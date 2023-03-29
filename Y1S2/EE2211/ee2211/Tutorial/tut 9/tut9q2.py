import numpy as np
import numpy.matlib
import matplotlib.pyplot as plt

from sklearn.metrics import mean_squared_error as skmse

x = np.array([[0.1, 0.7, 1.6, 2.2, 3.6, 4.1, 4.4, 5.2, 6.2, 7.3 ]]).T
y = np.array([[1.9, 1.5, 5.4, 6.1, 8.9, 9.5, 9.6, 12.9, 13.6, 15.7]]).T

##linex = np.array([5, 5, 5, 5, 5, 5])
##liney = np.array([0, 1, 2, 3, 4, 5])

#plt.plot(x, y, 'bx')
#plt.grid()
#plt.show()

yave = np.mean(y)
print('mean of all y values is', yave)

mseroot = skmse(numpy.matlib.repmat(yave,10,1), y)
print('MSE at root is:', mseroot)

yave = sum(y*(x>4))/5
print('mean of y valuse at depth 1 for x>5 is:', yave)

mse = sum((y - yave) * (y-yave) * (x>4))/5
print('MSE at depth 1 is:', mse)