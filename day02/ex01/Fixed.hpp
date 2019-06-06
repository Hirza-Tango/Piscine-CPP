#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
public:
	Fixed();
	~Fixed();
	Fixed(const int points);
	Fixed(const float points);
	Fixed(const Fixed &);
	Fixed& operator=(const Fixed &);
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;
private:
	int _fixed;
	static const int _bits = 8;
};

std::ostream& operator<<(std::ostream& ostream, const Fixed &fixed);

#endif
