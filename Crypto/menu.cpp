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
	int i = 0;
	char tmp = '9';
	std::string vigenere;
	std::string sub = "33";
	statistics stats;
	decrypt decrypt;
	switch(input) {
	case 1:	//shift
		std::cout << "Shift: ";
		std::cin >> shift;
		std::cout << std::endl;
		decrypt.decryptShift(shift, in);
		break;
	case 2:	//substitution
		vigenere = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		std::cout << "Manualy decrypt the cipher" << std::endl << "Enter 9 to exit" << "Enter the substitution you want to add like this AB, where an A in the cipher text is now a B in the plain text" << std::endl;
		while (sub.at(0) != tmp) {
			std::cin >> sub;
			if (sub.at(0) == '9') { 
				break; 
			}
			for (i = 0; i < sub.size(); i++) {
				sub.at(i) = toupper(sub.at(i));
			}
			vigenere.at(sub.at(0) - 'A') = sub.at(1);
			decrypt.decryptSub(vigenere, in);
		}
		break;
	case 3: //vigenere
		std::cout << "String Key: ";
		std::cin >> vigenere;
		std::cout << std::endl;
		for (i = 0; i < vigenere.size(); i++) {
			vigenere.at(i) = toupper(vigenere.at(i));
		}
		decrypt.decryptVigenere(vigenere, in);
		break;
	case 4: // permutation
		break;
	case 5: //ont time pad
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
