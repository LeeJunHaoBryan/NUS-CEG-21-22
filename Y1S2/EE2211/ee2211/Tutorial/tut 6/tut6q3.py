import numpy as np
from sklearn.preprocessing import PolynomialFeatures as skpf
from numpy.linalg import inv

X = np.array([[1, 0, 1], [1, -1, 1]])
order = 3
polyfn = skpf(order)

P = polyfn.fit_transform(X)

print('\nP is \n', P)

y = np.array([[0],[1]])

w = np.linalg.lstsq(P, y, rcond = None)[0]
print('\nw is\n', w)

## primal ridge
reg_L = 0.0001*np.identity(P.shape[1]) 
w_primal_ridge = inv(P.T @ P + reg_L) @ P.T @ y 
print(w_primal_ridge)