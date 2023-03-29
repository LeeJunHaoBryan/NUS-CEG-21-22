import numpy as np
import matplotlib.pyplot as plt

x_data = [[-10], [-8], [-3], [-1], [2], [8]]
y_data = [[5], [5], [4], [3], [2], [2]]

x = np.array(x_data)
Y = np.array(y_data)

bias = np.ones((len(x_data), 1))
X = np.hstack((bias, x))

print(X)

inv_XTX = np.linalg.inv(X.transpose().dot(X))
print(' ')
print('inv_XTX is:')
print(inv_XTX)
pinv = inv_XTX.dot(X.transpose())
print(' ')
print('pinv is:')
print(pinv)
print(' ')

w = pinv.dot(Y)
print('w is:')
print(w)

c = np.linalg.lstsq(X, Y, rcond = None)[0]
print(' ')
print('C is:')
print(c)

#part B starts here
inv_ATA = np.linalg.inv(x.transpose().dot(x))
print(' ')
print('inv_ATA is:')
print(inv_ATA)
Ainv = inv_ATA.dot(x.transpose())
print(' ')
print(Ainv)
E = Ainv.dot(Y)
print(' ')
print(E)
#part B ends here

#plotting for part(A)
yline = np.dot(X, w)

plt.plot(x_data,y_data,'bo')

plt.plot(x_data,yline,'r')
plt.xlabel('x')
plt.ylabel('y')
plt.grid()
plt.show()
#plotting for part(B)
Yline = np.dot(x,E)

plt.plot(x_data,y_data, 'bo')
plt.plot(x_data,Yline,'r')
plt.xlabel('x')
plt.ylabel('y')
plt.grid()
plt.show()