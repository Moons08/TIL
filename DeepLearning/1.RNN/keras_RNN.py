from keras.preprocessing import sequence
from keras.datasets import imdb
from keras import layers, models


class Data:
    def __init__(self, max_features=20000, maxlen=80):
                      # max_features : 최대 단어 빈도, maxlen : 최대 길이
        (x_train, y_train), (x_test, y_test) = imdb.load_data(
            num_words=max_features)
        x_train = sequence.pad_sequences(x_train, maxlen=maxlen)
        x_test = sequence.pad_sequences(x_test, maxlen=maxlen)
        # max_len 보다 긴 단어들을 pad_sequences() 함수로 잘라냄, 부족하면 0으로 채움
        self.x_train, self.y_train = x_train, y_train
        self.x_test, self.y_test = x_test, y_test


class RNN_LSTM(models.Sequential):  # 연쇄방식
    def __init__(self, max_features, maxlen):
        super().__init__()
        self.add(layers.Embedding(max_features, 128, input_length=maxlen))
        self.add(layers.LSTM(128, dropout=0.2, recurrent_dropout=0.2))
        self.add(layers.Dense(1, activation='sigmoid'))
        self.compile(loss='binary_crossentropy',
                     optimizer='adam', metrics=['accuracy'])


class RNN_LSTM_distributed(models.Model):  # 분산 방식
    def __init__(self, max_features, maxlen):
        x = layers.Input((maxlen,))
        h = layers.Embedding(max_features, 128)(x)
        h = layers.LSTM(128, dropout=0.2, recurrent_dropout=0.2)(h)
        y = layers.Dense(1, activation='sigmoid')(h)
        super().__init__(x, y)

        # try using different optimizers and different optimizer configs
        self.compile(loss='binary_crossentropy',
                     optimizer='adam', metrics=['accuracy'])


class Machine:
    def __init__(self,
                 max_features=20000,
                 maxlen=80):
        self.data = Data(max_features, maxlen)
        self.model = RNN_LSTM(max_features, maxlen)

    def run(self, epochs=3, batch_size=32):
        data = self.data
        model = self.model
        print('Training stage')
        print('==============')
        hist = model.fit(data.x_train, data.y_train,
                         batch_size=batch_size,
                         epochs=epochs,
                         validation_data=(data.x_test, data.y_test))

        score, acc = model.evaluate(data.x_test, data.y_test,
                                    batch_size=batch_size)
        print('Test performance: accuracy={0}, loss={1}'.format(acc, score))

        plt.figure(figsize=(15, 5))
        plt.subplot(121)
        plot_loss(hist)
        plt.subplot(122)
        plot_acc(hist)
        plt.show()


if __name__ == "__main__":
    m = Machine()
    m.run()
