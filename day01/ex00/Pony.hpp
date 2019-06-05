#ifndef PONY_HPP
# define PONY_HPP

#include <string>

typedef enum e_sex{
	male,
	female
} t_sex;

class Pony{
public:
	Pony(std::string breed, t_sex sex, size_t height);
	~Pony();
	void showPony();
private:
	std::string _breed;
	t_sex _sex;
	size_t _height;
};

void ponyOnTheHeap(std::string breed, t_sex sex, size_t height);
void ponyOnTheStack(std::string breed, t_sex sex, size_t height);

#endif
