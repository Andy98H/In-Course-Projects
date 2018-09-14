## @file SeqServices.py
#  @author Baikai, Wang
#  @date 20 Feb 2018

## @brief Return a boolean value for testing a list is or not ascending
#  @para  X  a list needs to test
#  @return if the list X is ascending return true, else return false.
def isAscending(X):
        for i in range(len(X)-1):
            if  X[i+1] < X[i]:
                return False
        return True
 
## @brief Return a boolean value for testing an import is or not in bounds
#  @para  X  a list
#  @para  x  a import x for testing in bounds
#  @Assuming isAscending is True
#  @return if the list x is in bounds return true, else return false.
def isInBounds(X, x):
        if (X[0] <= x) and (x <= X[len(X)-1]):
            return True
        return False

## @brief Calculate a linear interpolate variable
#  @para  x1  an import x1
#  @para  y1  the correspending value of the import x1
#  @para  x2  an import x2
#  @para  y2  the correspending value of the import x2
#  @Assuming isAscending is True
#  @return the variable calculated by the interpolate linear function
def interpLin(x1, y1, x2, y2, x):
        return ((((y2-y1)/(x2-x1))*(x-x1))+y1)


## @brief Calculate a linear interpolate variable
#  @para  x1  an import x1
#  @para  y1  the correspending value of the import x1
#  @para  x2  an import x2
#  @para  y2  the correspending value of the import x2
#  @para  x3  an import x3
#  @para  y3  the correspending value of the import x3
#  @Assuming isAscending is True
#  @return the variable calculated by the interpolate quadratic function  
def interpQuad(x0, y0, x1, y1, x2, y2, x):
        return (y1 + (y2-y0)/(x2-x0) * (x-x1) + (y2-2*y1+y0)/(2*(x2-x1)**2) * (x-x1)**2)

## @brief Calculate a linear interpolate variable
#  @para  X  an import list
#  @para  x  the import x
#  @Assuming isInBounds is True
#  @return the variable calculated by the interpolate quadratic function  
def index(X, x):
        for i in range(len(X)-1):
            if X[i] <= x and x <= X[i+1]:
                return i
    
    
    
    
    
    
    
    
    
    