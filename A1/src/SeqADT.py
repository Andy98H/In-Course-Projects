## @file SeqADT.py
# @title SeqT
# @author Andy Hameed
# @date 01/22/2017

## @brief This class represents a sequence
class SeqT:

## @brief Constructor for SeqT creates an empty list 
    def __init__(self):
        self.state = []     

## @brief add Method: Adds an element to the sequence or appends the element to the end of sequence 
# @param v is the element being added
# @param i is the index placement of the element in the sequence
    def add(self,i, v):
    	# append if index is equal to number of elements 
        if ( i >= len(self.state)):
            self.state.append(v)
        #inserts element v at index i     
        else:
            self.state.insert(i,v)  
	    
## @brief rm Method: Removes an element from the sequence
# @param i is the index of the element to be removed from the sequence
    def rm(self,i):
        try:
            del self.state[i]
	#Exception: index is out of range
        except:
            print("Out of range! Please choose another index")

## @brief Accepts two parameters to replace an element in the sequence with a different element
# @param v is the replacement element
# @param i is the index of the element to be replaced
    def set(self,i, v):
        try:
            self.state[i] = v
        except:
            print("Pick an index in range!")

## @brief Gets the value of an element at a given index
# @param i is the index of the element required
# @return the value of element at index i
    def get(self,i):
        try:
            return self.state[i]
        except:
            return "out of range"
## @brief Gives the number of elements in the sequence (size)
# @return the size of sequence
    def size(self):
        return len(self.state)

## @brief finds the ordering of an element with respect to sequence members
# @details by determing two adjacent elements that surround the number
# @param v is the number being fitted into sequence
# @return the lower bound (left) element out of the two elements
    def indexInSeq(self,v):     
        i = 0
        while (True):
            if ((self.state[i] <= v) and (v <= self.state[i+1])):
                return i
            i += 1



