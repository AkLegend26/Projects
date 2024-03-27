// File name: Point.h
// Author: CS2201 Instructor
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: PA 7
// Description:  Represent a point via x & y coordinates.
// Last Changed: 8-4-2009

#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
public:
	int x;
	int y;

	// Class Constructor
	// post: Initializes x and y to zero
	Point();

	// Class Constructor
	// post: Initializes x and y
	Point(int x,int y);


	// Equality operators
	bool operator== (const Point& rhs) const;
	bool operator!= (const Point& rhs) const;

};

// insertion operator for output
std::ostream& operator<< (std::ostream& os, const Point &p);

#endif
