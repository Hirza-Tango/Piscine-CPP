#ifndef ZOMBIE_HORDE_HPP
#define ZOMBIE_HORDE_HPP

#include "Zombie.hpp"

class ZombieHorde{
public:
	ZombieHorde(size_t size);
	~ZombieHorde();
	Zombie *zombies;
	void announce(void);
private:
	size_t _size;
};

#endif
