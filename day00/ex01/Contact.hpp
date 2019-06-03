#ifndef CONTACT_HPP
 #define CONTACT_HPP
 #include <iostream>
 #include <termios.h>
 #include <unistd.h>
 #include "prompt.hpp"

class Contact
{
public:
	bool full = false;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birth_date;
	std::string favourite_meal;
	// These are only public because the "friend" keyword is disallowed
	std::string underwear_color;
	std::string darkest_secret;
	void fill();
private:
};

std::ostream& operator<<(std::ostream &stream, const Contact contact);

#endif
