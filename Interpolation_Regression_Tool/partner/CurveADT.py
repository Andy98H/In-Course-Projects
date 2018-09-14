## @file CurveADT.py
#  @author Guiye Wu
#  @brief Provides the CurveT ADT class for finding a point by interpolation
#  @date 1/21/2018

import numpy
from SeqADT import *

## @brief An ADT that determine a point by interpolation and regression
#  @details The point is determined by curve's data points in Cartesian space
#           x and y. The first method is to use linear interpolation and the
#           second method is to use quadratic interpolation and the last one
#           is regression by using the function polyfit in numpy.
class CurveT:

    ## @brief CurveT constructor
    #  @details Initializes a data of x values and y values by using ADT of SeqT.
    #           The values are get from a txt file, the txt file has two column
    #           of values, the first column represent the data of x value, and
    #           the second column is y values. Each row of each number sparate by
    #           a comma and a space, and the end of the row is a newline.
    #  @param s The txt file name
    def __init__(self,s):
        f = open(s,"r")
        self.x = SeqT()
        self.y = SeqT()
        i = 0
        for line in f:
            lst = line.split(", ")
            self.x.add(i,float(lst[0]))
            self.y.add(i,float(lst[1]))
            i += 1
        f.close()

    ## @brief Use linear interpolation to find the y value
    #  @details Linear interpolation uses the formula
    #           'y = (y2-y1)/(x2-x1)*(x-x1)+y1'
    #           to find y by input x, (x1, y1) is the point on the curve to the
    #           left of x and (x2, y2) is the point on the curve to the right.
    #  @param x The input value x that is used to find value y
    #  @return The output value y by linear interpolation
    def linVal(self,x):
        index = self.x.indexInSeq(x)
        x1 = self.x.get(index)
        x2 = self.x.get(index+1)
        y1 = self.y.get(index)
        y2 = self.y.get(index+1)
        return (y2-y1)/(x2-x1)*(x-x1)+y1

    ## @brief Use quadratic interpolation to find the y value
    #  @details Quadratic interpolation uses the formula
    #           'y1+(y2-y0)/(x2-x0)*(x-x1)+(y2-2*y1+y0)/(2*(x2-x1)^2)*(x-x1)^2'
    #           to find y by input value x, this method is similar to linear
    #           interpolation, and (x0, y0) is the point on the curve to the left
    #           of (x1, y1).
    #  @param x The input value x that is used to find value y
    #  @return The output value y by quadratic interpolation
    def quadVal(self,x):
        index = self.x.indexInSeq(x)
        x0 = self.x.get(index-1)
        x1 = self.x.get(index)
        x2 = self.x.get(index+1)
        y0 = self.y.get(index-1)
        y1 = self.y.get(index)
        y2 = self.y.get(index+1)
        return y1+(y2-y0)/(x2-x0)*(x-x1)+(y2-2*y1+y0)/(2*(x2-x1)**2)*(x-x1)**2

    ## @brief Use regression to find the y value
    #  @details Regression is to find a polynomial that minimizes the square of
    #           error between the data and the fitted polynomial, it is done by
    #           using numpy.polyfit that is function from numpy directly. This
    #           function will need the degree of the polynomial as input, and
    #           also an array of x data and an array of y data, then function
    #           return an array of polynomial coefficient. Using the coeficient
    #           to be the input x coefficient to find the y value.
    #  @param n Polynomial coefficient
    #  @param x The input x value
    #  @return The output value y by regression
    def npolyVal(self,n,x):
        xarr = []
        yarr = []
        for i in range(self.x.size()):
            xarr.append(self.x.get(i))
            yarr.append(self.y.get(i))
        coef = numpy.polyfit(xarr,yarr,n)
        y = 0
        for j in range(n+1):
            y += coef[j]*(x**(-j+n))
        return y
