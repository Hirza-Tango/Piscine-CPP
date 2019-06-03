#include "Contact.hpp"

void Contact::fill(){
	termios oldTerm, newTerm;

	first_name = getInput("First name: ");
	last_name = getInput("Last name: ");
	nickname = getInput("Nickname: ");
	login = getInput("Login: ");
	postal_address = getInput("Postal address: ");
	email_address = getInput("Email address: ");
	phone_number = getInput("Phone number: ");
	birth_date = getInput("Birthday date: ");
	favourite_meal = getInput("Favourite meal: ");
	tcgetattr(STDIN_FILENO, &oldTerm); // Get terminal settings
	newTerm = oldTerm;	// Copy old settings
	newTerm.c_lflag &= ~ECHO; // Disable echo in new settings
	tcsetattr(STDIN_FILENO, TCSANOW, &newTerm); // Update terminal settings
	underwear_color = getInput("Underwear color: ");
	std::cout << std::endl;
	darkest_secret = getInput("Darkest secret: ");
	std::cout << std::endl;
	tcsetattr(STDIN_FILENO, TCSANOW, &oldTerm); // Reset terminal settings
	full = true;
}

std::ostream& operator<<(std::ostream &stream, const Contact contact){
	std::cout << "First name: " << contact.first_name << std::endl;
	std::cout << "Last name: " << contact.last_name << std::endl;
	std::cout << "Nickname: " << contact.nickname << std::endl;
	std::cout << "Login: " << contact.login << std::endl;
	std::cout << "Postal address: " << contact.postal_address << std::endl;
	std::cout << "Email address: " << contact.email_address << std::endl;
	std::cout << "Phone number: " << contact.phone_number << std::endl;
	std::cout << "Birthday date: " << contact.birth_date << std::endl;
	std::cout << "Favourite meal: " << contact.favourite_meal << std::endl;
	std::cout << "Underwear color: " << contact.underwear_color	 << std::endl;
	std::cout << "Darkest secret: " << contact.darkest_secret << std::endl;
	return stream;
}
