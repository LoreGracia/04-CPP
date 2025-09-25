#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class	Fixed
{	
	private:
		int	fixed;
		static int const bits = 8;
	public:
		Fixed();
		Fixed(Fixed &other);
		Fixed &operator=(const Fixed &other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
};
#endif
