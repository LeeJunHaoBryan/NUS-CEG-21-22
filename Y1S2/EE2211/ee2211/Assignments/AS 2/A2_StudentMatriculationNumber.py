from turtle import shape
import numpy as np
from sklearn.datasets import load_iris
from numpy.linalg import inv 
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import OneHotEncoder
from sklearn.preprocessing import PolynomialFeatures as skpf


# Please replace "MatricNumber" with your actual matric number here and in the filename
def A2_A0233090R(N):
    """
    Input type
    :N type: int

    Return type
    :X_train type: numpy.ndarray of size (number_of_training_samples, 4)
    :y_train type: numpy.ndarray of size (number_of_training_samples,)
    :X_test type: numpy.ndarray of size (number_of_test_samples, 4)
    :y_test type: numpy.ndarray of size (number_of_test_samples,)
    :Ytr type: numpy.ndarray of size (number_of_training_samples, 3)
    :Yts type: numpy.ndarray of size (number_of_test_samples, 3)
    :Ptrain_list type: List[numpy.ndarray]
    :Ptest_list type: List[numpy.ndarray]
    :w_list type: List[numpy.ndarray]
    :error_train_array type: numpy.ndarray
    :error_test_array type: numpy.ndarray
    """
    # your code goes here
    

    iris_dataset = load_iris()
    X_train, X_test, y_train, y_test = train_test_split(iris_dataset['data'], iris_dataset['target'], test_size = 0.8, random_state = N)

    onehot_encoder = OneHotEncoder(sparse=False)
    reshaped = y_train.reshape(len(y_train), 1)
    Ytr = onehot_encoder.fit_transform(reshaped)

    reshaped = y_test.reshape(len(y_test), 1)
    Yts = onehot_encoder.fit_transform(reshaped)

    Ptrain_list = []
    Ptest_list = []
    w_list = []
    error_train_array = []
    error_test_array =[]
    

    for orders in range (1, 11):
        polyfn = skpf(orders)
        P = polyfn.fit_transform(X_train)
        Ptest = polyfn.fit_transform(X_test)
        reg_L = 0.0001*np.identity(P.shape[1])
        reg_L2 = 0.0001*np.identity(P.shape[0])

        Ptrain_list.append(P)
        Ptest_list.append(Ptest)

        if (P.shape[0] >= P.shape[1]) :
            w = np.linalg.inv(P.T @ P + reg_L) @ P.T @ Ytr
            #print('\n w is:\n', w)
        else :
            w = P.T @ np.linalg.inv(P @ P.T + reg_L2) @ Ytr
            #print('\n w is:\n', w)
        
        w_list.append(w)

        ytr_ain = P.dot(w)
        ytr_cls = [[1 if y == max(x) else 0 for y in x] for x in ytr_ain]
        n1 = np.matrix(Ytr)
        n2 = np.matrix(ytr_cls)
        difference = np.abs(n1 - n2)
        correct_tp = np.where(~difference.any(axis = 1))[0]
        incorrect = len(difference) - len(correct_tp)
        error_train_array.append(incorrect)
    

        yt_est = Ptest.dot(w)
        yt_cls = [[1 if y == max(x) else 0 for y in x] for x in yt_est]

        m1 = np.matrix(Yts)
        m2 = np.matrix(yt_cls)
        difference = np.abs(m1-m2)
        correct_p = np.where(~difference.any(axis = 1))[0]
        incorrect = len(difference) - len(correct_p)
        error_test_array.append(incorrect)
    print('\nerror_test_array is:\n', error_test_array)
    print('\nerror_train_array is:\n', error_train_array)


    # return in this order
    return X_train, y_train, X_test, y_test, Ytr, Yts, Ptrain_list, Ptest_list, w_list, error_train_array, error_test_array
A2_A0233090R(2)