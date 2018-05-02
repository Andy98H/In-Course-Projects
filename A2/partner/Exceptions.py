## @file Exceptions.py
#  @author Andy Hameed
#  @brief implements exceptions used by other modules
#  @date 21/02/2018

## @brief An exception class for an inconsistency in ascending order of x coordinates
class IndepVarNotAscending(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return str(self.value)

## @brief An exception class for mismatched sequence size
class SeqSizeMismatch(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return str(self.value)

## @brief An exception class for Full data
class Full(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return str(self.value)

## @brief An exception class for out of domain evaluation 
class OutOfDomain(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return str(self.value)

## @brief An exception class for an invalid index input
class InvalidIndex(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return str(self.value)
## @brief An exception for handling invalid interpolation order
class InvalidInterpOrder(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return str(self.value)
    
