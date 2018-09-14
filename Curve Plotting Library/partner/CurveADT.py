## @file CurveADT.py
#  @author Baikai, Wang
#  @date 20 Feb 2018
from SeqServices import *
from Exceptions import *
class CurveT:
    # maximum order of curve is 2
    MAX_ORDER = 2
    
    DX = 1*10**(-3)
    
    ## @brief CurveT constructor
    #  @details Initializes a CurveT object using a list X and list Y
    #  @param X a list named X
    #  @param p2 a list named Y
    def __init__(self, X, Y, i):
        if (isAscending(X) == False):
            raise IndepVarNotAscending("The list is not ascending!")
        elif (len(X) != len(Y)):
            raise SeqSizeMismatch("The lengths of two lists are not equal!")  
        s = []
        for j in range(1, CurveT.MAX_ORDER+1):
            s.append(j)
        if (i not in s):
            raise InvalidInterpOrder("The import order is out of the max order range!")
        self.minx = X[0]
        self.maxx = X[len(X)-1]
        self.o = i
        self.f = (lambda v: __interp__(X, Y, self.o, v))
    
    ## @brief Gets minimum x point of the curve
    #  @return The minimum point of curve
    def minD(self):
        return self.minx
    
    ## @brief Gets maximum x point of the curve
    #  @return The maximum point of curve
    def maxD(self):
        return self.maxx
    
    ## @brief Gets order of the curve
    #  @return The order of curve
    def order(self):
        return self.o
    
    ## @brief Evaluate a import x in the curve
    #  @details Finds evaluate value for an import x by using the local function
    #  @para x import a x-coordinate
    #  @return The evaluate value of an import x
    def eval(self, x):
        if self.minx > x or x > self.maxx:
            raise OutOfDomain("The variable x out of the function's domain!")
        return self.f(x)
    
    ## @brief Gets the first derivative of an import x
    #  @details Finds the first derivative of an x by using the first derivative formula
    #  @para x import a x-coordinate
    #  @return The first derivative variable of a x
    def dfdx(self, x):
        if self.minx > x or x > self.maxx:
            raise OutOfDomain("The variable x out of the function's domain!")
        return ((self.f(x+CurveT.DX) - self.f(x))/CurveT.DX)
    
    ## @brief Gets the second derivative of an import x
    #  @details Finds the second derivative of an x by using the second derivative formula
    #  @para x import a x-coordinate
    #  @return The second derivative variable of a x
    def d2fdx2(self, x):
        if self.minx > x or x > self.maxx:
            raise OutOfDomain("The variable x out of the function's domain!")
        return ((self.f(x+2*CurveT.DX) - 2*self.f(x+CurveT.DX) + self.f(x))/(CurveT.DX**2))


## @brief Gets the interpolate value of a specific import v
#  @details Find the interpolate value of a x if it's a linear function or quadratic function,
#            using the interpolate function defined in SeqServices class.
#  @para X the x-coordinates of a Curve
#  @para Y the represented y values of each x
#  @para o the order of the curve
#  @para v an import variable for this curve
#  @return an interpolate value of the v     
def __interp__(X, Y, o, v):
    i = index(X, v)
    if o == 1:
        return (interpLin(X[i], Y[i], X[i+1], Y[i+1], v))
    elif o == 2:
        return (interpQuad(X[i-1], Y[i-1], X[i], Y[i], X[i+1], Y[i+1], v))

