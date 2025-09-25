#include "Fixed.hpp"

Fixed::Fixed()
	:fixed(0)
{;}

int Fixed::toInt( void ) const { return (static_cast<int>(roundf(this->toFloat()))); }

Fixed::Fixed(int const fixed)
	:fixed(fixed * (1 << this->bits))
{;}

float Fixed::toFloat( void ) const { return (static_cast<float>(this->fixed / static_cast<float>(1 << this->bits))); }

Fixed::Fixed(float const fixed)
	: fixed(roundf(fixed * (1 << this->bits)))
{;}

Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed& Fixed::operator=(const Fixed &other)
{
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

bool Fixed::operator<(const Fixed &other) { return (this->fixed < other.fixed ? true : false); }
bool Fixed::operator>(const Fixed &other) { return (this->fixed > other.fixed ? true : false); }
bool Fixed::operator>=(const Fixed &other) { return (this->fixed >= other.fixed ? true : false); }
bool Fixed::operator<=(const Fixed &other) { return (this->fixed <= other.fixed ? true : false); }
bool Fixed::operator==(const Fixed &other) { return (this->fixed == other.fixed ? true : false); }
bool Fixed::operator!=(const Fixed &other) { return (this->fixed != other.fixed ? true : false); }
Fixed Fixed::operator*(const Fixed &other) { return (Fixed(this->toFloat() * other.toFloat())); }
Fixed Fixed::operator+(const Fixed &other) { return (Fixed(this->toFloat() + other.toFloat())); }
Fixed Fixed::operator-(const Fixed &other) { return (Fixed(this->toFloat() - other.toFloat())); }
Fixed Fixed::operator/(const Fixed &other) { return (Fixed(this->toFloat() / other.toFloat())); }
Fixed& Fixed::operator++() { return (this->fixed++, *this); }
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++this->fixed;
	return (tmp);
}
Fixed& Fixed::operator--() { return (this->fixed--, *this); }
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--this->fixed;
	return (tmp);
}
Fixed Fixed::min(Fixed& a, Fixed& b) { return (a > b ? b : a); }
Fixed Fixed::min(const Fixed& a, const Fixed& b) { return (a.getRawBits() > b.getRawBits() ? b : a); }
Fixed Fixed::max(Fixed& a, Fixed& b) { return (a < b ? b : a); }
Fixed Fixed::max(const Fixed& a, const Fixed& b) { return (a.getRawBits() < b.getRawBits() ? b : a); }

Fixed::~Fixed() { ; }

int Fixed::getRawBits( void ) const { return (this->fixed); }

void Fixed::setRawBits( int const raw ) { this->fixed = raw; }
