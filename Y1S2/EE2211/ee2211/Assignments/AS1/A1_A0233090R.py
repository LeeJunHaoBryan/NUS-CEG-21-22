import numpy as np


# Please replace "MatricNumber" with your actual matric number here and in the filename
def A1_A0233090R(X, y):
    """
    Input type
    :X type: numpy.ndarray
    :y type: numpy.ndarray

    Return type
    :XT type: numpy.ndarray
    :InvXTX type: numpy.ndarray
    :w type: numpy.ndarray
   
    """
    # your code goes here
    XT=np.transpose(X)
    XTX = np.dot(XT, X)
    InvXTX = np.linalg.inv(XTX)
    InvXTXX=np.dot(InvXTX,XT)
    w =  np.dot(InvXTXX, y)


    # return in this order
    return InvXTX, w
