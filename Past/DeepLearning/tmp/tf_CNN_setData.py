import tensorflow as tf
import numpy as np
import os
from datetime import datetime

tf.app.flags.DEFINE_boolean("train", False, "학습모드")
FLAGS = tf.app.flags.FLAGS

def mnist_load():
    (train_x, train_y), (test_x, test_y) = tf.keras.datasets.mnist.load_data()
    train_x = train_x.reshape([train_x.shape[0], -1])
    train_x = train_x.astype('float32') / 255
    train_y = tf.keras.utils.to_categorical(train_y, num_classes=10)

    test_x = test_x.reshape([test_x.shape[0], -1])
    test_x = test_x.astype('float32') / 255
    test_y = tf.keras.utils.to_categorical(test_y, num_classes=10)

    return (train_x, train_y), (test_x, test_y)


class setData():
    def __init__(self, MINIBATCH_SIZE, data='mnist'):
        if data ='mnist':
            (train_x, train_y), (test_x, test_y) = mnist_load()

        buffer_size = train_x.shape[0] + test_x.shape[0]

        dataset = tf.data.Dataset.from_tensor_slices(({"image":train_x}, train_y))
        dataset = dataset.shuffle(buffer_size).repeat().batch(MINIBATCH_SIZE)

        self.num_examples = len(train_x)
        self.iterator = dataset.make_one_shot_iterator()
        self.next_batch = self.iterator.get_next()
        self.test_images, self.test_labels = test_x, test_y

class NN(object):
    def __init__(self):
        self.name = 'CNN'

    def __call__(self, X, keep_prob, reuse=False):
        with tf.variable_scope(self.name) as scope:
            if reuse:
                scope.reuse_variables()

            W1 = tf.Variable(tf.random_normal([3, 3, 1, 32], stddev=0.01))
            L1 = tf.nn.conv2d(X, W1, strides=[1, 1, 1, 1], padding='SAME')
            L1 = tf.nn.relu(L1)
            L1 = tf.nn.max_pool(L1, ksize=[1, 2, 2, 1], strides=[1, 2, 2, 1], padding='SAME')

            W2 = tf.Variable(tf.random_normal([3, 3, 32, 64], stddev=0.01))
            L2 = tf.nn.conv2d(L1, W2, strides=[1, 1, 1, 1], padding='SAME')
            L2 = tf.nn.relu(L2)
            L2 = tf.nn.max_pool(L2, ksize=[1, 2, 2, 1], strides=[1, 2, 2, 1], padding='SAME')

            W3 = tf.Variable(tf.random_normal([7 * 7 * 64, 256], stddev=0.01))
            L3 = tf.reshape(L2, [-1, 7 * 7 * 64])
            L3 = tf.matmul(L3, W3)
            L3 = tf.nn.relu(L3)
            L3 = tf.nn.dropout(L3, keep_prob)

            W4 = tf.Variable(tf.random_normal([256, 10], stddev=0.01))
            logits = tf.matmul(L3, W4)

            return logits

class Model():
    def __init__(self, NN):
        self.NN = NN

        self.X = tf.placeholder(tf.float32, shape=[None, 28, 28, 1], name="X")
        self.y = tf.placeholder(tf.int64, shape=[None, 10], name="y")
        self.keep_prob = tf.placeholder(tf.float32) # drop_out

        self.y_hat = self.NN(self.X, self.keep_prob)
        self.cost, self.train_op = self._build_op()

        # board
        now = datetime.utcnow().strftime("%Y/%m/%d_%H:%M")
        root_logdir = "tf_logs"
        if not os.path.exists(root_logdir):
            os.makedirs(root_logdir)
        logdir = "{}/run-{}/".format(root_logdir, now)

        self.cost_summary = tf.summary.scalar("xentropy", self.cost)
        self.file_writer = tf.summary.FileWriter(
            logdir, tf.get_default_graph())

        self.saver = tf.train.Saver()
        self.sess = tf.Session()

    def _build_op(self):
        cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits_v2(
            labels=self.y, logits=self.y_hat), name="cost")
        train_op = tf.train.AdamOptimizer(
            learning_rate=0.001).minimize(cost)

        return cost, train_op

    def train(self, data, n_epochs=15, batch_size=100):
        total_batch = data.num_examples // batch_size

        with self.sess as sess:
            sess.run(tf.global_variables_initializer())

            for epoch in range(n_epochs):
                for iteration in range(total_batch):
                    X_batch, y_batch= sess.run(data.next_batch)
                    _, cost_val = sess.run([self.train_op, self.cost],
                                            feed_dict={self.X: X_batch['image'].reshape(-1, 28, 28, 1),
                                                       self.y: y_batch,
                                                       self.keep_prob: 0.8})

                    if iteration % 100 == 0:
                        summary_str = self.cost_summary.eval(
                                                feed_dict={self.X: X_batch['image'].reshape(-1, 28, 28, 1),
                                                           self.y: y_batch,
                                                           self.keep_prob: 0.8})
                        step = epoch * n_epochs + iteration
                        self.file_writer.add_summary(summary_str, step)

                print('Epoch:', '%04d' % (epoch + 1),
                      'cost =', '{:.3f}'.format(cost_val))


                save_path = self.saver.save(sess, "./cnn_class.ckpt")

            return self

def predict():
    model = Model(NN())
    mnist = setData(100)

    is_correct = tf.equal(tf.argmax(model.y_hat, 1), tf.argmax(model.y, 1))
    accuracy = tf.reduce_mean(tf.cast(is_correct, tf.float32))
    saver = tf.train.Saver()

    with tf.Session() as sess:

        saver.restore(sess, "./cnn_class.ckpt")
        acc = sess.run( accuracy,
                        feed_dict={model.X: mnist.test_images.reshape(-1, 28, 28, 1),
                                    model.y: mnist.test_labels,
                                    model.keep_prob: 1})
        print(acc)

def main(_):
    if FLAGS.train:
        mnist = setData(100)
        model = Model(NN())
        model.train(mnist)
    else:
        predict()

if __name__ == "__main__":
    tf.app.run()
