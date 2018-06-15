from keras.models import Sequential
from keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout
from keras.optimizers import adam
from keras.utils import np_utils
from keras import regularizers

from sklearn.model_selection import train_test_split
from sklearn.datasets import fetch_olivetti_faces

import matplotlib.pyplot as plt
import numpy as np

from util import plot_acc, plot_loss

class Data:
    def __init__(self):
        olivetti = fetch_olivetti_faces()
        X = olivetti.data
        y = olivetti.target

        X = X.reshape(400, 64, 64)
        X_train0, X_test0 = train_test_split(X, test_size = .2, random_state=0)
        y_train0, y_test0= train_test_split(y, test_size = .2, random_state=0)

        X_train = X_train0[:, :,  :, np.newaxis].astype('float32') / 255.0
        X_test = X_test0[:, :, :, np.newaxis].astype('float32') / 255.0

        Y_train = np_utils.to_categorical(y_train0, 40)
        Y_test = np_utils.to_categorical(y_test0, 40)

        self.x_train, self.y_train = X_train, Y_train
        self.x_test, self.y_test = X_test, Y_test

class CNN(Sequential):
  def __init__(self):
    super().__init__() # Sequential init  상속
    self.add(Conv2D(5, (5, 5), activation='relu', input_shape=(64, 64, 1), padding='same',kernel_initializer="glorot_uniform"))
    self.add(Conv2D(8, (5, 5), activation='relu', padding='same',kernel_initializer="glorot_uniform"))
    self.add(MaxPooling2D()) # 사이즈 줄임
    self.add(Dropout(0.1))
    self.add(Flatten()) # 벡터로
    self.add(Dense(40, activation='softmax', kernel_initializer="glorot_uniform")) # softmax 대신 sigmoid같은것도 가능
    self.compile(loss='categorical_crossentropy', metrics=['accuracy'], optimizer=adam())


class Machine:
    def __init__(self):
        self.data = Data()
        self.model = CNN()

    def run(self, epoch=10, batch_size=150):
        data = self.data
        model = self.model
        print('Training...')
        print('===========')
        hist = model.fit(data.x_train, data.y_train,
                epochs=epoch, batch_size=batch_size,
                validation_data=(data.x_test, data.y_test), verbose=0)

        score, acc = model.evaluate(data.x_test, data.y_test,
                                    batch_size=batch_size)
        print('Test performance: %s (%.2f%%)' % (score, acc * 100))

        plt.figure(figsize=(15,5))
        plt.subplot(121)
        plot_loss(hist)
        plt.subplot(122)
        plot_acc(hist)
        plt.show()

if __name__ == "__main__":
    m = Machine()
    m.run()
