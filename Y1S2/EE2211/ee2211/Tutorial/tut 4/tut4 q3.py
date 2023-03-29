import numpy as np

X = np.array([[1,2],[2,4],[1,-1]])
y = np.array([[0],[0.1],[1]])

inv_XTX = np.linalg.inv(X.transpose().dot(X))
print(f'inv_XTX is:')
print(inv_XTX)

det_inv_XTX = np.linalg.det(inv_XTX)
print(f'det_inv_XTX is:')
print(det_inv_XTX)

l_inv = inv_XTX.dot(X.transpose())
print(f'left_inverse is:')
print(l_inv)

w = l_inv.dot(y)
print(f'w is:')
print(w)