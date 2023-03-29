from numpy.linalg import matrix_rank
import numpy as np

x = [[1, 2, 3], [4, 5, 6] , [7, 8, 9]]

X = np.array(x)

rank = matrix_rank(x)

print(rank)