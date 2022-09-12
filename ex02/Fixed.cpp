#include "Fixed.hpp"

Fixed::Fixed( void ) : _int(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const nb) : _int(nb << this->_nbdigits)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const nb) : _int(roundf(nb * (1 << this->_nbdigits)))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
	return ;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_int = rhs.getRawBits();
	return (*this);
}

Fixed & Fixed::operator++(void)
{
	++(this->_int);
	return (*this);
}

Fixed & Fixed::operator--(void)
{
	--(this->_int);
	return (*this);
}

Fixed Fixed::operator++(int n)
{
	Fixed tmp(*this);

	if (n >= 0)
		for (int i = 0; i < n; i++)
			++(*this);
	else
		for (int i = 0; i <= (-n); i++)
			--(*this);
	return (tmp);
}

Fixed Fixed::operator--(int n)
{
	Fixed tmp(*this);

	if (n >= 0)
		for (int i = 0; i <= n; i++)
			++(*this);
	else
		for (int i = 0; i <= (-n); i++)
			--(*this);
	return (tmp);
}

int	Fixed::getRawBits(void) const
{
	return (this->_int);
}

void Fixed::setRawBits(int const raw)
{
	this->_int = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_int / (1 << this->_nbdigits));
}

int Fixed::toInt(void) const
{
	return ((int)(roundf((float)this->_int / (1 << this->_nbdigits))));
}


std::ostream & operator<<(std::ostream &stream, Fixed const &rhs)
{
	stream << rhs.toFloat();
	return (stream);
}