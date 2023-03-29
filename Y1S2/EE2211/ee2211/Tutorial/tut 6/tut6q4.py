import numpy as np


x_data = [[-1], [0], [0.5], [0.3], [0.8]]
y_data = [[1], [1], [-1], [1], [-1]]

x = np.array(x_data)
y = np.array(y_data)

bias = np.ones((len(x_data), 1))
X = np.hstack((bias, x))

w = np.linalg.lstsq(X, y, rcond = None)[0]
print('\nw is\n', w)

xt = [[-0.1], [0.4]]
x_test = np.array(xt)
bias = np.ones((len(x_test), 1))
X_test = np.hstack((bias, x_test))
print('Xtest is : \n', X_test)

y_predict = X_test @ w
y_predict_class = np.sign(y_predict)

print('Raw predicted y values are :\n', y_predict)
print('Therefore predicted y output class is :\n', y_predict_class)
