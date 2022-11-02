#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(int const nb);
		Fixed(float const nb);
		Fixed(Fixed &to_copy);

		Fixed &operator=(Fixed &to_copy);

		int toInt(void) const;
		int getRawBits(void) const;
		float toFloat(void) const;
		void setRawBits(int const raw);

	private:
		int	_nb;
		static int const _bits = 8;
};

#endif