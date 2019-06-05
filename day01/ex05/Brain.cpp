#include "Brain.hpp"
#include <sstream>

std::string Brain::identify() const{
	std::stringstream ss;
	ss << _address;
	return ss.str();
}

Brain::Brain(){
	//Assigned in constructor because "this" will return human if called in
		//human's context
	_address = this;
}
