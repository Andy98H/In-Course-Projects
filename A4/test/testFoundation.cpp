#include "../catch/catch.h"

#include "../include/CardADT.h"
#include "../include/Foundation.h"
#include "../include/Exceptions.h"
#include <cmath>

TEST_CASE( "tests for Foundation" , "[Foundation]" ) {

  Foundation heart(H);
  Foundation spades(S);
  Foundation clubs(C);
  Foundation diamonds(D);

  Card c1(ace, H);
  Card c2(three, H);

  
  SECTION( "getSuit" ){
    REQUIRE(heart.getSuit() == H);
    REQUIRE(spades.getSuit() == S);
    REQUIRE(clubs.getSuit() == C);
    REQUIRE(diamonds.getSuit() == D);
  }

   SECTION( "addCard" ){
    heart.addCard(c1);
    REQUIRE_THROWS_AS(clubs.addCard(c2), invalid_move);
  }

  SECTION( "topCard" ){

    heart.addCard(c1);
    heart.addCard(Card(two,H));
    REQUIRE(heart.topCard().getSuit() == H);
    REQUIRE(heart.topCard().getRank() == two);
  }

   SECTION( "removeCard" ){
    heart.addCard(c1);
    heart.addCard(Card(two,H));
    heart.removeCard();
    REQUIRE(heart.topCard().getSuit() == H);
    REQUIRE(heart.topCard().getRank() == ace);

  }  
 
  SECTION( "isFull" ){
    heart.addCard(c1);
    heart.addCard(Card(two,H));
    heart.addCard(Card(three,H));
    heart.addCard(Card(four,H));
    heart.addCard(Card(five,H));
    heart.addCard(Card(six,H));
    heart.addCard(Card(seven,H));
    heart.addCard(Card(eight,H));
    heart.addCard(Card(nine,H));
    heart.addCard(Card(ten,H));
    heart.addCard(Card(jack,H));
    heart.addCard(Card(queen,H));
    heart.addCard(Card(king,H));

    REQUIRE(heart.isFull());
  }

}