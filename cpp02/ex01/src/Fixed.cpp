#include "Fixed.hpp"

Fixed::Fixed()
	:fixed(0)
{
	std::cout << "\033[34mDefault constructor called\033[0m" << std::endl;
}

int Fixed::toInt( void ) const
{
	return (static_cast<int>(roundf(this->toFloat())));
}

Fixed::Fixed(int const fixed)
	:fixed(fixed * (1 << this->bits))
{
	std::cout << "\033[34mInt constructor called\033[0m" << std::endl;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->fixed / static_cast<float>(1 << this->bits)));
}

Fixed::Fixed(float const fixed)
	: fixed(roundf(fixed * (1 << this->bits)))
{
	std::cout << "\033[34mFloat constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "\033[34mCopy of Fixed created\033[0m" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "\033[34mCopy assigment operator called\033[0m" << std::endl;
	if (this != &other)
	{
            fixed = other.getRawBits();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat() << std::flush;
	return (out);
}

Fixed::~Fixed()
{
	std::cout << "\033[34mDestructor called\033[0m" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (this->fixed);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "\033[34msetRawBits member fucntion called\033[0m" << std::endl;
	this->fixed = raw;
}
