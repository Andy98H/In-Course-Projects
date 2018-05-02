## @file Plot.py
#  @author Andy Hameed
#  @brief Implements curve plotting
#  @date 21/02/2018

import CurveADT
import Exceptions
import numpy as np
from graphics import *
import matplotlib.pyplot as plt

# @brief Plotseq creates an x-y plot graph using the inputted sets of values
# @param X is the set of x-values
# @param Y is the set of y-values
def PlotSeq(X, Y):
    if (len(X) != len(Y)):
        raise SeqSizeMismatch("Sequence size does not match")
    else:
        plt.plot(X, Y)
        plt.show()
        
# @brief PlotCurve plots a curve c using n data points
# @param c is the curve to be plotted
# @param n is the number of data points or intervals used for graphing
def PlotCurve(c,n):
    X = np.linspace(c.minD(),c.maxD(),n,endpoint = False)
    if (c.order() == 2):
        X = X[1:]
    Y = [c.eval(x) for x in X]
    PlotSeq(X,Y)
    


    
