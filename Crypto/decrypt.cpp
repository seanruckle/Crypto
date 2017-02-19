#include "decrypt.h"



decrypt::decrypt()
{
}

int decrypt::decryptShift(int shift, std::vector<char>* in)
{
	int i;
	for (i = 0; i < in->size(); i++) {
		in->at(i) = (((in->at(i) - 'A') + shift) % 26) + 'A';
	}
	return 0;
}

int decrypt::decryptVigenere(std::string key, std::vector<char>* in)
{
	int i = 0;
	char tmp;
	for (i = 0; i < in->size(); i++) {
		tmp = (in->at(i) - 'A') - (key.at(i % key.size()) - 'A');
		if (tmp < 0) {
			tmp = tmp + 26;
		}
		tmp = tmp + 'A';
		in->at(i) = tmp;
	}
	return 0;
}

int decrypt::decryptSub(std::string key, std::vector<char>* in)
{
	int i = 0;
	std::cout << "Cipher text:     ";
	for (i = 0; i < 50; i++) {
		std::cout << in->at(i);
	}
	std::cout << std::endl;
	std::cout << "Decrypt attempt: ";
	for (i = 0; i < 50; i++) {
		std::cout << key.at(in->at(i) - 'A');
	}
	std::cout << std::endl;
	/*for (i = 0; i < 50; i++) {
		std::cout << in->at(i);
	}*/

	return 0;
}


decrypt::~decrypt()
{
}
