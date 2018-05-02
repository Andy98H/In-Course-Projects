## @file CurveADT.py
# @title CurveT
# @author Andy Hameed
# @date 01/22/2017

#Assume values of x increasing

from SeqADT import * 
import numpy as np
import math

## @brief This class represents a curve in the Cartesian x-y plane
class CurveT:
    ## @brief The Constructor method for CurveT creats two sequences
    # @details of x and y values gathered from imput s
    # @param s is a string containing the name of the file to be read
    def __init__(self, s):  
        self.X = SeqT()
        self.Y = SeqT() 
        infile = open(s, "r")
        
        for line in infile:
            temp = line.strip("\n")
            temp = temp.split(", ")

            self.X.add(self.Y.size(), int(temp[0])) #append each x coordinate 
            self.Y.add(self.X.size(), int(temp[1])) #append y coordinate
            
        infile.close()

    ## @brief The linVal method implements linear interpolation
    # @details on x given the sequence of x and y values
    # @param x is the point corresponding to the y value being calculated
    # @return the estimated value y for a given x
    def linVal(self, x):
                    
        i = self.X.indexInSeq(x)
        num = self.Y.get(i+1) - self.Y.get(i)
        denom = self.X.get(i+1) - self.X.get(i)
        y = (num/denom)*(x - self.X.get(i)) + self.Y.get(i)

        return y

    ## @brief The quadVal method implements Quadratic Interpolation
    # @details on x given the sequence of x and y values
    # @param x is the point corresponding to the y value being calculated
    # @return the estimated value y for a given x
    def quadVal(self,x):        
        i = self.X.indexInSeq(x)
        
        num1 = self.Y.get(i+1) - self.Y.get(i-1)
        denom1 = self.X.get(i+1) - self.X.get(i-1)
        lin = (num1/denom1)*(x - self.X.get(i)) + self.Y.get(i)
     
        num = self.Y.get(i+1) - 2*(self.Y.get(i)) + self.Y.get(i-1)
        denom = 2*(self.X.get(i+1) - self.X.get(i))**2
        
        y = (num/float(denom))*(x - self.X.get(i))**2 + lin
        
        return y

    ## @brief The npolyVal method implements regression(Best fitting)
    # @details to find the y value for a given point x
    # @param x is the point corresponding to the y value being calculated
    # @return the estimated value y for a given x using numpy functions
    def npolyVal(self,n ,x):
        curve = np.polyfit(self.X.state, self.Y.state, n)
        
        value = np.polyval(curve, x)
        return value
        



        
        
        

