#include "../catch/catch.h"

#include "../include/CardADT.h"
#include "../include/Tableau.h"
#include "../include/Exceptions.h"
#include <cmath>

#include <vector>

TEST_CASE( "tests for Tableau" , "[Tableau]" ) {

  vector<Card> tmp;
  tmp.push_back(Card(ace,H));   // 1H , 5S, 4D, 2C, 9D, QH
  tmp.push_back(Card(five,S));
  tmp.push_back(Card(four,D)); 
  tmp.push_back(Card(two,C)); 
  tmp.push_back(Card(nine,D));  
  tmp.push_back(Card(queen,H)); 

  Tableau pile(tmp);

  SECTION( "topCard" ){
    REQUIRE(pile.topCard().getRank() == queen);
    REQUIRE(pile.topCard().getSuit() == H);
  }

   SECTION( "addCard" ){
    pile.addCard(Card(jack,C));
    REQUIRE(pile.topCard().getRank() == jack);
    REQUIRE(pile.topCard().getSuit() == C);
  }

  SECTION( "addCard Exception" ){
    REQUIRE_THROWS_AS(pile.addCard(Card(jack,H)), invalid_move); //same suit
    REQUIRE_THROWS_AS(pile.addCard(Card(ten, C)), invalid_move); //invalid rank
  }


   SECTION( "topCard" ){
    REQUIRE(pile.topCard().getSuit() == H);
    REQUIRE(pile.topCard().getRank() == queen);

  }  
 
}