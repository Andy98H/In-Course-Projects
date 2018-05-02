/**
 *  \file PathADT.h
 *  \brief Representing a Line as an ADT
 */


#ifndef PATHADT_H
#define PATHADT_H

#include <vector>
#include "PointADT.h"
#include "MapTypes.h"
#include "LineADT.h"

/**
 *  \brief Class representing a path in the 2D plane
 *  \details Comprised of lines 
 */
class PathT{
	private:
		///sequence of lines forming path
		std::vector<LineT> s;

		/**
	 	*  \brief local function for finding adjacent point to a line
	 	*  \param ornt orientation of the current line
	 	*  \return a starting point adjacent to previous line
	 	*/	
		PointT adjPt(CompassT ornt);

		/**
	 	*  \brief local function for finding points in a line
	 	*  \param l line being examined for its points
	 	*  \return vector containing all points in line l
	 	*/	
		std::vector<PointT> pointsInLine(LineT l);

	public:
		/**
	 	*  \brief Constructor for a path data type
	 	*  \param st sets the start point for path
	 	*  \param ornt sets the orientation of the path
	 	*  \param l sets the length of the path
	 	*/	
		PathT(PointT st,CompassT ornt, int l);


		/**
	 	*  \brief appends line to the path
	 	*  \param ornt the orientation of the appended path
	 	*  \param l length of the appended line
	 	*/
		void append(CompassT ornt, int l);


		/**
	 	*  \brief Accessor for start point 
	 	*  \returns start point for path
	 	*/
		PointT strt();

		/**
	 	*  \brief Accessor for end point 
	 	*  \returns end point for path
	 	*/
		PointT end();

		/**
	 	*  \brief finds line i in the path
	 	*  \param i index of line in path
	 	*  \return line being searched for, as a separate line object 
	 	*/
		LineT line(int i);

		/**
	 	*  \brief Accessor for number of lines in path 
	 	*  \returns size of path as a count of lines
	 	*/
		int size();

		/**
	 	*  \brief Accessor for length of path 
	 	*  \returns length path
	 	*/
		int len();

		/**
	 	*  \brief translates path in the x and y direction
	 	*  \param x horizontal translation
	 	*  \param y vertical translation 
	 	*  \returns path object after translation by x and y  
	 	*/
		PathT translate(int dx, int dy);
};

#endif