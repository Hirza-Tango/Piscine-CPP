#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name, std::string type)
{
	_name = name;
	_type = type;
}

void Zombie::announce(void){
	std::cout << "<" << _name << " (" << _type <<")> Braiiiiiiins" << std::endl;
}
