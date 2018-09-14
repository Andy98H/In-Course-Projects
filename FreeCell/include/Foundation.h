/**
 * \author Andy Hameed | 400073469
 *  \file Foundation.h
 *  \brief Representing one of four foundation piles
 *  \details one for each suit
 */


#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <vector>

using namespace std;

/**
 *  \brief Class representing a Foundation pile in freecell
 *  \details that accepts a specific suit of cards 
 */
class Foundation{
private:
	/// One pile of foundation cards
	vector<Card> pile;
	///suit associated with the pile
	Suit suit;
public:

	/**
 	*  \brief Constructor for a single foundation pile
 	*  \param suit suit of the cards belonging to the pile 
 	*/	
	Foundation(Suit suit);
	Foundation();

	/**
	*  \brief method for adding card onto foundation pile 
	*  \param c card being added to the pile
	*/
	void addCard(Card c);

	/**
	*  \brief method for removing top card from foundation pile 
	*/
	void removeCard();

	/**
	*  \brief checks if foundation pile is complete
	*  \return true if full, false otherwise
	*/
	bool isFull();

	/**
	*  \brief gets the suit of the foundation
	*/
	Suit getSuit();

	/**
	*  \brief gets the top card from the pile
	*/
	Card topCard();


};

#endif