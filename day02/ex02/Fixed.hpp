#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &);
	Fixed operator=(const Fixed &);
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed(const int points);
	Fixed(const float points);
	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs);
	bool operator<=(const Fixed &rhs);
	bool operator==(const Fixed &rhs);
	bool operator!=(const Fixed &rhs);
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

private:
	int _fixed;
	static const int _bits = 8;
};

std::ostream& operator<<(std::ostream& ostream, const Fixed &fixed);

Fixed &min(Fixed &, Fixed &);
const Fixed &min(const Fixed &, const Fixed &);
Fixed &max(Fixed &, Fixed &);
const Fixed &max(const Fixed &, const Fixed &);


#endif
