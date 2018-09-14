
/**
 * \author Andy Hameed | 400073469
 *  \file FreeCell.h
 *  \brief Representing one of four free cells
 */


#ifndef FREECELL_H
#define FREECELL_H

#include <vector>

/**
 *  \brief Class representing the free cells in a FreeCell game
 */
class FreeCell{
private:
	std::vector<Card> cells;
public:
	/**
	* \brief constructor for FreeCell
	*
	*/
	FreeCell();

	/**
	* \brief returns true if full, otehrwise false
	* \return true if all four cells are taken
	*
	*/
	bool isFull();

	/**
	* \brief search for the card with the matching suit and rank
	* \param rank rank of card being moved 
	* \param suit suit of card being moved 
	*
	*/
	Card searchCard(Rank rank, Suit suit);
	
	/**
	* \brief move card back to tableau or foundation
	* \param c card being added to free cells pile
	*
	*/
	void addCard(Card c);

	/**
	* \brief remove card from free cells
	* \param rank rank of card being moved 
	* \param suit suit of card being moved  
	*
	*/
	void removeCard(Rank rank, Suit suit);

};

#endif