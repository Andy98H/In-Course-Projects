/**
 * \author Andy Hameed | 400073469
 *  \file Setup.h
 *  \brief Representing the setup of the board and methods
 *  \details for changing the game state
 */


#ifndef SETUP_H
#define SETUP_H

#include <vector>


class Setup{
public:

	/// 8 tableau piles
	Tableau board[8];
	/// 4 foundation piles
	Foundation founds[4];
	/// 4 free cells 
	FreeCell free;


	/**
	* Randomly constructs the initial state of the tableau piles and 
	* initializes freecells and foundation piles
	*
	*/
	Setup();

	/**
	* For manual set up of cards into tableaus
	*
	*/
	Setup(vector< vector<Card> > s);

	/** \brief moves card from the free cells to a teableau pile
	*  \param rank rank of card being moved 
	*  \param suit suit of card being moved 
	*  \param to index of tableau pile beng moved to
	*
	*/
	void freeToTab(Rank rank, Suit suit, int to);	

	/** \brief moves card from the Tableau "from" to the tableau "to"
	*  \param from pile from which a card is being moved
	*  \param to pile where card is dropped or appended
	*/
	void tabToTab(int from, int to);

	/** \brief moves card from the Tableau "from" to the foundation
	*  \param from pile from which a card is being moved to a free cell
	*
	*/
	void tabToFound(int from);

	/** \brief moves card from the Tableau "from" to a free cell 
	*  \param from pile from which a card is being moved to foundation
	*
	*/
	void tabToFree(int from);

	/** \brief moves card from the free cells to foundation pile 
	*  \param rank rank of card being moved 
	*  \param suit suit of card being moved 
	*
	*/
	void freeToFound(Rank rank, Suit suit);

	/** \brief moves top card from a foundation pile to tableau pile 
	*  \param suit suit of card being moved 
	*  \param to pile to which it is being moved
	*/
	void foundToTab(Suit suit, int to);

	/** \brief returns top cards on the tableau 
	*/
	void tabTopCards();

	/*
	*  \brief returns true if wnning game is present
	*/
	bool winningGame();

};

#endif