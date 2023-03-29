import numpy as np

X = np.array([[1,2],[3,6]])
y = np.array([[0],[1]])

det_X = np.linalg.det(X)
print(det_X)
