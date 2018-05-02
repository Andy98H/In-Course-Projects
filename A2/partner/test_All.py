import pytest
from CurveADT import *
from Data import *
from SeqServices import *
from Exceptions import *

class TestMethods:
    #at least one test case per procedure
    #test normal cases, boundary cases, and exception cases
    #print out # of self.tests self.passed / total self.tests
    #No doxygen comments needed
    
    def setup_method(self, method):
        self.tests = 0
        self.passed = 0
        self.curve1 = CurveT([1,2,3],[4,5,6],1)
        self.curve2 = CurveT([1,3,5],[6,8,34],2)
        self.curve4 = CurveT([2,3,4],[8,9,10],1)
        self.curve3 = CurveT([1,3,5,8,9,10,12,13,14,15,88],[6,8,34,45,15,24,12,32,45,12,89],2)
        Data.init()
        
    def teardown_method(self,method):
        self.curve1 = None
        self.curve2 = None
        Data = None

    #CurveADT Testing
    def test_IndepVarNotAscending_exc(self):
        
        self.tests+=1
        try:
            with pytest.raises(IndepVarNotAscending):
                self.curve = CurveT([1,3,2],[4,5,6],1)
            self.passed+=1
        except AssertionError:
            print("isAscending Test Failed")

    def test_SeqSizeMismatch(self):
        
        self.tests+=1
        try:
            with pytest.raises(SeqSizeMismatch):
                curve = CurveT([1,2,3],[4,5,6,7,8],1)
            self.passed+=1
        except AssertionError:
            print("SeqSizeMismatch Test Failed")    

    def test_InvalidInterpOrder(self):
        
        self.tests+=1
        try:
            with pytest.raises(InvalidInterpOrder):
                curve = CurveT([1,2,3],[4,5,6],5)
            self.passed+=1
        except AssertionError:
            print("InvalidInterpOrder Test Failed")
    
    def test_minD(self):
        
        self.tests+= 1
        try:
            assert self.curve1.minD() == 1
            self.passed+= 1
        except AssertionError:
            print("minD Test Failed")


    def test_maxD(self):
        
        self.tests+= 1
        try:
            assert self.curve1.maxD() == 3
            self.passed+= 1
        except AssertionError:
            print("maxD Test Failed")

    def test_order(self):
        
        self.tests+= 1
        try:
            assert self.curve1.order() == 1
            self.passed+= 1
        except AssertionError:
            print("order Test Failed")

    def test_eval(self):
        
        self.tests+= 1
        try:
            assert self.curve1.eval(2.5) == 5.5 
            self.passed+=1
        except AssertionError:
            print("eval Test Failed")

    def test_evalquad(self):
        
        self.tests+= 1
        try:
            assert self.curve2.eval(4.3) == pytest.approx(22.169999999999995, rel=0.1)
            self.passed+=1
        except AssertionError:
            print("evalquad Test Failed")

    def test_OutofDomain(self):
        
        self.tests+= 1
        try:
            with pytest.raises(OutOfDomain):
                self.curve1.eval(4)
            self.passed+=1
        except AssertionError:
            print("OutOfDomain Test Failed")

    def test_dfdx(self):
        
        self.tests+= 1
        try:
            assert self.curve1.dfdx(2.5) ==  pytest.approx(0.9999999999994458, rel=0.1) 
            self.passed+=1
        except AssertionError:
            print("dfdx Test Failed")

    def test_d2fdx2(self):
        self.tests+= 1
        try:
            assert self.curve1.d2fdx2(2.8) == pytest.approx(-8.881784197001252e-10, rel=0.1) 
            self.passed+=1
        except AssertionError:
            print("d2fdx2 Test Failed")  

    #Data Testing
    def test_init(self):
        
        self.tests+= 1
        try:
            assert Data.S == []
            assert Data.Z == []
            self.passed+=1
        except AssertionError:
            print("Data init Test Failed")

    def test_add(self):
        
        self.tests+= 1
        try:
            Data.add(self.curve1,5)
            Data.add(self.curve2,7)
            assert Data.S == [self.curve1,self.curve2]
            assert Data.Z == [5,7]
            self.passed+=1
        except AssertionError:
            print("Data add Test Failed")
            
    def test_add_MaxExc(self):
        
        self.tests+= 1
        try:
            Data.add(self.curve1,4)
            Data.add(self.curve1,5)
            Data.add(self.curve1,6)
            Data.add(self.curve1,8)
            Data.add(self.curve1,9)
            Data.add(self.curve1,10)
            Data.add(self.curve1,11)
            Data.add(self.curve1,12)
            Data.add(self.curve1,13)
            Data.add(self.curve1,14)
            with pytest.raises(Full):
                Data.add(self.curve1,16)
            self.passed+=1
        except AssertionError:
            print("Data Max_size exception Failed")

    def test_add_Notascending(self):
        
        self.tests+= 1
        try:
            Data.add(self.curve1,4)
            with pytest.raises(IndepVarNotAscending):
                Data.add(self.curve2,2)
            self.passed+=1
        except AssertionError:
            print("Data add Notascending exception Failed")

    def test_getC(self):
        
        self.tests+= 1
        try:
            Data.add(self.curve1,8)
            assert Data.getC(0) == self.curve1
            self.passed+=1
        except AssertionError:
            print("Data getC Failed")

    def test_getC_IndexExc(self):
        
        self.tests+= 1
        try:
            with pytest.raises(InvalidIndex):
                Data.getC(5) 
            self.passed+=1
        except AssertionError:
            print("Data getC index exception Failed")

    def test_data_eval(self):
        
        self.tests+= 1
        try:
            Data.add(self.curve1,5)
            Data.add(self.curve4,7)
            assert Data.eval(2.5,6) == 7
            self.passed+=1
        except AssertionError:
            print("Data getC index exception Failed")

    def test_data_eval_OOF(self):
        
        self.tests+= 1
        try:
            Data.add(self.curve1,4)
            Data.add(self.curve2,6)
            with pytest.raises(OutOfDomain):
                Data.eval(5,5)
            self.passed+=1
        except AssertionError:
            print("Data getC Out of Domain exception Failed")

    def test_slice(self):
        self.tests+= 1
        try:
            Data.add(self.curve1,9)
            Data.add(self.curve4,16)
            assert Data.slice(2.5,1).minD() == 9
            assert Data.slice(2.5,1).maxD() == 16
            self.passed+=1
        except AssertionError:
            print("Data slice Failed")

    #SeqServices Testing
    def test_isAscending(self):
        try:
            assert isAscending([1,2,3,4,5,6]) == True
            assert isAscending([6,2,2,1,0,3]) == False                   
            self.passed+=1
        except AssertionError:
            print("isAscending Failed")

    def test_isAscendingEqual(self):
        try:
            assert isAscending([1,2,2,2,2,7]) == True                  
            self.passed+=1
        except AssertionError:
            print("isAscending Failed")
    
    def test_isInBounds(self):
        try:
            assert isInBounds([1,2,3,4,5,6], 3)
            assert not isInBounds([1,2,3,4,5,6], 8)                   
            self.passed+=1
        except AssertionError:
            print("isInBounds Failed")

    
    def test_interpLin(self):
        try:
            assert interpLin(4,8,6,16,5) == 11                 
            self.passed+=1
        except AssertionError:
            print("interpLin Failed")    

    def test_interpQuad(self):
        try:
            assert interpQuad(3,10,5,12,8,15,6) == pytest.approx(13.055555556, rel=0.1)             
            self.passed+=1
        except AssertionError:
            print("interpQuad Failed")

    def test_index(self):
        try:
            assert index([2,4,6,8,10],7) == 2              
            self.passed+=1
        except AssertionError:
            print("interpQuad Failed")
            
    def printtests(self):
        print(self.passed, "OUT OF", self.tests, "PASSED")
    


    

            

