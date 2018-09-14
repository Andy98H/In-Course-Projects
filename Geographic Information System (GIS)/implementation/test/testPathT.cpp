#include "catch.h"
#include "PointADT.h"
#include "LineADT.h"
#include "PathADT.h"
#include "MapTypes.h"
#include "Exceptions.h"

bool pt_eql(PointT p1, PointT p2) {
  return      p1.x() == p2.x()
          &&  p1.y() == p2.y();
}

bool line_eql(LineT l1, LineT l2) {
  return      pt_eql(l1.strt(), l2.strt())
          &&  l1.orient() == l2.orient()
          &&  l1.len() == l2.len();
}



TEST_CASE( "general tests for PathT" , "[PathT]" ) {
  
  SECTION( "general tests for append" ){
    PathT p_appendTest(PointT(0,0), N, 1);
    
    for(int i = 2; i <= 100; ++i){
      CompassT dir;
      
      switch(i%4) {
        case 0:
          dir = W;
          break;
        case 1:
          dir = N;
          break;
        case 2:
          dir = E;
          break;
        case 3:
          dir = S;
          break;
      }  
    
      p_appendTest.append(dir, i);
    }
    
    REQUIRE
    ((      p_appendTest.len() == 5050
        &&  p_appendTest.size() == 100
    ));
  }

  SECTION( "translate does not change original path" ){
    PathT p(PointT(0,0), N, 5);
    p.append(E, 6);
    p.append(S, 3);

    p.translate(5,5);

    REQUIRE
    ((      line_eql(p.line(0), LineT(PointT(0, 0), N, 5)) 
        &&  line_eql(p.line(1), LineT(PointT(1, 4), E, 6))  
        &&  line_eql(p.line(2), LineT(PointT(6, 3), S, 3))  
    ));
  }

}



TEST_CASE( "tests for PathT on a simple path" , "[PathT]" ) {
  
  PathT p_simple(PointT(5, 10), N, 5);
  
  SECTION( "general tests for strt (simple)" ){
    REQUIRE( pt_eql(p_simple.strt(), PointT(5, 10)) );
  }
  
  SECTION( "general tests for end (simple)" ){
    REQUIRE( pt_eql(p_simple.end(), PointT(5, 14)) );
  }

  SECTION( "general tests for size (simple)" ){
    REQUIRE( p_simple.size() == 1 );
  }

  SECTION( "general tests for len (simple)" ){
    REQUIRE( p_simple.len() == 5 );
  }

  SECTION( "general tests for line (simple)" ){
    REQUIRE( line_eql(p_simple.line(0), LineT(PointT(5, 10), N, 5)) );
  }

  SECTION( "general tests for translate (simple)" ){
    PathT trans = p_simple.translate(3, 3);
      
    REQUIRE( line_eql(trans.line(0), LineT(PointT(8, 13), N, 5)) );
  }

  SECTION( "line exception for outside bounds (simple)" ){
    REQUIRE_THROWS_AS( p_simple.line(1), outside_bounds ); 
  }

  SECTION( "append exception for self-crossing path (simple)" ){
    REQUIRE_THROWS_AS( p_simple.append(S, 1), ::invalid_argument ); 
  }

}



TEST_CASE( "tests for PathT on a complex path" , "[PathT]" ) {
  
  PathT p_complex(PointT(10, 5), N, 5);
  p_complex.append(E, 3);
  p_complex.append(S, 3);
  p_complex.append(E, 6);
  p_complex.append(S, 3);
  p_complex.append(W, 14);
  p_complex.append(N, 5);
  
  SECTION( "general tests for strt (complex)" ){
    REQUIRE( pt_eql(p_complex.strt(), PointT(10, 5)) );
  }
  
  SECTION( "general tests for end (complex)" ){
    REQUIRE( pt_eql(p_complex.end(), PointT(5, 8)) );
  }

  SECTION( "general tests for size (complex)" ){
    REQUIRE( p_complex.size() == 7 );
  }

  SECTION( "general tests for len (complex)" ){
    REQUIRE( p_complex.len() == 39 );
  }

  SECTION( "general tests for line (complex)" ){
    REQUIRE( line_eql(p_complex.line(4), LineT(PointT(19, 5), S, 3)) );
  }

  SECTION( "general tests for translate (complex)" ){
    PathT trans = p_complex.translate(3, 3);
      
    REQUIRE
    ((      line_eql(trans.line(0), LineT(PointT(13, 8), N, 5)) 
        &&  line_eql(trans.line(1), LineT(PointT(14, 12), E, 3))  
        &&  line_eql(trans.line(2), LineT(PointT(16, 11), S, 3))  
        &&  line_eql(trans.line(3), LineT(PointT(17, 9), E, 6))  
        &&  line_eql(trans.line(4), LineT(PointT(22, 8), S, 3))  
        &&  line_eql(trans.line(5), LineT(PointT(21, 6), W, 14))  
        &&  line_eql(trans.line(6), LineT(PointT(8, 7), N, 5))             
    ));
  }
  
  SECTION( "line exception for outside bounds (complex)" ){
    REQUIRE_THROWS_AS( p_complex.line(7), outside_bounds ); 
  }

  SECTION( "append exception for self-crossing path (complex)" ){
    REQUIRE_THROWS_AS( p_complex.append(E, 15), ::invalid_argument ); 
  }

}
