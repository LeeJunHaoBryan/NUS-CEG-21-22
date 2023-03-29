import numpy as np
from numpy.linalg import inv
from sklearn.preprocessing import PolynomialFeatures as skpf

##Linear regression for classification

x_data = [[1, 2, 3], [4, 0, 6], [1, 1, 0], [0, 1, 2], [5, 7, -2], [-1, 4, 0]]
y_data = [[1, 0 , 0], [1, 0, 0], [0, 1, 0], [0, 0, 1], [0, 1, 0], [0, 0 , 1]]

x = np.array(x_data)
y = np.array(y_data)

bias = np.ones((len(x_data), 1))
x = np.hstack((bias, x))

w = np.linalg.lstsq(x, y, rcond = None) [0]
print('\n w is \n', w)

x_test = np.array([[1, 1, -2, 3]])
y_predict = x_test @ w
print('\n y predict is: \n', y_predict)
y_class_predict = [[1 if y == max(x) else 0 for y in x] for x in y_predict]
print('\b y_class_predict is: \n', y_class_predict)

##Polynomial regression for classification

order = 5
polyfn = skpf(order)
P = polyfn.fit_transform(x_data)

wP = P.T @ inv(P @ P.T) @ y
print('\n wP is: \n', wP)

P_test = np.array([[1, -2, 3]])
Pt = polyfn.fit_transform(P_test)
yp_predict = Pt @ wP
print('\n yp_predict is: \n', yp_predict)
yp_class_predict = [[1 if y == max(x) else 0 for y in x] for x in yp_predict]
print('\n yp_class_predict is: \n', yp_class_predict)