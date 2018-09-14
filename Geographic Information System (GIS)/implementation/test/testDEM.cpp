#include "catch.h"
#include "PointADT.h"
#include "LineADT.h"
#include "PathADT.h"
#include "DEM.h"
#include "Exceptions.h"

#include <vector>

using std::vector;

TEST_CASE( "tests for DEMT" , "[DEMT]" ) {
  
  vector<vector<int>> v;
  
  /*    TEST GRID 'v':
   * 
   *    3   3   3   0   6
   *    0   1   3   1   6
   *    1   1   3   1   5
   *    1   2   3   3   5
   */
  
  v.push_back( vector<int> {1,2,3,3,5} );
  v.push_back( vector<int> {1,1,3,1,5} );
  v.push_back( vector<int> {0,1,3,1,6} );
  v.push_back( vector<int> {3,3,3,0,6} );
  
  DEMT dem(v, 3.0);
  
  SECTION( "constructor exception for negative scale" ){
    REQUIRE_THROWS_AS( DEMT(v, -1.0), ::invalid_argument );
  }

  SECTION( "constructor exception for zero scale" ){
    REQUIRE_THROWS_AS( DEMT(v, 0.0), ::invalid_argument );
  }

  SECTION( "constructor exception for empty grid" ){
    REQUIRE_THROWS_AS( DEMT(vector<vector<int>>(), 1.0), ::invalid_argument );
  }

  SECTION( "constructor exception for grid with empty row" ){
    vector<vector<int>> grid;
    grid.push_back( vector<int>() );

    REQUIRE_THROWS_AS( DEMT(grid, 1.0), ::invalid_argument );
  }

  SECTION( "constructor exception for grid with unequal row lengths" ){
    vector<vector<int>> grid;
    grid.push_back( vector<int> {0,0,0,0} );
    grid.push_back( vector<int> {0,0,0,0} );
    grid.push_back( vector<int> {0,0,0} );
    grid.push_back( vector<int> {0,0,0,0} );
    
    REQUIRE_THROWS_AS( DEMT(grid, 1.0), ::invalid_argument );
  }

  SECTION( "general tests for get" ){
    REQUIRE( dem.get(PointT(1,2)) == 1 );
  }

  SECTION( "get on upper right corner" ){
    REQUIRE( dem.get(PointT(4,3)) == 6 );
  }

  SECTION( "get exception on invalid point" ){
    REQUIRE_THROWS_AS( dem.get(PointT(3,4)), outside_bounds );
  }

  SECTION( "general tests for set" ){
    dem.set(PointT(1,3), 50);
    REQUIRE( dem.get(PointT(1,3)) == 50 );
  }  

  SECTION( "set exception on invalid point" ){
    REQUIRE_THROWS_AS( dem.set(PointT(3,4), 0), outside_bounds );
  }

  SECTION( "general tests for getNumRow" ){
    REQUIRE( dem.getNumRow() == 4 );
  }

  SECTION( "general tests for getNumCol" ){
    REQUIRE( dem.getNumCol() == 5 );
  }

  SECTION( "general tests for getScale" ){
    // don't need approx here since no arithmetic has been done.
    REQUIRE( dem.getScale() == 3.0 );
  }
  
  SECTION( "general tests for count(T)" ){
    REQUIRE
    ((      dem.count(0) == 2
        &&  dem.count(1) == 6
        &&  dem.count(2) == 1
        &&  dem.count(3) == 7
        &&  dem.count(4) == 0
        &&  dem.count(5) == 2
        &&  dem.count(6) == 2
    ));
  }

  SECTION( "general tests for count(LineT, T)" ){
    LineT l(PointT(4,2), W, 4);    

    REQUIRE
    ((      dem.count(l, 0) == 0
        &&  dem.count(l, 1) == 2
        &&  dem.count(l, 2) == 0
        &&  dem.count(l, 3) == 1
        &&  dem.count(l, 4) == 0
        &&  dem.count(l, 5) == 0
        &&  dem.count(l, 6) == 1
    ));
  }

  SECTION( "count(LineT, T) exception for line extending outside of grid" ){
    LineT l(PointT(2,2), N, 3);    

    REQUIRE_THROWS_AS( dem.count(l, 0), ::invalid_argument );
  }

  SECTION( "general tests for count(PathT, T)" ){
    PathT p(PointT(0,0), N, 3);
    p.append(E, 3);
    p.append(S, 1);   

    REQUIRE
    ((      dem.count(p, 0) == 1
        &&  dem.count(p, 1) == 5
        &&  dem.count(p, 2) == 0
        &&  dem.count(p, 3) == 1
        &&  dem.count(p, 4) == 0
        &&  dem.count(p, 5) == 0
        &&  dem.count(p, 6) == 0
    ));
  }

  SECTION( "count(PathT, T) exception for path extending outside of grid" ){
    PathT p(PointT(0,0), N, 3);
    p.append(E, 3);
    p.append(S, 1);
    p.append(E, 2);  

    REQUIRE_THROWS_AS( dem.count(p, 0), ::invalid_argument );
  }

  SECTION( "general tests for length" ){
    PathT p(PointT(0,0), N, 3);
    p.append(E, 3);
    p.append(S, 1);

    REQUIRE( dem.length(p) == Approx(21.0) );
  }

  SECTION( "length exception for path extending outside of grid" ){
    PathT p(PointT(0,0), N, 3);
    p.append(E, 3);
    p.append(S, 1);
    p.append(E, 2);

    REQUIRE_THROWS_AS( dem.length(p), ::invalid_argument );
  }

  SECTION( "(0,0) -> (1,2) is connected" ){
    REQUIRE( dem.connected(PointT(0,0), PointT(1,2)) );
  }

  SECTION( "(0,0) -> (3,2) not connected" ){
    REQUIRE( !dem.connected(PointT(0,0), PointT(3,2)) );
  }

  SECTION( "(3,0) -> (0,3) is connected" ){
    REQUIRE( dem.connected(PointT(3,0), PointT(0,3)) );
  }

  SECTION( "(0,3) -> (3,0) is connected" ){
    REQUIRE( dem.connected(PointT(0,3), PointT(3,0)) );
  }

  SECTION( "(0,2) -> (3,3) not connected" ){
    REQUIRE( !dem.connected(PointT(0,2), PointT(3,3)) );
  }

  SECTION( "(2,1) -> (0,0) not connected" ){
    REQUIRE( !dem.connected(PointT(2,1), PointT(0,0)) );
  }

  SECTION( "connected exception for point outside grid" ){
    REQUIRE_THROWS_AS( dem.connected(PointT(0,0), PointT(5,5)), ::invalid_argument );
  }

}
