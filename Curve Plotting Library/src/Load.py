## @file Load.py
#  @author Andy Hameed
#  @brief Library for loading curves into the abstract object Data
#  @date 12/02/2018

from CurveADT import *
from Data import *


#What are environment variables?


## @brief Load is a method that initializes the data module to value
# @details found in the input file s
# @param s input file for reading curve values and x-y data points
def Load(s):
    Data.init()
    infile = open(s,"r")
    j = 0

    # Reading the values for each curve z1 ...Zn
    # and the order of interpolation o1 .. on
    temp = infile.readline().strip("\n").split(",")
    CurveValue = [float(x) for x in temp]
    temp = infile.readline().strip("\n").split(",") 
    Order = [float(x) for x in temp]
    
    #Setting reset cursor position to third line of input file
    last_pos = infile.tell()

    #collecting each pair of x-y values for each curve by
    #looping through file (rereading)
    for point in range(0,len(CurveValue)*2,2):
        infile.seek(last_pos)
        temp = []
        for line in infile:
            XY_pair = (line.strip("\n").split(","))[point:point+2]
            if (XY_pair[0] == ''):
                continue
            XY_coord = [float(x) for x in XY_pair]
            temp += XY_coord
        X = temp[::2]
        Y = temp[1::2]
        #Appending a new curve based on collected x-y values
        Data.add(CurveT(X,Y,Order[j]), CurveValue[j]) 
        j+=1

        
    infile.close()
