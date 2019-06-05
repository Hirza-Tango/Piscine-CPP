#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain{
public:
	Brain();
	std::string identify() const;
private:
	const Brain *_address;
};

#endif
