## @file Data.py
#  @author Baikai, Wang
#  @date 20 Feb 2018

from CurveADT import CurveT
from SeqServices import *
from Exceptions import *

class Data:
    # maximum size of sequence is 10
    MAX_SIZE = 10
    
    #empty sequence
    S = []
    Z = []
    
    ## @brief Data initializer
    @staticmethod
    def init():
        Data.S = []
        Data.Z = []
    
    ## @brief insert element to sequences
    @staticmethod
    def add(s, z):
        if (len(Data.S) == Data.MAX_SIZE):
            raise FULL("Maximum size exceeded")
        
        if (len(Data.Z) != 0):
            if (z <= Data.Z[len(Data.Z)-1]):
                raise IndepVarNotAscending("The list is not ascending!")
        Data.S.append(s)
        Data.Z.append(z)
    
    ## @brief Gets a curve from the list of Data.S 
    @staticmethod
    def getC(i):
        if (i < 0 or i >= len(Data.S)):
            raise InvalidIndex("The variable i is not the correct index")
        return Data.S[i]
    
    ## @brief Calculate an import value x with a given index position z 
    #  @details To evaluate an import x, we need to find the index position 
    #           in Data.Z with the import z. Then, using the linear interpolate 
    #           function  calculate the variable.
    #  @para x  the variable needs to evaluate
    #  @para z  the import z is to find the postion on Data.Z where x needs to calculate.
    #  @return  the output of the x.
    @staticmethod
    def eval(x, z):
        if (isInBounds(Data.Z, z) == False):
            raise OutOfDomain("The variable x out of the function's domain!")
        j = index(Data.Z, z)
        return (interpLin(Data.Z[j], Data.S[j].eval(x), Data.Z[j+1], Data.S[j+1].eval(x), z))
    
    ## @brief Gets a curve from the list of Data.S 
    @staticmethod
    def slice(x, i):
        Y = []
        for j in range(len(Data.S)):
            Y.append(Data.S[j].eval(x))
        return CurveT(Data.Z, Y, i)
    
