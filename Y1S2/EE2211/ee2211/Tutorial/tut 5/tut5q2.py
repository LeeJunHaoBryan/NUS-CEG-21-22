import numpy as np
import matplotlib.pyplot as plt

#part (a)
x_data = [[1, 0 ,1], [2, -1, 1], [1, 1, 5]]
y_data = [[1], [2], [3]]

X = np.array(x_data)
Y = np.array(y_data)

w = np.linalg.lstsq(X,Y,rcond = None)[0]
print('w is:')
print(w)

xt = [[-1, 2, 8], [1, 5, -1]]
xt_est = np.array(xt)
yt_rain = xt_est.dot(w)
print(' ')
print('y_train is:')
print(yt_rain)

#part(b)
bias = np.ones((len(x_data), 1))
A = np.hstack((bias, X))

E = np.linalg.lstsq(A,Y,rcond = None)[0]
print(' ')
print('E is:')
print(E)

At = [[1, -1, 2, 8], [1, 1, 5, -1]]
At_est = np.array(At)
Y_train = At_est.dot(E)
print(' ')
print('Y_train is:')
print(Y_train)