/**
 *  \file MapTypes.h
 *  \brief Representing compass directions, land categories, and rotations
 *	\details as enumerated types 
 */


#ifndef MAPTYPES_H
#define MAPTYPES_H


/// enum type for compass directions
enum CompassT{N,S,E,W};

/// enum type for landuse categories
enum LanduseT{Recreational,Transport, Agricultural, Residential, Commercial};

/// enum type for clockwise and counterclockwise rotation
enum RotateT{CW, CCW};

#endif 
