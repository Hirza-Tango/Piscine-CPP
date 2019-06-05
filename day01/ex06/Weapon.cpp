#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string weapon_type){
	type = weapon_type;
}
const std::string &Weapon::getType(){
	return this->type;
}
void Weapon::setType(std::string weapon_type){
	type = weapon_type;
}
