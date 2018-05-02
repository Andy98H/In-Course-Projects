#include <iostream>


#include "../include/CardADT.h"


using namespace std;

Card::Card(Rank rank, Suit suit){
	this->rank = rank;
	this->suit = suit;

	//if Diamond or Hearts, set the colour to red, else black
	if (suit == D || suit == H)
		this->colour = Red;

	else
		this->colour = Black;
}

Card::Card(){}

Rank Card::getRank(){
	return this->rank;
}


Suit Card::getSuit(){
	return this->suit;
}


Colour Card::getColour(){
	return this->colour;
}
/*
int main(){
	Card c(four, D);
	//how do I compare to enum type??
	cout << c.getRank()  << endl;
	cout << c.getSuit()  << endl;
	cout << c.getColour()  << endl; //0 since Diamond is red and red comes first in Colour 



	return 0;

}*/