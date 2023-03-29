import numpy as np
import matplotlib.pyplot as plt

xdata = [[36], [26], [35], [39], [26], [30], [31], [38], [36], [38], [26], [26]]
ydata = [[31], [20], [34], [35], [20], [30], [30], [38], [34], [33], [20], [20]]

X = np.array(xdata)
Y = np.array(ydata)

bias = np.ones((len(xdata), 1))
X = np.hstack((bias,X))
print(X)

w = np.linalg.lstsq(X,Y, rcond = None)[0]
print(' ')
print('w is:')
print(w)

#part(b)
xt = [[1, 30]]
xt_est = np.array(xt)
y_train = xt_est.dot(w)
print(' ')
print('y_train is:')
print(y_train)

#part(C)
x2data = [[36], [26], [35], [39], [30], [31], [38], [36], [38]]
y2data = [[31], [20], [34], [35], [30], [30], [38], [34], [33]]

A = np.array(x2data)
Y2 = np.array(y2data)
bias2 = np.ones((len(x2data), 1))
A = np.hstack((bias2,A))
w2 = np.linalg.lstsq(A,Y2, rcond = None)[0]
print(' ')
print('w2 is:')
print(w2)
y_train2 = xt_est.dot(w2)
print(' ')
print('y_train2 is:')
print(y_train2)

#part(a) graph
yline = np.dot(X,w)
plt.plot(xdata,ydata,'bo')
plt.plot(xdata,yline,'r')
plt.xlabel('students')
plt.ylabel('books')
plt.grid()
plt.show()

#part(c) graph
yline2 = np.dot(A, w2)
plt.plot(x2data,y2data,'bo')
plt.plot(x2data,yline2,'r')
plt.xlabel('students')
plt.ylabel('books')
plt.grid()
plt.show()