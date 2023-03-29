import numpy as np

X = np.array([[1,1],[3,4]])
y = np.array([[0],[1]])
#print(X)
#print(y)
Inv_X = np.linalg.inv(X)
det_X = np.linalg.det(X)

print('det is:')
print(det_X)

w = np.dot(Inv_X, y)

print('\n w is:')
print(w)