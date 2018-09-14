#include "../catch/catch.h"
#include <cmath>
#include <cstdlib>

#include "../include/CardADT.h"
#include "../include/FreeCell.h"
#include "../include/Tableau.h"
#include "../include/Foundation.h"
#include "../include/Setup.h"
#include "../include/Exceptions.h"

TEST_CASE( "tests for Setup" , "[Setup]" ) {
  vector<Card> tmp;
  vector< vector<Card> > s;

  int i = 8;
  for (int j = 0; j < 8; j++){
    while (i--){
      tmp.push_back(Card((Rank) (i + 1), (Suit)(j/2)));
    } 
    i = 8;
    s.push_back(tmp);
    tmp.clear();  
  }

  //trivial set of tableaus for test suite
  Setup set = Setup(s);
  Setup set2 = Setup(s);


  SECTION( "Setup random tableau generator" ){
    Setup set1 = Setup();
    set1.tabTopCards(); //no error produced
  }


 SECTION( "tabToFree" ){
   set.tabToFree(0); // Rank 1 Suit 0 to free cells 
   REQUIRE(set.free.searchCard(ace, C).getRank() == 1);
   REQUIRE(set.free.searchCard(ace, C).getSuit() == 0);
  }

  SECTION( "tabToFree Exception" ){
   set.tabToFree(0); // Rank 1 Suit 0 to free cells
   set.tabToFree(1);
   set.tabToFree(2);
   set.tabToFree(3);

   REQUIRE_THROWS_AS(set.tabToFree(4),full);
  }


 SECTION( "freeToFound" ){
   set.tabToFree(0); // Rank 1 Suit 0 to free cells 
   set.freeToFound(ace, C);
   REQUIRE(set.founds[0].topCard().getRank() == 1);
   REQUIRE(set.founds[0].topCard().getSuit() == 0);
  }

 SECTION( "tabToTab" ){
    set.tabToFree(0); // Rank 1 Suit 0 to free cells
    REQUIRE(set.board[0].topCard().getRank() == 2);
    REQUIRE(set.board[0].topCard().getSuit() == 0); 
  	set.tabToTab(2,0);
    REQUIRE(set.board[0].topCard().getRank() == 1);
    REQUIRE(set.board[0].topCard().getSuit() == 1);
  }

  SECTION( "foundToTab" ){
   set.tabToFree(0); // Rank 1 Suit 0 to free cells 
   set.freeToFound(ace, C);
   set.tabToTab(2,0); 
    REQUIRE(set.board[2].topCard().getRank() == 2);
    REQUIRE(set.board[2].topCard().getSuit() == 1);
   set.foundToTab(C, 2);
    REQUIRE(set.board[2].topCard().getRank() == 1);
    REQUIRE(set.board[2].topCard().getSuit() == 0);
  }


 SECTION( "tabToFound" ){
   set.tabToFound(0);
   REQUIRE(set.founds[0].topCard().getRank() == 1);
   REQUIRE(set.founds[0].topCard().getSuit() == 0);
  }

  SECTION( "freeToTab" ){
      set2.tabToFree(0); // Rank 1 Suit 0 to free cells
      set2.tabToTab(2,0); 
      set2.freeToTab(ace, C,2);
    }

  SECTION( "Winning Game" ){
    for (int j = 0; j < 4; j++){
      for (int i = 1; i < 14; i ++){
        set2.founds[j].addCard(Card((Rank) i, (Suit) j));
      }
    }
 
  REQUIRE(set2.winningGame() == true);
  }

  SECTION( "No Valid Moves" ){
  }

}