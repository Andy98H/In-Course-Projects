## @file Data.py
#  @author Andy Hameed
#  @brief Implements Data abstract object
#  @date 21/02/2018

from CurveADT import *
from SeqServices import *
from Exceptions import *

class Data:

    # Maximum size of the data
    MAX_SIZE = 10

    # Empty Sequences
    S = []
    Z = []

    ## @brief Data initializer
    @staticmethod
    def init():
        Data.S = []
        Data.Z = []
        
    ## @brief Add Method is used to append a new curve and value for a curve
    # @param s is the new curve being added
    # @param z is the new curve value being added
    @staticmethod    
    def add(s,z):
        if (len(Data.S) == Data.MAX_SIZE):          
            raise Full("Data is full")
        elif(len(Data.Z) > 0 and z <= Data.Z[-1]):
            raise IndepVarNotAscending("values must be in ascending order!")
        else: 
            Data.S.append(s)
            Data.Z.append(z)

    ## @brief getC Method is used to find the curve at a certain index
    # @param i is the specified index of the curve
    @staticmethod        
    def getC(i):
        if not (i >= 0 and i < len(Data.S)):
            raise InvalidIndex("Index is not valid")
        else:
            return Data.S[i]

    ## @brief eval Method is used to interpolate a curve given its value and an x value for interpolation
    # @param x is the x value of interpolation
    # @param z is the value of the curve being interpolated   
    @staticmethod        
    def eval(x,z):
        j = index(Data.Z,z)
        if not (isInBounds(Data.Z,z)):
            raise OutOfDomain("No longer in the domain")
        else:
            return interpLin(Data.Z[j],Data.S[j].eval(x),Data.Z[j+1],Data.S[j+1].eval(x),z)

    ## @brief slice method creates a curve of order i with y values 
    # @details corresponding to the interpolation at a given x value
    # @param x is the value of interpolation on each curve
    # @param i is the order of the curve being created        
    @staticmethod
    def slice(x,i):
        #Evaluating each curve in S at given x value before creating new curve
        Y = list(map(lambda s: s.eval(x),Data.S))  
        return CurveT(Data.Z,Y,i)  
        
    
