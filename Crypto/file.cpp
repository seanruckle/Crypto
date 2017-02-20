#include "file.h"



file::file()
{
}

bool file::readFile(char * fileName)
{
	std::ifstream inS;
	char temp;
	inS.open(fileName);
	if (!inS.is_open()) {
		std::cout << "FILE couldn't be opened";
		return false;
	}
	while (!inS.eof()) {
		inS >> temp;
		if (!inS.eof()) {
			input.push_back(temp);
		}
	}
	inS.close();
	return true;
}

std::vector<char>* file::getInput()
{
	return &input;
}

void file::printText()
{
	int i = 0;
	for (i = 0; i < 100; i++) {
		std::cout << input.at(i);
	}
	std::cout << std::endl;
	return;
}

void file::print(std::vector<float>* in, std::vector<float>* sample, std::vector<float>* diagrams, float IC)
{
	int i = 0;
	int j = 0;
	char let = 'A';
	std::cout << "IC: " << IC << std::endl;
	/*for (i = 0; i < 26; i++) {
		let = 'A' + i;
		std::cout << let << "\t" << in->at(i) << "\t" << sample->at(i) << std::endl;	
	}
	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			std::cout << (char)('A' + i) << (char)('A' + j) << "\t" << diagrams->at(i+j) << std::endl;
		}
	}*/
}


file::~file()
{
}
