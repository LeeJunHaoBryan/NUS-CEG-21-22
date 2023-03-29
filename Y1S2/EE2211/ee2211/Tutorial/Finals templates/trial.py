from audioop import bias
import numpy as np
from sklearn.metrics import mean_squared_error

xdata = [[50, 10],[40,7],[65,12],[70,5],[75,4]]
ydata = [[9], [6], [5],[3], [2]]

X = np.array(xdata)
y = np.array(ydata)

bias = np.ones((len(X), 1))
X = np.hstack((bias, X))
#print(X)

w = np.linalg.lstsq(X, y, rcond = None)[0]

print(w)

xt = [[1, 62, 8]]

#xt = [[1, -1]]
x_test = np.array(xt)
y_train = x_test.dot(w)
print(y_train)