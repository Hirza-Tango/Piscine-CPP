#include "Human.hpp"

const Brain Human::getBrain(){
	return _brain;
}

std::string Human::identify(){
	return _brain.identify();
}

Human::Human(){}
