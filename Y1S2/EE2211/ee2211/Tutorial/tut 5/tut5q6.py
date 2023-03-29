import pandas as pd
import numpy as np
from numpy.linalg import inv
from sklearn.metrics import mean_squared_error

wine = pd.read_csv("https://archive.ics.uci.edu/ml/machine-learning-databases/wine-quality/winequality-red.csv",sep=';')
wine.info()
y = wine.quality
x = wine.drop('quality',axis = 1)

bias = np.ones((len(x), 1))
X = np.hstack((bias, x))
#print(X)

train_X = X[0:1500]
train_Y = y[0:1500]
Xt_est = X[1500:1599]
Yt_est = y[1500:1599]

w = np.linalg.lstsq(train_X,train_Y, rcond = None)[0]
print(w)
print(' ')

test_y = Xt_est.dot(w)

MSE = mean_squared_error(Yt_est,test_y)
print(MSE)