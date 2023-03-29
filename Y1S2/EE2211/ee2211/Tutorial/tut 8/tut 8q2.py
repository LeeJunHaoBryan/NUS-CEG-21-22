import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv('/Users/bryanlee/Desktop/NUS/NUS Y2S1/ee2211/Tutorial/tut 8/government-expenditure-on-education.csv')
expenditure = df['total_expenditure_on_education'].to_numpy()
years = df['year'].to_numpy()

x = years/max(years)
y = expenditure/max(expenditure)
X = np.column_stack((np.ones((len(x))), x))

plt.figure(1)
plt.plot(years, expenditure, 'bo')
plt.xlabel('years')
plt.ylabel('expenditure')

plt.figure(2)
plt.plot(x, y, 'bo')
plt.xlabel('years normalized')
plt.ylabel('expenditure normalized')
plt.show()

num_iteration = 2000000

w = np.zeros(2)
learning_rate = 0.03

pred_y = np.exp(-X @ w)

cost = np.zeros(num_iteration)

for i in range (0, num_iteration):
    gradient = -2 * (pred_y - y) * pred_y @ X

    w = w - learning_rate * gradient

    current_cost = np.sum((pred_y - y) * (pred_y - y))
    cost[i] = current_cost

    if(i % 40000 == 0):
        print('Iter', i, 'cost =', current_cost)
        plt.figure(i)
        plt.plot(X[:, 1], y, 'bo')
        plt.plot(X[:, 1], pred_y, label = i)
        plt.legend()
plt.show()


