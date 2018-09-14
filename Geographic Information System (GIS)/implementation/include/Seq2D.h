/**
 *  \file Seq2D.h
 *  \brief Representing a Geographic Map as an ADT
 */

#ifndef SEQ2D_H
#define SEQ2D_H

#include <vector>
#include "PointADT.h"
#include "MapTypes.h"
#include "LineADT.h"
#include "PathADT.h"

/**
 *  \brief Class representing a map as a 2D sequence of type T  
 */
template <class T>
class Seq2D{
private:

	///2D sequence of rows and columns for elements of type T 
	std::vector< std::vector<T> > s;

	///scale of map as a real number
	double scale;

	///number of rows in 2D sequence
	int nRow;

	///number of columns in 2D sequence
	int nCol;

	bool check = false;

	std::vector<PointT> checked;

	//local functions

	/**
 	*  \brief Checks if row is in bounds
 	*  \param i ith row in the sequence
 	*  \return boolean for in or out of bounds
 	*/	
	bool validRow(int i);

	/**
 	*  \brief Checks if column is in bounds
 	*  \param j jth column in the sequence
 	*  \return boolean for in or out of bounds
 	*/	
	bool validCol(int j);

	/**
 	*  \brief Checks if point is in bounds
 	*  \param p point being checked for
 	*  \return boolean for in or out of bounds
 	*/
	bool validPoint(PointT p);

	/**
 	*  \brief Checks if line is in bounds
 	*  \param l line being checked for
 	*  \return boolean for in or out of bounds
 	*/
	bool validLine(LineT l);

	/**
 	*  \brief Checks if path is in bounds
 	*  \param pth path being checked for
 	*  \return boolean for in or out of bounds
 	*/
	bool validPath(PathT pth);

	/**
 	*  \brief  gives all points in a line l
 	*  \param l the line being inputted
 	*  \return vector of all points in l
 	*/
	std::vector<PointT> pointsInLine(LineT l);

	/**
 	*  \brief  gives all points in a path p
 	*  \param p the path being inputted
 	*  \return vector of all points in p
 	*/
	std::vector<PointT> pointsInPath(PathT p);

	bool pointChecked(PointT x);

	bool PointsAdjacent(PointT p1,PointT p2);

public:
	/**
 	*  \brief  Constructor for the 2D Sequence
 	*  \param S 2D sequence for the map
 	*  \param scl sclae of the map
 	*/
	Seq2D(std::vector< std::vector<T> > S, double scl);

	/**
 	*  \brief sets the value at point p to v
 	*  \param p point on the map
 	*  \param v value being assigned
 	*/
	void set(PointT p, T v);

	/**
 	*  \brief gets the value at point p
 	*  \param p point on the map
 	*  \return a value of type T
 	*/
	T get(PointT p);

	/**
 	*  \brief gets the number of rows in the map
 	*  \return number of rows 
 	*/
	int getNumRow();

	/**
 	*  \brief gets the number of columns in the map
 	*  \return number of columns 
 	*/
	int getNumCol();

	/**
 	*  \brief gets the scale being used for the map
 	*  \return scale as a real number
 	*/
	double getScale();

	/**
 	*  \brief counts the number of times t occurs
 	*  \details in the map as a value
 	*  \param t value being searched for
 	*  \return a count of occurences
 	*/
	int count(T t);

	/**
 	*  \brief counts the number of times t occurs
 	*  \details in a line as a value
 	*  \param t value being searched for
 	*  \param l line being searched
 	*  \return a count of occurences
 	*/
	int count(LineT l, T t);

	/**
 	*  \brief counts the number of times t occurs
 	*  \details in a path as a value
 	*  \param pth path being searched
 	*  \param t value being searched for
 	*  \return a count of occurences
 	*/
	int count(PathT pth, T t);

	/**
 	*  \brief takes the length of a path
 	*  \param pth path being searched
 	*  \return length based on the scale
 	*/
	double length(PathT pth);

	/**
 	*  \brief finds wether a path exists
 	*  \details between two points 
 	*  \details where all values are the same in the path
 	*  \param p1 first point
 	*  \param p2 second point
 	*  \return boolean value of whether such path exists
 	*/
	bool connected(PointT p1, PointT p2);
	


};

#endif