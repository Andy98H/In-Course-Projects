## @file CurveADT.py
#  @author Andy Hameed
#  @brief implements an abstract data type for a curve
#  @date 21/02/2018

from SeqServices import *
from Exceptions import *

## @brief An Abstract Data type representing a curve
class CurveT:
    
    ## @brief CurveT constructor
    #  @details Initializes a CurveT object with a set of X and Y coordinates
    #  @param X The set of x values for the curve
    #  @param Y The set of y values for the curve
    #  @param i Order of polynomials representing curves
    def __init__(self,X, Y, i):
        self.MAX_ORDER = 2
        self.DX = 1e-3
        
        if not (isAscending(X)):
            raise IndepVarNotAscending("values must be in ascending order!")
        elif (len(X) != len(Y)):
            raise SeqSizeMismatch("Sequence size X does not match Y")
        elif (i < 1 or i > self.MAX_ORDER): 
            raise InvalidInterpOrder("Order of interpolation should be 1 or 2")
        else:
            self.minx = X[0]
            self.maxx = X[-1]
            self.o = i
            self.f = lambda v : interp(X,Y,self.o,v)

    ## @brief Accessor method for minimum x value in X
    # @return minimum value x
    def minD(self):
        return self.minx
    
    ## @brief Accessor method for maximum x value in X
    # @return maximum value x
    def maxD(self):
        return self.maxx

    ## @brief Accessor method for the order of a curve
    # @return order of curve
    def order(self):
        return self.o
    
    ## @brief eval method performs interpolation on a value x
    # @return interpolated y value
    def eval(self, x):
        if not (self.minD() <= x and x <= self.maxD()):
            raise OutOfDomain("No longer in the domain")
        else:
            return self.f(x)

    ## @brief dfdx method finds the first direvative at a given point x
    # @param x is the point where derivative is taken 
    # @return First direvative of curve at x 
    def dfdx(self, x):
        if not (self.minD() <= x and x <= self.maxD()):
            raise OutOfDomain("No longer in the domain")
        else:
            First_Dir = (self.f(x + self.DX) - self.f(x))/self.DX
            return First_Dir

    ## @brief d2fdx2 method finds the second direvative at a given point x
    # @param x is the point where second derivative is taken 
    # @return Second direvative of curve at x 
    def d2fdx2(self, x):
        if not (self.minD() <= x and x <= self.maxD()):
            raise OutOfDomain("No longer in the domain")
        else:
            Sec_Dir = (self.f(x + 2*self.DX) - (2*self.f(x + self.DX)) + self.f(x))/((self.DX)**2)
            return Sec_Dir

## @brief A function that performs linear or quadratic interpolations depending
# @details on input
# @param X set of x-values 
# @param Y set of y-values
# @param o order of interpolation
# @param v value being interpolated for
# @return intepolated value y at the given x-value v
def interp(X,Y,o,v):
    i = index(X,v);
    if (o == 1):
        return interpLin(X[i],Y[i],X[i+1],Y[i+1],v)
    elif (o == 2):
        return interpQuad(X[i-1],Y[i-1],X[i],Y[i],X[i+1],Y[i+1],v)
            
    
        
