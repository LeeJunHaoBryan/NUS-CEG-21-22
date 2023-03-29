import numpy as np
from sklearn.metrics import mean_squared_error

x_data = [[50,10], [40, 7], [65, 12], [70, 5], [75, 4]]
y_data = [[9], [6], [5], [3], [2]]

x = np.array(x_data)
y = np.array(y_data)

bias = np.ones((len(x_data), 1))
x = np.hstack((bias, x))

w = np.linalg.lstsq(x, y, rcond = None)[0]

y_pred = x @ w

MSE = mean_squared_error(y, y_pred)
print(MSE)

x_test_data = [[1, 62, 8]]
x_test = np.array(x_test_data)

y_test = x_test @ w
print('\n y_test is: \n', y_test)