#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA{
public:
	HumanA(std::string human_name, Weapon &human_weapon);
	void attack();
private:
	Weapon &weapon;
	std::string name;
};

#endif
