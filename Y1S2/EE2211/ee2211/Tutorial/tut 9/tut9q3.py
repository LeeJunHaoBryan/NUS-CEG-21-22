from cProfile import label
from sklearn import datasets
import numpy as np
import matplotlib.pyplot as plt

boston = datasets.load_boston()
print(boston.DESCR)
print(boston.feature_names)

xtrain = boston.data[:, 12]
xtrain = xtrain.reshape((len(xtrain), 1))
ytrain = boston.target
ytrain = ytrain.reshape((len(ytrain), 1))

from sklearn.tree import DecisionTreeRegressor as dtr

tree = dtr(criterion='mse', max_depth= 2)
tree.fit(xtrain, ytrain)

y_pred = tree.predict(xtrain)

plt.figure(1)
plt.plot(xtrain, ytrain, 'bo')
plt.plot(xtrain, y_pred, 'r.', label='scikit-learnn')
plt.grid()
plt.show()

##-- GROWING YOUR OWN TREE --##
xtrain = boston.data[:,12]

#sorting data according to x values
#argsort is a numpy function that returns the indices that would sort this array xtrain
xtrain = boston.data[:,12]
sorted_index = xtrain.argsort()
xtrain = xtrain[sorted_index]
print(xtrain)

#Remember to sort y accordingly too
ytrain=boston.target
ytrain = ytrain[sorted_index]


# This function finds the best threshold in given dataset y according to minimum sum of squared errors
def find_best_split(y):
    
    # index represents last element in the below threshold node
    sq_err_vec = np.zeros(len(y)-1)    
    for index in range(0, len(y)-1):
        
        # split the data
        data_below_threshold = y[:index+1]  # ==> from 0 to index+1
        data_above_threshold = y[index+1:]  # ==> index+1 to the end of array
        
        # Compute estimate
        mean_below_threshold = np.mean(data_below_threshold)
        mean_above_threshold = np.mean(data_above_threshold)
        
        # Compute total square error
        # Note that MSE = total square error divided by number of data points
        below_sq_err = np.sum(np.square(data_below_threshold - mean_below_threshold))
        above_sq_err = np.sum(np.square(data_above_threshold - mean_above_threshold))
        sq_err_vec[index] = below_sq_err + above_sq_err
    
    #np.argmin returns the index of the minimum value in this array
    best_index = np.argmin(sq_err_vec)
    
    yL = y[:best_index+1]   #y values in node A / left side
    yR = y[best_index+1:]   #y values in node B  / right side

    return yL, yR




#Splitting data at first level (depth = 1 )
yA, yB = find_best_split(ytrain)

#Splitting data at second level (depth = 2)
yA1, yA2 = find_best_split(yA)
yB1, yB2 = find_best_split(yB)

#Calculating the regression tree y values (average of y values in this node)
yA1_pred = np.mean(yA1)
yA2_pred = np.mean(yA2)
yB1_pred = np.mean(yB1)
yB2_pred = np.mean(yB2)

#generating the y values for plotting
y_pred_plotting = np.concatenate([yA1_pred*np.ones(len(yA1)),yA2_pred*np.ones(len(yA2)),yB1_pred*np.ones(len(yB1)),yB2_pred*np.ones(len(yB2))])

plt.plot(xtrain,y_pred_plotting,'g', linestyle='dashed',label="own tree")
plt.legend()
plt.grid()
plt.show()