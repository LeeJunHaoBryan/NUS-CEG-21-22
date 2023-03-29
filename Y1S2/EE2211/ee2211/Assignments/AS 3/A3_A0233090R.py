import numpy as np

def grad1D(f, x, h = 1e-3):
    return (f(x+h) - f(x-h))/(2*h)
    
def grad2D(f, x, y, h = 1e-3):
    return (f(x+h, y) - f(x-h, y))/(2*h), (f(x, y + h) - f(x, y -  h))/(2*h)
    
def f1(x):
    return x**4
    
def f2(x):
    return (np.cos(x**2))**2

def f3(x, y):
    return x**3 + y**4


# Please replace "StudentMatriculationNumber" with your actual matric number here and in the filename
def A3_A0233090R(learning_rate, num_iters):
    """
    Input type
    :learning_rate type: float
    :num_iters type: int

    Return type
    :a_out type: numpy array of length num_iters
    :f1_out type: numpy array of length num_iters
    :b_out type: numpy array of length num_iters
    :f2_out type: numpy array of length num_iters
    :c_out type: numpy array of length num_iters
    :d_out type: numpy array of length num_iters
    :f3_out type: numpy array of length num_iters
    """
    # your code goes here
    a_out, f1_out = [], []
    a = 1.5
    b_out, f2_out = [], []
    b = 3
    c_out, d_out, f3_out = [], [], []
    c, d = 2, 3

    for _ in range(num_iters):
        a = a - learning_rate * grad1D(f1, a)
        b = b - learning_rate * grad1D(f2, b)
        gc, gd = grad2D(f3, c, d)
        c = c - learning_rate * gc
        d = d - learning_rate * gd

        a_out.append(a)
        f1_out.append(f1(a))
        b_out.append(b)
        f2_out.append(f2(b))
        c_out.append(c)
        d_out.append(d)
        f3_out.append(f3(c, d))


    # return in this order
    return a_out, f1_out, b_out, f2_out, c_out, d_out, f3_out

def print_array(a, title):
    print(title, ":", end='\t')
    for num in a:
        print("%.5f " % num, end='')
    print()



a_out, f1_out, b_out, f2_out, c_out, d_out, f3_out = A3_A0233090R(0.1, 1)
#print_array(a_out, "a_out")
#print_array(f1_out, "f1_out")
##print_array(b_out, "b_out")
print_array(f2_out, "f2_out")
print_array(c_out, "c_out")
print_array(d_out, "d_out")
#print_array(f3_out, "f3_out")
