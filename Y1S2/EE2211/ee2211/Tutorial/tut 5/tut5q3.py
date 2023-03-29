import numpy as np
import matplotlib.pyplot as plt

xdata = [[36], [28], [35], [39], [30], [30], [31], [38], [36], [38], [29], [26]]
ydata = [[31], [29], [34], [35], [29], [30], [30], [38], [34], [33], [29], [26]]

X = np.array(xdata)
Y = np.array(ydata)

bias = np.ones((len(xdata), 1))
X = np.hstack((bias, X))
print('X is:')
print(X)

w = np.linalg.lstsq(X,Y, rcond = None)[0]
print(' ')
print('w is:')
print(w)

xt = [[1, 30]]
xt_est = np.array(xt)
y_train = xt_est.dot(w)
print(' ')
print('y_train is:')
print(y_train)

xt2 = [[1, 5]]
x_test2 = np.array(xt2)
y_train2 = x_test2.dot(w)
print(' ')
print('y_train2 is:')
print(y_train2)

yline = np.dot(X,w)
plt.plot(xdata,ydata,'bo')
plt.plot(xdata,yline,'r')
plt.xlabel('Students')
plt.ylabel('Books')
plt.grid()
plt.show()

