#include "../catch/catch.h"

#include "../include/CardADT.h"
#include "../include/FreeCell.h"
#include "../include/Exceptions.h"
#include <cmath>

TEST_CASE( "tests for FreeCellADT" , "[FreeCellADT]" ) {

  FreeCell free;
  Card c1(ace, S);
  Card c2(three, H);
  Card c3(five, D);
  Card c4(jack, C);

  
  SECTION( "addCard Exception" ){
    free.addCard(c1);
    free.addCard(c2);
    free.addCard(c3);
    free.addCard(c4);

    REQUIRE_THROWS_AS(free.addCard(Card(nine, H)),full);
  }

  SECTION( "searchCard" ){

  free.addCard(c1);
  free.addCard(c2);
  free.addCard(c3);
  free.addCard(c4);

    REQUIRE(free.searchCard(three,H).getRank() == three);
    REQUIRE(free.searchCard(three,H).getSuit() == H);

  }

  SECTION( "removeCard" ){


  free.addCard(c1);
  free.addCard(c2);
  free.addCard(c3);
  free.addCard(c4);

    free.removeCard(three,H);
    REQUIRE_THROWS_AS(free.searchCard(three, H), not_available);

  }
 
  SECTION( "isFull" ){

  free.addCard(c1);
  free.addCard(c2);
  free.addCard(c3);
  free.addCard(c4);

    REQUIRE(free.isFull());

    free.removeCard(three,H);
    REQUIRE(!free.isFull());    

  }

}