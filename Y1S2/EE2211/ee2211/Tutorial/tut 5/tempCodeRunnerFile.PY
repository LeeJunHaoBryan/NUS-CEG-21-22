x2data = [[36], [26], [35], [39], [30], [31], [38], [36], [38]]
y2data = [[31], [20], [34], [35], [30], [30], [38], [34], [33]]

A = np.array(x2data)
Y2 = np.array(y2data)
bias2 = np.ones((len(x2data), 1))
A = np.hstack((bias,A))
w2 = np.linalg.lstsq(A,Y2, rcond = None)[0]
print(' ')
print('w2 is:')
print(w2)
