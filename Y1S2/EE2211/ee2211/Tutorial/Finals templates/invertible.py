import numpy as np

x_data = [[9,2,5,6,3], [3,4,3,2,1], [3,1,3,3,1], [3,3,3,2,1], [12,7,9,8,4]]

x = np.array(x_data)

det = np.linalg.det(x)

print(det)