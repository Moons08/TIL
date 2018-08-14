import tensorflow as tf
import tensorflow.layers as tl
import tensorflow.contrib.layers as tcl
from tensorflow.examples.tutorials.mnist import input_data

import numpy as np
import os
from datetime import datetime


class NN(object):
    def __init__(self):
        self.name = 'NN'

    def __call__(self, X, reuse=False):
        with tf.variable_scope(self.name) as scope:
            if reuse:
                scope.reuse_variables()

            hidden = tcl.fully_connected(
                X, 300, activation_fn=tf.nn.elu, normalizer_fn=tcl.batch_norm)
            hidden2 = tcl.fully_connected(
                hidden, 100, activation_fn=tf.nn.elu, normalizer_fn=tcl.batch_norm)
            logit = tcl.fully_connected(
                hidden2, 10, activation_fn=None, normalizer_fn=tcl.batch_norm)

            return logit


class model():
    def __init__(self, NN, data):
        self.NN = NN
        self.data = data

        self.X = tf.placeholder(tf.float32, shape=(None, 28 * 28), name="X")
        self.y = tf.placeholder(tf.int64, shape=(None), name="y")

        self.y_hat = self.NN(self.X)

        self.loss = tf.reduce_mean(tf.nn.sparse_softmax_cross_entropy_with_logits(
            labels=self.y, logits=self.y_hat), name="loss")
        self.optimizer = tf.train.GradientDescentOptimizer(
            learning_rate=0.01).minimize(self.loss)
        self.accuracy = tf.reduce_mean(
            tf.cast(tf.nn.in_top_k(self.y_hat, self.y, 1), tf.float32))

        # board
        now = datetime.utcnow().strftime("%Y%m%d-%H%M%S")
        root_logdir = "tf_logs"
        if not os.path.exists(root_logdir):
            os.makedirs(root_logdir)
        logdir = "{}/run-{}/".format(root_logdir, now)

        self.loss_summary = tf.summary.scalar("xentropy", self.loss)
        self.file_writer = tf.summary.FileWriter(
            logdir, tf.get_default_graph())

        self.sess = tf.Session()
        self.saver = tf.train.Saver()

    def train(self, n_epochs=2, batch_size=50):
        extra_update_ops = tf.get_collection(tf.GraphKeys.UPDATE_OPS)

        with self.sess as sess:
            sess.run(tf.global_variables_initializer())

            for epoch in range(n_epochs):
                for iteration in range(self.data.train.num_examples // batch_size):
                    X_batch, y_batch = self.data.train.next_batch(batch_size)
                    if iteration % 20 == 0:
                        summary_str = self.loss_summary.eval(
                            feed_dict={self.X: X_batch, self.y: y_batch})
                        step = epoch * n_epochs + iteration
                        self.file_writer.add_summary(summary_str, step)

                    sess.run([self.optimizer, extra_update_ops],
                             feed_dict={self.X: X_batch, self.y: y_batch})

                accuracy_val = self.accuracy.eval(feed_dict={self.X: self.data.validation.images,
                                                             self.y: self.data.validation.labels})

                print(epoch, "Validation acc:", accuracy_val)

                save_path = self.saver.save(sess, "./with_class.ckpt")

            return self

    def predict(self):
        with tf.Session() as sess:
            self.saver.restore(sess, "./with_class.ckpt")

            accuracy_val, y_hat = sess.run([self.accuracy, self.y_hat],
                                           feed_dict={self.X: mnist.test.images,
                                                      self.y: mnist.test.labels})
            print("test acc:", accuracy_val)

            return np.argmax(y_hat, axis=1)

    def predict_proba(self):
        with tf.Session() as sess:
            self.saver.restore(sess, "./with_class.ckpt")

            accuracy_val, y_hat = sess.run([self.accuracy, self.y_hat],
                                           feed_dict={self.X: mnist.test.images,
                                                      self.y: mnist.test.labels})
            print("test acc:", accuracy_val)

            return y_hat




if __name__ == "__main__":
    mnist = input_data.read_data_sets("/tmp/data/")
    mymodel = model(NN(), mnist)
    # mymodel.train()
    mymodel.predict()

    # main()
