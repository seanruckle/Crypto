#include "menu.h"
#include <string>


menu::menu()
{
}

int menu::options()
{
	int input = -1;
	std::cout << "Options:" << std::endl << "1. Run analysis to crack cipher" << std::endl << "2. Choose ciper and enter key" << std::endl;
	std::cin >> input;
	return input;
}

int menu::options2()
{
	int input = -1;
	std::cout << "Possible Ciphers:" << std::endl << "1. Shift Cipher" << std::endl << "2. Substitution Cipher" << std::endl << "3. Vigenere Cipher" << std::endl << "4. Permutation Cipher" << std::endl << "5. One-Time Pad" << std::endl;
	std::cin >> input;
	return input;
}

int menu::crack(int input, std::vector<char>* in)
{
	int shift;
	int i;
	std::string vigenere;
	statistics stats;
	decrypt decrypt;
	switch(input) {
	case 1:
		std::cout << "Shift: ";
		std::cin >> shift;
		std::cout << std::endl;
		decrypt.decryptShift(shift, in);
		break;
	case 2:
		break;
	case 3:
		std::cout << "String Key: ";
		std::cin >> vigenere;
		std::cout << std::endl;
		for (i = 0; i < vigenere.size(); i++) {
			vigenere.at(i) = toupper(vigenere.at(i));
		}
		decrypt.decryptVigenere(vigenere, in);
		break;
	case 4:
		break;
	case 5:
		break;
	}
	return 0;
}

void menu::guess(int type)
{
	switch (type) {
	case 0:
		std::cout << "Guessing it is a shift cipher" << std::endl;
		break;
	case 1:
		std::cout << "Guessing it is a substitution cipher" << std::endl;
		break;
	case 2:
		std::cout << "Guessing it is a vigenere cipher" << std::endl;
		break;
	case 3:
		std::cout << "Guessing it is a permutation cipher" << std::endl;
		break;
	case 4:
		std::cout << "Guessing it is a one-time pad" << std::endl;
		break;
	}

}


menu::~menu()
{
}
