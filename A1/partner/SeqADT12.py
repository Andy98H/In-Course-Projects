## @file SeqADT.py
#  @author Guiye Wu
#  @brief Provides the SeqT ADT class for representing curve's data points
#  @date 1/21/2018

## @brief An ADT that modify a sequence for curve's data points
class SeqT:

    ## @brief SeqT constructor
    #  @details Initializes an empty sequence
    def __init__(self):
        self.seq = []

    ## @brief Add a real number into the sequence at specific position
    #  @details The real number can not add to the position that is not in the
    #           range of the sequence, the range of the sequence is from 0 to the
    #           sequence size.
    #  @param i The index in the sequence that the value is added at
    #  @param v The real number that should be added
    #  @exception If the index is greater than the length of the sequence or index
    #             is less than 0, ValueError raise.
    def add(self,i,v):
        if ((i > len(self.seq)) or (i < 0)):
            raise ValueError("Index is out of the range")
        else:
            self.seq.insert(i,v)

    ## @brief Remove a value in the sequence
    #  @param i The index of the value that should be remove
    def rm(self,i):
        ival = self.seq[i]
        self.seq.remove(ival)

    ## @brief Modify the sequence at specific index to have a value
    #  @param i The index in the sequence that the value is setted at
    #  @param v The real number that should be setted
    def set(self,i,v):
        self.seq[i] = v

    ## @brief Get the value at specific positon
    #  @param i The index of the value that should be gotten
    #  @return The value at the specific position of the sequence
    def get(self,i):
        return self.seq[i]

    ## @brief Get the size of the sequence
    #  @return The size of the sequence
    def size(self):
        return len(self.seq)

    ## @brief Take an input of a real number and get the index from a specific range
    #  @details The function take the real number, finds if the any number in the
    #           sequence that is less than or equal to the real number and also the
    #           next value of the sequence is greater than or equal to the real
    #           number. If the value in the sequence exist, then output the index of
    #           the value.
    #  @param v The real number that is used to get the index
    #  @return Returns the index of the real number if it is in the range
    #  @exception ValueError Raise the error if the real number is not in the range
    def indexInSeq(self,v):
        i = 0
        for j in range(len(self.seq)-1):
            if ((self.seq[j] <= v) and (v <= self.seq[j+1])):
                return i
            else:
                i += 1
        if (i == (len(self.seq)-1)):
            raise ValueError("value is not in range")
            
