#include "Point.hpp"

Fixed sign(Point const &a, Point const &b, Point const &c)
{
	return ((a.getx() - c.getx()) * (b.gety() - c.gety()) - (b.getx() - c.getx()) * (a.gety() - c.gety()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if ((point.getx() == a.getx() && point.gety() == a.gety()) ||
		(point.getx() == b.getx() && point.gety() == b.gety()) ||
		(point.getx() == c.getx() && point.gety() == c.gety()))
		return false;
	Fixed d1 = sign(point, a, b);
	Fixed d2 = sign(point, b, c);
	Fixed d3 = sign(point, c, a);

	bool neg = d1 < 0 || d2 < 0 || d3 < 0;
	bool pos = d1 > 0 || d2 > 0 || d3 > 0;
	return !(neg && pos);
}
