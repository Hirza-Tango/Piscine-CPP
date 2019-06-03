#include "PhoneBook.hpp"

void PhoneBook::add(){
	int index = get_state(book,0);
	if (index == -1){
		std::cout << "ERROR: The phonebook is full" << std::endl;
		return;
	}
	book[index].fill();
}

void PhoneBook::search(){
	int index;
	if (get_state(book, 1) == -1){
		std::cout << "ERROR: The phonebook is empty" << std::endl;
		return;
	}
	std::cout << "Index     |First Name|Last Name |Nickname  " << std::endl;
	std::cout << std::setw(43) << std::setfill('-') << "" << std::endl;
	for (int i = 0; i < 8; i++){
		if(book[i].full){
			std::cout << std::setw(10) << std::setfill(' ') << i << "|";
			std::cout << std::setw(10) << trim_field(book[i].first_name) << "|";
			std::cout << std::setw(10) << trim_field(book[i].last_name) << "|";
			std::cout << std::setw(10) << trim_field(book[i].nickname);
			std::cout << std::endl;
		}
	}
	std::cout << std::setw(43) << std::setfill('-') << "" << std::endl;
	std::setfill(' ');
	index = getInput("Select the index of your contact: ")[0] - 48;
	if (index < 0 || index > 7){
		std::cout << "ERROR: invalid input" << std::endl;
		return;
	}
	if (!book[index].full){
		std::cout << "ERROR: empty contact selected" << std::endl;
		return;
	}
	std::cout << book[index];
}

std::string PhoneBook::trim_field(std::string field){
	if (field.length() > 10){
		return field.substr(0, 9) + ".";
	}
	return field;
}

int PhoneBook::get_state(Contact book[8], bool full){
	for (int i = 0; i < 8; i++){
		if (book[i].full == full){
			return i;
		}
	}
	return -1;
}
