#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(){
	_fixed = 0;
}

Fixed::~Fixed(){
}

Fixed::Fixed(const Fixed &orig){
	*this = orig;
}

Fixed Fixed::operator=(const Fixed &orig){
	this->_fixed = orig._fixed;
	return *this;
}

int Fixed::getRawBits( void ) const{
	return _fixed;
}

void Fixed::setRawBits( int const raw ){
	_fixed = raw;
}

Fixed::Fixed(int num){
	_fixed = num << _bits;
}

Fixed::Fixed(float num){
	_fixed = static_cast<int>(roundf(num * (1 << _bits)));
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

bool Fixed::operator>(const Fixed &rhs) const{
	return this->_fixed > rhs._fixed;
}

bool Fixed::operator<(const Fixed &rhs) const{
	return this->_fixed < rhs._fixed;
}

bool Fixed::operator>=(const Fixed &rhs){
	return this->_fixed >= rhs._fixed;
}

bool Fixed::operator<=(const Fixed &rhs){
	return this->_fixed <= rhs._fixed;
}

bool Fixed::operator==(const Fixed &rhs){
	return this->_fixed == rhs._fixed;
}

bool Fixed::operator!=(const Fixed &rhs){
	return this->_fixed != rhs._fixed;
}

Fixed Fixed::operator+(const Fixed &rhs) const{
	return Fixed(this->_fixed + rhs._fixed);
}

Fixed Fixed::operator-(const Fixed &rhs) const{
	return Fixed(this->_fixed - rhs._fixed);
}

Fixed Fixed::operator*(const Fixed &rhs) const{
	return Fixed(this->_fixed * rhs._fixed);
}

Fixed Fixed::operator/(const Fixed &rhs) const{
	return Fixed(this->_fixed / rhs._fixed);
}

Fixed& Fixed::operator++(){
	this->_fixed++;
	return *this;
}

Fixed& Fixed::operator--(){
	this->_fixed--;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed ret;
	ret._fixed++;
	return ret;
}

Fixed Fixed::operator--(int){
	Fixed ret;
	ret._fixed--;
	return ret;
}

Fixed &min(Fixed &lhs, Fixed &rhs){
	if (lhs > rhs){
		return rhs;
	} else {
		return lhs;
	}
}

const Fixed &min(const Fixed &lhs, const Fixed &rhs){
	if (lhs > rhs){
		return rhs;
	} else {
		return lhs;
	}
}

Fixed &max(Fixed &lhs, Fixed &rhs){
	if (lhs < rhs){
		return rhs;
	} else {
		return lhs;
	}
}

const Fixed &max(const Fixed &lhs, const Fixed &rhs){
	if (lhs > rhs){
		return rhs;
	} else {
		return lhs;
	}
}
