/** \author Andy Hameed | 400073469
 *  \file CardADT.h
 *  \brief Representing a playing card as an ADT
 *  \details along with enume types for card attributes
 */


#ifndef CARDADT_H
#define CARDADT_H


/// enum type for card suits in the order Clubs, Diamonds, spades and hearts respectively
enum Suit{C, D, S, H};
/// enum type for card suit colour
enum Colour{Red, Black};
/// enum type for card rank or value
enum Rank{Empty,ace, two, three, four, five, six, seven , eight, nine, ten, jack, queen, king};

/**
 *  \brief Class representing a playing card
 *  \details of a specific suit and rank. Colour is determined by suit
 */
class Card{
private:
	/// value of the card
	Rank rank; 
	/// suit is determined by wether it is a spade, club, heart or diamond
	Suit suit; 
	///Red of Black card
	Colour colour;

public:

	/**
 	*  \brief Constructor for the Card data type
 	*  \param rank rank or value of card
 	*  \param suit suit of card, one of the four suits 
 	*/	
	Card(Rank rank, Suit suit);

	///creating constructor without parameter to dodge initialization 
	Card();

	/**
 	*  \brief returns the colour of the card
 	*  \return red or black depending on suit 
 	*/	
	Colour getColour();


	/**
 	*  \brief returns rank of the card object 
 	*  \return rank of card 
 	*/	
	Rank getRank();


	/**
 	*  \brief returns suit of card
 	*  \return suit of the card
 	*/	
	Suit getSuit();
};

#endif