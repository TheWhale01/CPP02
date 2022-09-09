#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <cmath>
#include <iostream>

class Fixed {
	public:
		Fixed( void );
		Fixed( Fixed const &to_copy );
		Fixed( int const nb );
		Fixed( float const nb );
		~Fixed( void );

		Fixed & operator=(Fixed const & rhs);

		int		toInt(void) const;
		int		getRawBits(void) const;

		void	setRawBits(int const raw);

		float	toFloat(void)const;

	private:
		int					_int;
		static int const	_nbdigits = 8;
};

std::ostream & operator<<( std::ostream & stream, Fixed const & rhs);

#endif