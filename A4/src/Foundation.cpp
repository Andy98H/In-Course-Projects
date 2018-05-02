
#include <iostream>

#include "../include/CardADT.h"
#include "../include/Foundation.h"
#include "../include/Exceptions.h"

using namespace std;

Foundation::Foundation(Suit suit){
	this->suit = suit;
}

Foundation::Foundation(){}

void Foundation::addCard(Card c){

	
	// placing ace into foundation pile
	if (this->pile.empty() && c.getRank() == 1)
		this->pile.push_back(c);

	//Appended card is not of same suit or has an incrorrect rank
	else if(c.getSuit() != this->suit || c.getRank() != this->pile.back().getRank() + 1)
		throw invalid_move();
	else if(c.getRank() == this->pile.back().getRank() + 1)
		this->pile.push_back(c);

}

void Foundation::removeCard(){
	if (this->pile.empty())
		throw not_available();

	this->pile.pop_back();
}

Suit Foundation::getSuit(){
	return this->suit;

}

bool Foundation::isFull(){
	///Foundation pile is complete with 13 cards
	if (this->pile.size() == 13)
		return true;
	return false;
}

Card Foundation::topCard(){
	if (this->pile.empty())
		throw not_available();

	//last element in the vector
	return this->pile.back();
}

/*int main(){
	cout << "Good Job!" << endl;

	return 0;
}
*/






