#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

class Fixed {
	public:
		Fixed( void );
		Fixed( Fixed const &to_copy );
		~Fixed( void );

		Fixed & operator=(Fixed const & rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_int;
		static int const	_nbdigits = 8;
};

#endif