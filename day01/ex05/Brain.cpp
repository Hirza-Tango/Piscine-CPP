#include "Brain.hpp"
#include <sstream>

std::string Brain::identify() const{
	std::stringstream ss;
	ss << this;
	return ss.str();
}
