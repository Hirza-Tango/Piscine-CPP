#ifndef PHONEBOOK_HPP
 #define PHONEBOOK_HPP

 #include "Contact.hpp"
 #include <iostream>
 #include <iomanip>
 #include "prompt.hpp"

class PhoneBook{
public:
	Contact book[8];
	void add();
	void search();
private:
	std::string trim_field(std::string field);
	int get_state(Contact book[8], bool full);
};

#endif
