#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string human_name){
	name = human_name;
}

HumanB::~HumanB(){
}

void HumanB::attack(){
	std::cout << name << " attacks with their "
		<< weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &human_weapon){
	weapon = &human_weapon;
}
