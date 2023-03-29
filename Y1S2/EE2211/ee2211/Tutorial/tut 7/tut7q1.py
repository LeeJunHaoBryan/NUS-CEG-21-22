import numpy as np

x1 = np.array([0.351, 2.1812, 0.2415, -0.1096, 0.1544])
x2 = np.array([1.1796, 2.1068, 1.7753, 1.2747, 2.0851])
x3 = np.array([0.0838, -0.4092, -0.3025, 1.4621, 0.4658])
y = np.array([0.8206, 1.0639, 0.06895, 0.0252, 0.995])

r1 = np.corrcoef(x1, y)
r2 = np.corrcoef(x2, y)
r3 = np.corrcoef(x3, y)

print('\nr1 is:\n', r1)
print('\nr2 is:\n', r2)
print('\nr3 is:\n', r3)

print('Pearson correlation values are : ', r1[0][1], r2[0][1], r3[0][1])