#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon{
public:
	Weapon();
	Weapon(std::string weapon_type);
	const std::string &getType();
	void setType(std::string);
private:
	std::string type;
};

#endif
