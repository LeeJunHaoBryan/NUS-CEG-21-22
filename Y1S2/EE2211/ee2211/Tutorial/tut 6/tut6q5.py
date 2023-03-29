import numpy as np
from sklearn.preprocessing import PolynomialFeatures as skpf
from numpy.linalg import inv
from sklearn.preprocessing import OneHotEncoder

x_data = [[-1], [0], [0.5], [0.3], [0.8]]
y_data = [[1, 0 , 0], [1, 0, 0], [0, 1, 0], [0, 0, 1], [0, 1, 0]]

x = np.array(x_data)
y = np.array(y_data)

bias = np.ones((len(x_data), 1))
X = np.hstack((bias, x))

print('\nX is \n', X)

w = np.linalg.lstsq(X, y, rcond = None)[0]
print('\nw is\n', w)

x_test = np.array([[1, -.1], [1, 0.4]])
y_predict = x_test @ w

print('\ny_predict is\n', y_predict)

#The following two pieces of codes both returns argmax, but in different formats. 
#Option 1 returns the output directly in one-hot encoding

#Creates an array which returns argmax
y_class_predict = [[1 if y == max(x) else 0 for y in x] for x in y_predict ]
print('y_class_predict is : \n', y_class_predict)

#Option 2 returns the output not in one-hot encoding
#Alternative code below returns the argmax values per row
y_class_predict1 = np.argmax(y_predict,axis=1)
print('y_class_predict1 is : \n', y_class_predict1)

x_data2 = [[-1], [0], [0.5], [0.3], [0.8]]
x_2 = np.array(x_data2)

bias = np.ones((len(x_data2), 1))
X2 = np.hstack((bias, x_2))


order = 5
polyfn = skpf(order)
P = polyfn.fit_transform(x_2)

print('\nP is \n', P)

wp = P.T @ inv(P @ P.T) @ y
print('\nwP is \n', wp)

xtest = np.array([[-.1], [.4]])

Ptest = polyfn.fit_transform(xtest)
y_predict2 = Ptest @ wp
print('y_predict2 is : \n', y_predict2)

y_class_predict2 = np.argmax(y_predict2,axis=1)
print('y_class_predict2 is : \n', y_class_predict2)

enc=OneHotEncoder(categories=[[0,1,2]],sparse=False)
tmp = y_class_predict2.reshape(len(y_class_predict2),1)
enc.fit_transform(tmp)

print(tmp)
