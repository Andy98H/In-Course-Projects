/**
 *  \file PointADT.h
 *  \brief Representing a point as an ADT
 */

#ifndef POINTADT_H
#define POINTADT_H


/**
 *  \brief Class representing a point in the 2D plane
 *  \details Coordinates are integer values
 */
class PointT{
	private:
		/// x-coordinate
		int xc;
		/// y-coordinate
		int yc;

	public:

	/**
 	*  \brief Constructor for a point data type
 	*  \param x x-coordinate for point
 	*  \param y y-coordinate for point
 	*/	
	PointT(int x, int y);

	/**
 	*  \brief gives x-value of point
 	*  \return x-coordinate for point object
 	*/	
	int x();

	/**
 	*  \brief gives y-value of point
 	*  \return y-coordinate for point object
 	*/	
	int y();

	/**
 	*  \brief translates point to new position
 	*  \param x change in x position dx
 	*  \param y change in y position dy
 	*  \return A point object after translation 
 	*/	
	PointT translate(int x, int y);

};

#endif 