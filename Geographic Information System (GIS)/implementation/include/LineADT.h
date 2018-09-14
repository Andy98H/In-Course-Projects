/**
 *  \file LineADT.h
 *  \brief Representing a Line as an ADT
 */

#ifndef LINEADT_H
#define LINEADT_H

#include "PointADT.h"
#include "MapTypes.h"

/**
 *  \brief Class representing a line in the 2D plane
 *  \details Comprised of points defined by PointADT
 */
class LineT{
	private:
		/// starting point 
		PointT s;
		/// orientation of line
		CompassT o;
		/// Length of line
		int L;

	public:

		/**
	 	*  \brief Constructor for a line data type
	 	*  \param st sets the start point for line
	 	*  \param ornt sets the orientation of the line
	 	*  \param l sets the length of the line
	 	*/	
		LineT(PointT st, CompassT ornt, int l);

		/**
	 	*  \brief Accessor for start point 
	 	*  \returns start point for line
	 	*/
		PointT strt();

		/**
	 	*  \brief Accessor for end point 
	 	*  \returns end point for line
	 	*/
		PointT end();


		/**
	 	*  \brief Accessor for orientation of line 
	 	*  \returns orientation of line in 2D space
	 	*/
		CompassT orient();


		/**
	 	*  \brief Accessor for length of line 
	 	*  \returns length line
	 	*/
		int len();


		/**
	 	*  \brief flips the line object to face opposite direction 
	 	*  \returns line facing opposite direction with the same length and start point
	 	*/
		LineT flip();


		/**
	 	*  \brief Rotates line clockwise or counterclockwise 
	 	*  \returns line object rotated 90 degrees CW or CCW with the same length and start point
	 	*/
		LineT rotate(RotateT);
		
		/**
	 	*  \brief translates line in the x and y direction
	 	*  \param x horizontal translation
	 	*  \param y vertical translation 
	 	*  \returns line object after translation by x and y  
	 	*/
		LineT translate(int x, int y);

};

#endif