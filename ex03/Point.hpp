#ifndef __POINT_HPP__
# define __POINT_HPP__

# include "Fixed.hpp"

class Point
{
	private:
		Fixed _x;
		Fixed _y;

	public:
		Point(void);
		Point(Point &to_copy);
		Point(Fixed const x, Fixed const y);
		~Point(void);

		Point &Point::operator=(Point const &rhs);
};

#endif