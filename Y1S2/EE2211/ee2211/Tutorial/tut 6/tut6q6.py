from sklearn.datasets import load_iris
import numpy as np
from numpy.linalg import inv 
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder
from sklearn.preprocessing import PolynomialFeatures as skpf

iris_dataset = load_iris()

X_train, X_test, y_train, y_test = train_test_split(iris_dataset['data'], iris_dataset['target'], test_size = 0.26, random_state = 0) 
print('\ny_train.shape is\n', y_train.shape)
print('\ny_test.shape is\n', y_test.shape)
print('\n y_test is\n', y_test)

onehot_encoder = OneHotEncoder(sparse=False)
reshaped = y_train.reshape(len(y_train),1)
Ytr_onehot = onehot_encoder.fit_transform(reshaped)

print('\nytr_onehot is:\n', Ytr_onehot)

reshaped = y_test.reshape(len(y_test), 1)
Yts_onehot = onehot_encoder.fit_transform(reshaped)
print('Yts_onehot is : \n', Yts_onehot)

w = np.linalg.lstsq(X_train, Ytr_onehot, rcond = None) [0]
print('\n w is: \n', w)

yt_est = X_test.dot(w)
yt_cls = [[1 if y == max(x) else 0 for y in x] for x in yt_est ]
print(yt_cls)

m1 = np.matrix(Yts_onehot)
m2 = np.matrix(yt_cls)
difference = np.abs(m1 - m2)

correct = np.where(~difference.any(axis = 1))[0]
accuracy = len(correct)/len(difference)

print('\n len(correct) is: \n', len(correct))
print('\n len(diff) is: \n', len(difference))
print('\n accuracy is\n', accuracy)

order = 2
polyfn = skpf(order)
P = polyfn.fit_transform(X_train)
pt = polyfn.fit_transform(X_test)

if P.shape[0] > P.shape[1]:
    wp = inv(P.T @ P) @ P.T @ Ytr_onehot
    #wp = np.linalg.lstsq(P, Ytr_onehot, rcond = None) [0]
    print(wp)
else :
    wp = P.T @ inv(P @ P.T) @ Ytr_onehot
    #wp = np.linalg.lstsq(P, Ytr_onehot, rcond = None) [0]
    print(wp)

yt_est_p = pt.dot(wp)
yt_cls_p = [[1 if y == max(x) else 0  for y in x] for x in yt_est_p]

m1 = np.matrix(Yts_onehot)
m2 = np.matrix(yt_cls_p)
difference = np.abs(m1 - m2)

correct_p = np.where(~difference.any(axis = 1))[0]
accuracy = len(correct_p)/len(difference)
print('\n len(correct) is: \n', len(correct))
print('\n accuracy is\n', accuracy)

