
#include "../include/CardADT.h"
#include "../include/Exceptions.h"
#include "../include/Tableau.h"
#include <vector>

using namespace std;

Tableau::Tableau(vector<Card> s){

	this->tab = s;
}

Tableau::Tableau(){
}


void Tableau::addCard(Card c){
	
	// the tableau is empty
	if (this->tab.empty())
		this->tab.push_back(c);

	// the appended card is one less than current and has opposite colour
	if (c.getRank() + 1 == this->tab.back().getRank()
		&& c.getColour() != this->tab.back().getColour() ){
		this->tab.push_back(c);
	}
	else 
		throw invalid_move();
}

void Tableau::removeCard(){
	
	if (this->tab.empty())
		throw not_available();
	
	this->tab.pop_back();
}

Card Tableau::topCard(){
	if (this->tab.empty()){
		throw not_available();
	}
	
	return this->tab.back();
}

