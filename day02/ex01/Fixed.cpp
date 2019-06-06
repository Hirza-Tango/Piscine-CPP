#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(){
	_fixed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &orig){
	std::cout << "Copy constructor called" << std::endl;
	*this = orig;
}

Fixed& Fixed::operator=(const Fixed &orig){
	std::cout << "Assignment constructor called" << std::endl;
	this->_fixed = orig._fixed;
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	_fixed = raw;
}

Fixed::Fixed(int points){
	std::cout << "Int constructor called" << std::endl;
	_fixed = points << _bits;
}

Fixed::Fixed(float points){
	std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(points * (1 << _bits));
}

int Fixed::toInt( void ) const{
	return _fixed >> _bits;
}

float Fixed::toFloat( void ) const{
	return static_cast<float>(_fixed) / (1 << _bits);
}

std::ostream& operator<<(std::ostream& ostream, const Fixed &fixed){
	return ostream << fixed.toFloat();
}
