import numpy as np
from sklearn.metrics import mean_squared_error as skmse
from sklearn.preprocessing import PolynomialFeatures as skpf
import matplotlib.pyplot as plt

trainingmse = []
testmse = []
reglambda = 1

x_train = np.array([[-10], [-8], [-3], [-1], [2], [7]])
y_train = np.array([[4.18], [2.42], [0.22], [0.12], [0.25], [3.09]])

x_test = np.array([[-9], [-7], [-5], [-4], [-2], [1], [4], [5], [6], [9]])
y_test = np.array([[3], [1.81], [0.80], [0.25], [-.19], [.4], [1.24], [1.68], [2.32], [5.05]])

for order in range (1, 7) :
    polyfn = skpf(order)
    P = polyfn.fit_transform(x_train)

    w = np.linalg.inv(P.T @ P + np.identity(len(P.T))) @ P.T @ y_train
    Ptest = polyfn.fit_transform(x_test)

    y_reg = P @ w
    y_test_reg = Ptest @ w

    trainingmse.append(skmse(y_train, y_reg))
    testmse.append(skmse(y_test, y_test_reg))

    plt.figure(3)
    plt.title('Regularization')

    plt.plot(x_train, y_train, 'bo')
    plt.plot(x_test, y_test, 'rx')

    xline = np.arange(min(np.concatenate((x_train,x_test))), max(np.concatenate((x_train,x_test))), 0.1)
    xline_reshaped = xline.reshape((len(xline), 1))
    Pline = polyfn.fit_transform(xline_reshaped)
    yline = Pline @ w
    plt.plot(xline, yline, '--', label=order)
    plt.legend()

plt.grid()
print ("With Regularization :::")
print ("Training MSE", trainingmse)
print ("Test MSE", testmse)

plt.figure(4)
plt.title('Regularization MSE')
plt.plot(np.arange(1,7),trainingmse,label="Training MSE")
plt.plot(np.arange(1,7),testmse,label="Test MSE")
plt.legend()
plt.show()

