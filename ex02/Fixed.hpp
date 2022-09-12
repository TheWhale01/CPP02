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
		Fixed & operator>(Fixed const & rhs) const ;
		Fixed & operator<(Fixed const & rhs) const ;
		Fixed & operator>=(Fixed const & rhs) const ;
		Fixed & operator<=(Fixed const & rhs) const ;
		Fixed & operator==(Fixed const & rhs) const ;
		Fixed & operator!=(Fixed const & rhs) const ;

		Fixed operator+(Fixed const & rhs);
		Fixed operator-(Fixed const & rhs);
		Fixed operator*(Fixed const & rhs);
		Fixed operator/(Fixed const & rhs);

		Fixed & operator++(void);
		Fixed & operator--(void);
		Fixed operator++(int n);
		Fixed operator--(int n);

		int			toInt(void) const;
		int			getRawBits(void) const;

		void		setRawBits(int const raw);

		float		toFloat(void)const;

		static int	min(Fixed & nb1, Fixed & nb2);
		static int	max(Fixed & nb1, Fixed & nb2);
		static int	min(Fixed const & nb1, Fixed const & nb2);	
		static int	max(Fixed const & nb1, Fixed const & nb2);

	private:
		int					_int;
		static int const	_nbdigits = 8;
};

std::ostream & operator<<( std::ostream & stream, Fixed const & rhs);

#endif