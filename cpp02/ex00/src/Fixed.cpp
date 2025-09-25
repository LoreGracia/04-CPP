#include "Fixed.hpp"

Fixed::Fixed()
	:fixed(0)
{
	std::cout << "\033[34mDefault constructor called\033[0m" << std::endl;
}

Fixed::Fixed(Fixed &other)
	:fixed(other.getRawBits())
{
	std::cout << "\033[34mCopy of Fixed created\033[0m" << std::endl;
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

Fixed::~Fixed()
{
	std::cout << "\033[34mDestructor called\033[0m" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "\033[34mgetRawBits member function called\033[0m" << std::endl;
	return (this->fixed);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "\033[34msetRawBits member fucntion called\033[0m" << std::endl;
	this->fixed = raw;
}
