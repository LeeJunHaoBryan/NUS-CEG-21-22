from json import load
from sklearn.datasets import load_iris
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import accuracy_score as AS
from sklearn.model_selection import train_test_split as tts
from sklearn.tree import DecisionTreeClassifier as dtc
from sklearn.tree import plot_tree

iris_dataset = load_iris()

X_train, X_test, y_train, y_test = tts(iris_dataset['data'], iris_dataset['target'], test_size= 0.8, random_state= 0)

tree = dtc(criterion='entropy', max_depth = 4)
tree.fit(X_train, y_train)
y_pred_train = tree.predict(X_train)
y_pred_test = tree.predict(X_test)

score_train = AS(y_train, y_pred_train)
score_test = AS(y_test, y_pred_test)
print('training accuracy score:\n', score_train )
print('testing accuracy score:\n', score_test)

plot_tree(tree)
plt.show()

