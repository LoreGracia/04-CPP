#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class	Fixed
{	
	private:
		int	fixed;
		static int const bits = 8;
	public:
		Fixed();
		Fixed(int const fixed);
		Fixed(float const fixed);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		bool operator<(const Fixed &other);
		bool operator>(const Fixed &other);
		bool operator>=(const Fixed &other);
		bool operator<=(const Fixed &other);
		bool operator==(const Fixed &other);
		bool operator!=(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator/(const Fixed &other);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		static Fixed min(Fixed& a, Fixed& b);
		static Fixed min(const Fixed& a, const Fixed& b);
		static Fixed max(Fixed& a, Fixed& b);
		static Fixed max(const Fixed& a, const Fixed& b);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
		int toInt( void ) const;
		float toFloat( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
