#include "catch.h"
#include "PointADT.h"

TEST_CASE( "tests for PointT" , "[PointT]" ) {
  
  PointT p(5, 10);
  
  SECTION( "general tests for x" ){
    REQUIRE( p.x() == 5 );
  }

  SECTION( "general tests for y" ){
    REQUIRE( p.y() == 10 );
  }
  
  SECTION( "general tests for translate" ){
    PointT testPt = p.translate(-20, 30);
    
    REQUIRE
    ((      testPt.x() == -15 
        &&  testPt.y() == 40
    ));
  }

  SECTION( "translate does not change original point" ){
    p.translate(5, 5);
    
    REQUIRE
    ((      p.x() == 5 
        &&  p.y() == 10
    ));
  }
  
}
