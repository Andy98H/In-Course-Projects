/**
 * \author Andy Hameed | 400073469
 *  \file Tableau.h
 *  \brief Representing one of eight tableau piles
 */


#ifndef TABLEAU_H
#define TABLEAU_H

#include <vector>

using namespace std;


/**
 *  \brief Class representing a Tableau pile in freecell
 *  \details where each card  
 */
class Tableau{
private:
	//vector allows for easy add remove functionaity and obtaining size
	vector<Card> tab;
public:

	/**
	* \brief Constructor for Tableau
	* \details creates a tableau based on 
	* an input vector of cards
	* \param s a vector of 6 or 7 cards
	*
	*/
	Tableau(vector<Card> s);
	Tableau();

	/**
	* \brief Adds card c to the tableau pile at hand
	* \param c card being added to the pile
	*
	*/
	void addCard(Card c);

	/**
	* \brief Removes top card from the current pile
	*
	*/
	void removeCard();

	/**
	* \brief Extracts top card from pile
	* \return Card object with the attributes of the card
	*
	*/
	Card topCard();

};

#endif