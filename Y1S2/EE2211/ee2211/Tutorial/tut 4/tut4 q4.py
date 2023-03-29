import numpy as np
from numpy.linalg import inv

X = np.array([[1, 0,1,0], [1,-1,1,-1], [1, 1,0,0]])
y = np.array([[1],[0],[1]])

det = np.linalg.det(X.dot(X.transpose()))

inv_XTX = np.linalg.inv(X.dot(X.transpose()))

pinv = X.transpose().dot(inv_XTX)

w=pinv.dot(y)

print(w)