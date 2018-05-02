#include "catch.h"
#include "PointADT.h"
#include "LineADT.h"
#include "Exceptions.h"

TEST_CASE( "tests for LineT" , "[LineT]" ) {
  
  LineT lN(PointT(5, 10), N, 5);
  LineT lE(PointT(5, 10), E, 5);
  LineT lS(PointT(5, 10), S, 5);
  LineT lW(PointT(5, 10), W, 5);

  SECTION( "constructor exception for LineT with length 0" ){
    REQUIRE_THROWS_AS( LineT(PointT(0,0), N, 0), ::invalid_argument );
  }

  SECTION( "general tests for strt" ){
    REQUIRE
    ((      lN.strt().x() == 5
        &&  lN.strt().y() == 10 
    ));
  }
  
  SECTION( "general tests for end" ){
    REQUIRE
    ((      lN.end().x() == 5 
        &&  lN.end().y() == 14 
        &&  lE.end().x() == 9 
        &&  lE.end().y() == 10
        &&  lS.end().x() == 5 
        &&  lS.end().y() == 6 
        &&  lW.end().x() == 1
        &&  lW.end().y() == 10 
    ));
  }
  
  SECTION( "general tests for orient" ){
    REQUIRE
    ((      lN.orient() == N 
        &&  lE.orient() == E 
        &&  lS.orient() == S 
        &&  lW.orient() == W 
    ));
  }

  SECTION( "general tests for len" ){
    REQUIRE( lN.len() == 5 );
  }

  SECTION( "flip reverses direction" ){
    REQUIRE
    ((      lN.flip().orient() == S
        &&  lE.flip().orient() == W
        &&  lS.flip().orient() == N
        &&  lW.flip().orient() == E
    ));
  }

  SECTION( "flip maintains other parameters" ){
    REQUIRE
    ((      lN.flip().strt().x() == 5
        &&  lN.flip().strt().y() == 10
        &&  lN.flip().len() == 5
    ));
  }

  SECTION( "rotate changes direction properly" ){
    REQUIRE
    ((      lN.rotate(CW).orient() == E
        &&  lE.rotate(CW).orient() == S
        &&  lS.rotate(CW).orient() == W
        &&  lW.rotate(CW).orient() == N
        &&  lN.rotate(CCW).orient() == W
        &&  lE.rotate(CCW).orient() == N
        &&  lS.rotate(CCW).orient() == E
        &&  lW.rotate(CCW).orient() == S
    ));
  }

  SECTION( "rotate maintains other parameters" ){
    REQUIRE
    ((      lN.rotate(CW).strt().x() == 5
        &&  lN.rotate(CW).strt().y() == 10
        &&  lN.rotate(CW).len() == 5
        &&  lN.rotate(CCW).strt().x() == 5
        &&  lN.rotate(CCW).strt().y() == 10
        &&  lN.rotate(CCW).len() == 5
    ));
  }

  SECTION( "general tests for translate" ){
    LineT testLn = lN.translate(5, 5);

    REQUIRE
    ((      testLn.strt().x() == 10
        &&  testLn.strt().y() == 15
        &&  testLn.orient() == N
        &&  testLn.len() == 5
    ));
  }

  SECTION( "translate does not change original line" ){
    lN.translate(5, 5);

    REQUIRE
    ((      lN.strt().x() == 5
        &&  lN.strt().y() == 10
        &&  lN.orient() == N
        &&  lN.len() == 5
    ));
  }
}
