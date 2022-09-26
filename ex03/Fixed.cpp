#include "Fixed.hpp"

Fixed::Fixed( void ) : _int(0)
{
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const nb) : _int(nb << this->_nbdigits)
{
	// std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const nb) : _int(roundf(nb * (1 << this->_nbdigits)))
{
	// std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const &to_copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
	return ;
}

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

/*	---------- OPERATOR OVERLOAD ---------- */

bool Fixed::operator>(Fixed const & rhs) const
{
	return (this->_int > rhs._int);
}

bool Fixed::operator<(Fixed const & rhs) const
{
	return (this->_int < rhs._int);
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_int <= rhs._int);
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_int >= rhs._int);
}

bool Fixed::operator==(Fixed const & rhs) const
{
	return (this->_int == rhs._int);
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_int != rhs._int);
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

Fixed& Fixed::operator=(Fixed const & rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_int = rhs.getRawBits();
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	++(*this);
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	--(*this);
	return (tmp);
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

std::ostream & operator<<(std::ostream &stream, Fixed const &rhs)
{
	stream << rhs.toFloat();
	return (stream);
}

/* ---------- FUNCTION MEMBERS ---------- */

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

Fixed Fixed::max(Fixed& nb1, Fixed& nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}

Fixed Fixed::min(Fixed& nb1, Fixed& nb2)
{
	if (nb1 <= nb2)
		return (nb1);
	return (nb2);
}

Fixed const Fixed::max(Fixed const & nb1, Fixed const & nb2)
{
	if (nb1 >= nb2)
		return (nb1);
	return (nb2);
}

Fixed const Fixed::min(Fixed const & nb1, Fixed const & nb2)
{
	if (nb1 <= nb2)
		return (nb1);
	return (nb2);
}