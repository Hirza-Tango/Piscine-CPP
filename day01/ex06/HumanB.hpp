#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB{
public:
	HumanB(std::string human_name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &human_weapon);
private:
	Weapon *weapon;
	std::string name;
};

#endif
