#include "Point.hpp"

Point::Point(void)
{
	this->_x = 0;
	this->_y = 0;
	return ;
}

Point::Point(Point &to_copy)
{
	*this = to_copy;
	return ;
}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y)
{
	return ;
}

Point::~Point(void)
{
	return ;
}

/* ---------- OPERATOR OVERLOAD ---------- */

Point &Point::operator=(Point const &rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	return (*this);
}