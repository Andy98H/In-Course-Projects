
#include <algorithm>
#include "../include/CardADT.h"
#include "../include/FreeCell.h"
#include "../include/Tableau.h"
#include "../include/Foundation.h"
#include "../include/Setup.h"
#include "../include/Exceptions.h"

#include <vector>

#include <iostream>

#include <assert.h>

Setup::Setup(vector< vector<Card> > s){

	///	load tableau
	for (int i = 0; i < 8; i++){
		this->board[i] = s.at(i);
	}
	
    /// generate foundation piles based on their suit i   
    for (int i = 0; i < 4; i++){
		this->founds[i] = Foundation((Suit) i);
	}

}


Setup::Setup(){

	//avoids appending same cards
	int k = 0;
	vector<Card> Deck;
	vector<Card> tmp;
	vector< vector<Card> > s;

	for (int i = 0; i < 4 ; i++){
		for (int j = 1; j < 14 ; j++){ // since 0 is the empty card
			//add Card with suit i and rank j to the deck  
			Deck.push_back(Card((Rank) j, (Suit) i));
		}
	}

	//shuffle the deck of cards
	std::random_shuffle(Deck.begin(), Deck.end());

	//Generate first 4 tableau piles of 7 cards
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 7 ; j++){
			tmp.push_back(Deck.at(k++));
		}
		s.push_back(tmp);
		//clear vector for new cards
		tmp.clear();
	}

	//last 4 tableau piles of 6 cards
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 6 ; j++){
			tmp.push_back(Deck.at(k++));
		}
		s.push_back(tmp);
		//clear vector for new cards
		tmp.clear();
	}

	///	load tableau
	for (int i = 0; i < 8; i++){
		this->board[i] = s[i];
	}

    /// generate foundation piles based on their suit i   
    for (int i = 0; i < 4; i++){
		this->founds[i] = Foundation((Suit) i);
	}

}

void Setup::tabToTab(int from, int to){

	this->board[to].addCard(this->board[from].topCard()); 

	//remove card since no longer in this pile
	this->board[from].removeCard();
}


void Setup::tabToFound(int from){
	int temp = (int) this->board[from].topCard().getSuit();
	this->founds[temp].addCard(this->board[from].topCard());
	this->board[from].removeCard();
}

void Setup::freeToTab(Rank rank, Suit suit, int to){

	//add the card to tableau
	this->board[to].addCard(this->free.searchCard(rank,suit));
	//remove from free pile
	this->free.removeCard(rank,suit);
	
	}

void Setup::tabToFree(int from){
	if(this->free.isFull()){
		throw full();}

	free.addCard(this->board[from].topCard());
	this->board[from].removeCard();
}

void Setup::freeToFound(Rank rank, Suit suit){


	founds[suit].addCard(this->free.searchCard(rank,suit));
	free.removeCard(rank,suit);
}

void Setup::foundToTab(Suit suit, int to){
	for (int i = 0; i < 4; i++){
		if (founds[i].getSuit() == suit){
			this->board[to].addCard(founds[i].topCard());
			founds[i].removeCard();
		}
	}	
}


void Setup::tabTopCards(){
	cout << "Your Tableau Top Cards: " << endl;

	for (int i = 0; i < 8; i++){
		cout << "Col " << i << "     " << "Rank " << this->board[i].topCard().getRank()
		<< " Suit " << this->board[i].topCard().getSuit() <<
		" Colour " << this->board[i].topCard().getColour() << endl;
	}	
}

bool Setup::winningGame(){
	bool temp = true;	
	for (int i = 0; i < 4 ; i++)
		if (!this->founds[i].isFull())
			temp = false;

	return temp;
}

/*
bool Setup::noValidMoves(){
	
}



*/