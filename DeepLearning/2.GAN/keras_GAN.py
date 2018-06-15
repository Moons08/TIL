from keras import backend as K
from keras.datasets import mnist
from keras.layers import Input, Dense, Reshape, Flatten, Dropout
from keras.layers import BatchNormalization, Activation, ZeroPadding2D
from keras.layers.advanced_activations import LeakyReLU
from keras.layers.convolutional import UpSampling2D, Conv2D
from keras.models import Sequential, Model
from keras.optimizers import Adam

import numpy as np

generator_ = Sequential()
generator_.add(Dense(128 * 7 * 7, activation="relu", input_shape=(100,)))
generator_.add(Reshape((7, 7, 128)))
generator_.add(BatchNormalization(momentum=0.8))
generator_.add(UpSampling2D())
generator_.add(Conv2D(128, kernel_size=3, padding="same"))
generator_.add(Activation("relu"))
generator_.add(BatchNormalization(momentum=0.8))
generator_.add(UpSampling2D())
generator_.add(Conv2D(64, kernel_size=3, padding="same"))
generator_.add(Activation("relu"))
generator_.add(BatchNormalization(momentum=0.8))
generator_.add(Conv2D(1, kernel_size=3, padding="same"))
generator_.add(Activation("tanh"))

noise_input = Input(shape=(100,), name="noise_input")
generator = Model(noise_input, generator_(noise_input), name="generator")

optimizer = Adam(0.0002, 0.5)

generator.compile(loss='binary_crossentropy', optimizer=optimizer)

discriminator_ = Sequential()

discriminator_.add(Conv2D(32, kernel_size=3, strides=2, input_shape=(28, 28, 1), padding="same"))
discriminator_.add(LeakyReLU(alpha=0.2))
discriminator_.add(Dropout(0.25))
discriminator_.add(Conv2D(64, kernel_size=3, strides=2, padding="same"))
discriminator_.add(ZeroPadding2D(padding=((0,1),(0,1))))
discriminator_.add(LeakyReLU(alpha=0.2))
discriminator_.add(Dropout(0.25))
discriminator_.add(BatchNormalization(momentum=0.8))
discriminator_.add(Conv2D(128, kernel_size=3, strides=2, padding="same"))
discriminator_.add(LeakyReLU(alpha=0.2))
discriminator_.add(Dropout(0.25))
discriminator_.add(BatchNormalization(momentum=0.8))
discriminator_.add(Conv2D(256, kernel_size=3, strides=1, padding="same"))
discriminator_.add(LeakyReLU(alpha=0.2))
discriminator_.add(Dropout(0.25))
discriminator_.add(Flatten())
discriminator_.add(Dense(1, activation='sigmoid'))

image_input = Input(shape=(28, 28, 1), name="image_input")

discriminator = Model(image_input, discriminator_(image_input), name="discriminator")


discriminator.compile(loss='binary_crossentropy', optimizer=optimizer, metrics=['accuracy'])
discriminator_.summary()

noise_data = np.random.normal(0, 1, (32, 100))
generated_images = 0.5 * generator.predict(noise_data) + 0.5
generated_images.shape
