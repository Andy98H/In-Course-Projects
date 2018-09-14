
#include <iostream>

#include "../include/CardADT.h"
#include "../include/FreeCell.h"
#include "../include/Exceptions.h"

FreeCell::FreeCell(){
}



void FreeCell::addCard(Card c){
	if (isFull()){
		throw full();
	}
	this->cells.push_back(c);
}

Card FreeCell::searchCard(Rank rank, Suit suit){
	for (int i = 0; i < 4 ; i++){
		//count the number of free spots
		if (rank == this->cells[i].getRank() && suit == this->cells[i].getSuit())
			return this->cells.at(i);
	}

	throw not_available();

}


void FreeCell::removeCard(Rank rank, Suit suit){
	//index initially set not to exist
	int index = -1;

	for (int i = 0; i < 4 ; i++){
		//find the index under these conditions
		if (rank == this->cells[i].getRank() && suit == this->cells[i].getSuit())
			 index = i;
	}	
	
	//index was not found, throw error
	if (index < 0)
		throw not_available();

	//delete thr card from free cells
	this->cells.erase(this->cells.begin() + index);		
}


bool FreeCell::isFull(){
	//only 4 free cells available
	return (this->cells.size() >= 4); 
}

/*int main(){
	FreeCell free = FreeCell();
	Card c(four, S);

	free.addCard(c);
	free.addCard(Card(nine, H));
	free.addCard(Card(six, C));

	cout << free.searchCard(nine, H).getSuit() << endl;
	free.removeCard(four, S);
	free.searchCard(four, S);

	cout << !free.isFull() << endl;

	return 0;

}*/


