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

int decrypt::decryptPerm(int key, std::vector<char>* in)
{
	int i = 0;
	int j = 0;
	int k;
	int rows = ceil((float)in->size() / (float)key);
	std::vector<std::vector<char>> matrix;
	std::vector<char> tmp;
	std::vector<char> plain;
	for (i = 0; i < key; i++) {
		matrix.push_back(tmp);
	}
	for (i = 0; i < rows; i++) {
		for (j = 0; j < key; j++) {
			matrix.at(j).push_back(' ');
		}
	}
	k = in->size() % key;
	if (k == 0) {
		for (i = 0; i < key; i++) {
			for (j = 0; j < rows; j++) {
				matrix.at(i).at(j) = in->at((i * rows) + j);
			}
		}
	}
	else {
		for (i = 0; i < k; i++) {
			for (j = 0; j < rows; j++) {
				matrix.at(i).at(j) = in->at((i * rows) + j);
			}
		}
		j = j;
		while (i < key) {
			for (j = 0; j < rows - 1; j++) {
				matrix.at(i).at(j) = in->at((i * rows) + j);
			}
			i++;
		}
	}
	for (i = 0; i < rows; i++) {
		for (j = 0; j < key; j++) {
			plain.push_back(matrix.at(j).at(i));
		}
	}
	for (i = 0; i < in->size(); i++) {
		in->at(i) = plain.at(i);
	}
	i = 2;
	return 0;
}


decrypt::~decrypt()
{
}
