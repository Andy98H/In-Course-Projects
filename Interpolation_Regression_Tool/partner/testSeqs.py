## @file testSeqs.py
# @title testSeqs
# @author Andy Hameed
# @date 01/22/2017

from SeqADT import *
from CurveADT import *

##SeqADT 

## @brief Tests the add Method of the SeqT class
# @details Checking if values at each index correspond to the added values
#       The SeqT add method 
def test_add(): 
	global tested, tests
	tests+=1
	try: 
		#Test 1: Inserting at the end of sequence (appending)
		test_seq.add(0,2)
		test_seq.add(1,3)
		test_seq.add(2,4)
		test_seq.add(3,6)

		#Test 2: Inserting between elements
		test_seq.add(2,5)

		assert test_seq.state[0] == 2
		assert test_seq.state[1] == 3
		assert test_seq.state[2] == 5
		assert test_seq.state[3] == 4
		assert test_seq.state[4] == 6
		tested+=1
		print("add test: PASS")
	except:
		print("add test: FAIL")

## @brief Tests the rm Method of the SeqT class
# @details Checking if values have been removed based on index
#       The SeqT rm method 
def test_rm():
	global tested, tests
	tests+=1

	try:
		#Test 1: Removing element in range
		test_seq.rm(1)
		assert test_seq.state[1] != 3

		#Test 2: Removing element out of range
		#Error caught
		test_seq.rm(9)                                                  
		
		tested+=1
		print("rm test: PASS")
	except:
		print("rm test: FAIL")


## @brief Tests the set Method of the SeqT class
# @details Checking if indexed value has been replaced by input element
#       The SeqT set method     
#[2,5,4,8]
def test_set():
	global tested, tests
	tests+=1
	
	try:

		#Test 1: Set element within range
		test_seq.set(3,8)
		assert test_seq.state[3] == 8

		#Test 2: Set element out of range
		#Error caught 
		test_seq.set(10,6)                             

		tested+=1
		print("Set test: PASS")
	except:
		print("Set test: FAIL")


## @brief Tests the get Method of the SeqT class
# @details Checking if the value returned corresponds to element in sequence
#       The SeqT get method 
def test_get():
	global tested, tests
	tests+=1
	
	try:
		#Test 1: Get element within range
		assert test_seq.get(2) == 4

		#Test 2: Get element out of range
		#Error caught 
		assert test_seq.get(10) == "out of range"                               

		tested+=1
		print("get test: PASS")
	except:
		print("get test: FAIL")


## @brief Tests the size Method of the SeqT class
# @details Checking if the value returned corresponds to size of sequence
#       The SeqT size method 
def test_size():
	global tested, tests
	tests+=1
	
	try:
		assert test_seq.size() == 4

		tested+=1
		print("size test: PASS")
	except:
		print("size test: FAIL")


## @brief Tests the indexInSeq Method of the SeqT class
# @details Checking if the value returned corresponds to size of sequence
#       The SeqT size method 
def test_indexInSeq():
	global tested, tests
	tests+=1
	
	try:
		assert test_seq.indexInSeq(7) == 2

		tested+=1
		print("indexInSeq test: PASS")
	except:
		print("indexInSeq test: FAIL")

#***CurveADT***

## @brief Tests the Constructor of the CurveT class
# @details Testing based on the dataTest.txt file 
#       The CurveADT Constructor __init__
def test_CurveT():
	global tested, tests
	tests+=1
	
	try:
		assert new.X.get(4) == 13
		assert new.Y.get(5) == 20

		tested+=1
		print("CurveT test: PASS")
	except:
		print("CurveT test: FAIL")


## @brief Tests the linVal Method of the CurveT class
# @details Checking if the value returned corresponds to 
# @details value obtained using an online linear interpolation calculator
# @details https://www.ajdesigner.com/phpinterpolation/linear_interpolation_equation.php
#       The CurveADT linVal Method 
def test_linVal():
	global tested, tests
	tests+=1
	Tolerance = 1e-9
	
	try:
		assert ((new.linVal(15) - 16) < Tolerance)

		tested+=1
		print("linVal test: PASS")
	except:
		print("linVal test: FAIL")

## @brief Tests the quadVal Method of the CurveT class
# @details Checking if the value returned corresponds to 
# @details value obtained using an online quadratic interpolation calculator
# @details https://www.johndcook.com/quadratic_interpolator.html
#       The CurveADT quadVal Method 
def test_quadVal():
	global tested, tests
	tests+=1
	Tolerance = 1e-9
	
	try:
		assert ((new.quadVal(15) - 14.666666666666666) < Tolerance)

		tested+=1
		print("quadVal test: PASS")
	except:
		print("quadVal test: FAIL")

## @brief Tests the npolyVal Method of the CurveT class
# @details Checking if the value returned corresponds to 
# @details value obtained from online regression calculator
# @details https://www.graphpad.com/quickcalcs/linear1/
#       The CurveADT npolyVal Method 
def test_npolyVal():
	global tested, tests
	tests+=1
	Tolerance = 1e-9

	try:
		assert ((new.npolyVal(3,8) - 24.190458598099138) < Tolerance)

		tested+=1
		print("npolyVal test: PASS")
	except:
		print("npolyVal test: FAIL")



tested=0
tests=0

new = CurveT("dataTest.txt")
test_seq = SeqT() 

test_add()
test_rm() 
test_set()
test_get()
test_size()
test_indexInSeq()

test_CurveT()
test_linVal()
test_quadVal()
test_npolyVal()


print('\n', tested,' of', tests,' tests passed.')





