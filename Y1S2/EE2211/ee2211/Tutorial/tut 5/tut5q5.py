import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Extract year and expenditure data from csv file
df = pd.read_csv("Tutorial/tut 5/government-expenditure-on-education.csv")
expenditureList = df ['total_expenditure_on_education'].tolist()
yearList = df ['year'].tolist()

#Creating the numpy arrays

#Adding a column of ones to the year data (x data).
#You can also use np.ones() and hstack to do the following.
m_list = [[1]*len(yearList), yearList]

print(m_list)
print(np.array(m_list).shape)

#Transpose required, else a row vector is created instead of a column vector
X = np.array(m_list).T

print(X)

y = np.array(expenditureList)

w = np.linalg.inv(X.T @ X) @ X.T @ y
print(w)

#Creating the y-data points for the regression line
y_line = X.dot(w)

#Plotting Scatter Plot for data and Linear Regression Line
plt.plot(yearList, expenditureList, 'o', label = 'Expenditure over the years')
plt.plot(yearList, y_line)
plt.xlabel('Year')
plt.ylabel('Expenditure')
plt.title('Education Expenditure')
plt.show()

#Calculating the prediction for 2021
y_predict = np.array([1, 2021]).dot(w)
print(y_predict)