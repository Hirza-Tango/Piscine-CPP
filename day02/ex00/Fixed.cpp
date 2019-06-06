#include "Fixed.hpp"
#include <iostream>

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
	this->_fixed = orig.getRawBits();
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
