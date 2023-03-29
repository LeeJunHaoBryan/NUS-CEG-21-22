import numpy as np
from sklearn.preprocessing import PolynomialFeatures as skpf
import matplotlib.pyplot as plt

x = np.array([[-10], [-8], [-3], [-1], [2], [8]])
y = np.array([[5], [5], [4], [3], [2], [2]])
order = 3
polyfn =  skpf(order)
P = polyfn.fit_transform(x)

print('\nP is \n', P)

w = np.linalg.lstsq(P, y, rcond=None)[0]
print('\nw is\n', w)

xt = np.array([[9]])
testx = polyfn.fit_transform(xt)

ypredicted = testx.dot(w)

print('\npredicted y is\n', ypredicted)

plt.plot(x,y,'bo')
xline = np.arange(min(x), max(x),0.1)
yline= model(xline)
plt.plot(xline, yline)
plt.show()