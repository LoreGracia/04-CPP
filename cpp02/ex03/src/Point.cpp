#include "Point.hpp"

Point::Point()
	:x(0), y(0), angle(0)
{}

Point::Point(const float x, const float y)
	:x(x), y(y), angle(0)
{
}

Point::Point(Point const &other): x(other.x), y(other.y){
}

Fixed	Point::getx() const { return (this->x); }
Fixed	Point::gety() const { return (this->y); }
Fixed	Point::getangle() const { return (this->angle); }

Point& Point::operator=(Point const &other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{}
