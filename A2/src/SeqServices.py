## @file SeqServices.py
#  @author Andy Hameed
#  @brief implements necessary methods for that service defined sequences 
#  @date 21/02/2018


def isAscending(X):
    for i in range(len(X) - 1):
        if (X[i+1] < X[i]):  
            return False
    return True 

def isInBounds(X,x):
    if (X[0] <= x <= X[len(X)-1]):
        return True
    return False
    
def interpLin(x1, y1, x2, y2, x):
    return ((y2-y1)/(x2-x1))*(x - x1) + y1

def interpQuad(x0, y0, x1, y1, x2, y2, x): 
    return y1 + ((y2 - y0)/(x2-x0))*(x - x1) + ((y2 - 2*y1 + y0)/(2*(x2-x1)**2))*(x - x1)**2

def index(X, x):
    for i in range(len(X)): 
        if (X[i] <= x and x < X[i+1]):
            return i;




 
