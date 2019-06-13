enum input_types{
	is_char = 0,
	is_int,
	is_float,
	is_double,
	is_inf_pos,
	is_inf_neg,
	is_nan,
	is_inff_pos,
	is_inff_neg,
	is_nanf
};

#include <sstream>
#include <iostream>
#include <string>
#include <string.h>
#include <climits>
#include <cfloat>

void exit(std::string message){
	std::cout << message << std::endl;
	exit(0);
}

char detect_type(std::string input){
	if (input == "+inf")
		return is_inf_pos;
	else if (input == "-inf")
		return is_inf_neg;
	else if (input == "nan")
		return is_nan;
	else if (input == "+inff")
		return is_inff_pos;
	else if (input == "-inff")
		return is_inff_neg;
	else if (input == "nanf")
		return is_nanf;
	else if (input.length() == 1 && input[0] < '0' && input[0] > '9'){
		return is_char;
	} else if (input[input.length - 1] == 'f'){
		if (input.find('-', 1) != std::string::npos){
			//check for minus not at start
			exit("Bad input");
		} else if (input.find('.', input.find('.') + 1) != std::string::npos){
			//check for multiple dots
			exit("Bad input");
		}
		if (input != "-inff" && input != "+inff" && input != "nanf"){
			//check for bad characters
			for (size_t i = 0; i < input.length() - 1; i++){
				if (input[i] < '0' && input[i] > '9' && input[i] != '.' && input[i] != '-'){
					exit("Bad input");
				}
			}
		}
		return is_float;
	} else if (input.find('.') || input == "nan" || input == "+inf" || input == "-inf"){
		if (input.find('-', 1) != std::string::npos){
			//check for minus not at start
			exit("Bad input");
		} else if (input.find('.', input.find('.') + 1) != std::string::npos){
			//check for multiple dots
			exit("Bad input");
		}
		if (input != "-inf" && input != "+inf" && input != "nan"){
			for (size_t i = 0; i < input.length(); i++){
				//check for bad characters
				if (input[i] < '0' && input[i] > '9' && input[i] != '.' && input[i] != '-'){
					exit("Bad input");
				}
			}
		}
		return is_double;
	}
	else {
		if (input.find('-', 1) != std::string::npos){
			//check for minus not at start
			exit("Bad input");
		}
		for (size_t i = 1; i < input.length(); i++){
			//check for bad characters
			if (input[i] < '0' && input[i] > '9' && input[i] != '.' && input[i] != '-'){
				exit("Bad input");
			}
		}
		return is_int;
	}
}

int main(int argc, char *argv[]){
	if (argc < 2){
		exit("Not enough arguments");
	}
	std::string input = argv[1];
	char input_type = detect_type(input);
	std::stringstream stream(input);
	switch (input_type){
		case is_char:
			char char_value = input[0];
			std::cout << "char: ";
			if (isprint(char_value)){
				std::cout << "'" << char_value << "'" << std::endl;
			} else {
				std::cout << "Non displayable" << std::endl;
			}
			std::cout << "int: " << static_cast<int>(char_value) << std::endl;
			std::cout << "float: " << static_cast<float>(char_value) << std::endl;
			std::cout << "double: " << static_cast<double>(char_value) << std::endl;
			break;
		case is_float:
			float float_value;
			stream >> float_value;
			//TODO: check for fail
			std::cout << "char: ";
			if (float_value > CHAR_MAX || float_value < CHAR_MIN){
				std::cout << "impossible" << std::endl;
			} else {
				char_value = static_cast<char>(float_value);
				if (isprint(char_value)){
					std::cout << "'" << char_value << "'" << std::endl;
				} else {
					std::cout << "Non displayable" << std::endl;
				}
			}
			std::cout << "int: ";
			if (float_value > INT_MAX || float_value < INT_MIN){
				std::cout << "impossible" << std::endl;
			} else {
				std::cout << static_cast<int>(float_value) << std::endl;
			}
			std::cout << "float: " << float_value <<std::endl;
			std::cout << "double: " << static_cast<double>(float_value) << std::endl;
			break;
		case is_double:
			double double_value;
			stream >> double_value;
			//TODO: check for fail
			std::cout << "char: ";
			if (double_value > CHAR_MAX || double_value < CHAR_MIN){
				std::cout << "impossible" << std::endl;
			} else {
				char_value = static_cast<char>(double_value);
				if (isprint(char_value)){
					std::cout << "'" << char_value << "'" << std::endl;
				} else {
					std::cout << "Non displayable" << std::endl;
				}
			}
			std::cout << "int: ";
			if (double_value > INT_MAX || double_value < INT_MIN){
				std::cout << "impossible" << std::endl;
			} else {
				std::cout << static_cast<int>(double_value) << std::endl;
			}
			std::cout << "float: ";
			if (double_value > FLT_MAX){
				std::cout << "+inff" << std::endl;
			} else if (double_value < FLT_MIN){
				std::cout << "-inff" << std::endl;
			} else {
				std::cout << static_cast<float>(double_value) << std::endl;
			}
			std::cout << "double: " << double_value <<std::endl;
			break;
		case is_int:
			int int_value;
			stream >> int_value;
			//TODO: check for fail
			std::cout << "char: ";
			if (int_value > CHAR_MAX || int_value < CHAR_MIN){
				std::cout << "impossible" << std::endl;
			} else if (isprint(int_value)){
				std::cout << "'" << static_cast<char>(int_value) << "'" << std::endl;
			} else {
				std::cout << "Non displayable" << std::endl;
			}
			std::cout << "int: " << int_value << std::endl;
			std::cout << "float: " << static_cast<float>(int_value) << std::endl;
			std::cout << "double: " << static_cast<double>(int_value) << std::endl;
			break;
		case is_inf_pos:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			break;
		case is_inf_neg:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			break;
		case is_nanf:
		case is_nan:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			break;
		case is_inff_pos:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: " << FLT_MAX << std::endl;
		case is_inff_neg:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: " << FLT_MIN << std::endl;
	}

}
