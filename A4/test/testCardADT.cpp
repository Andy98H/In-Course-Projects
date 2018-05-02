#include "../catch/catch.h"

#include "../include/CardADT.h"
#include "../include/Exceptions.h"
#include <cmath>


TEST_CASE( "tests for CardADT" , "[CardADT]" ) {

  Card c1(four,D);
  Card c2(five, H);
  Card c3 (eight, S);
  Card c4 (ace, C);


  // Red is 0, 1 is black
  SECTION( "Correct colour using colour get method" ){
  REQUIRE(c1.getColour() == 0);
  REQUIRE(c2.getColour() == 0);
  REQUIRE(c3.getColour() == 1);
  REQUIRE(c4.getColour() == 1);
  }

  SECTION( "getRank" ){
  REQUIRE(c1.getRank() == 4);
  REQUIRE(c4.getRank() == 1);
  }

  SECTION( "getSuit" ){
  REQUIRE(c1.getSuit() == 1);
  REQUIRE(c4.getSuit() == 0);
  }

}