#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
		Fixed const angle;
	public:
		 Point();
		 Point(const float x, const float y);
		 Point(Point const &other);
		 Point& operator=(Point const &other);
		 Fixed getx() const;
		 Fixed gety() const;
		 Fixed getangle() const;
		 void setagle(Fixed angle);
		 ~Point();		
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
