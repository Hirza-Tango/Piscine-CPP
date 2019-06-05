#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string human_name, Weapon &human_weapon):weapon(human_weapon){
	name = human_name;
}

void HumanA::attack(){
	std::cout << name << " attacks with their "
		<< this->weapon.getType() << std::endl;
}
