#include "statistics.h"




statistics::statistics()
{
}

bool statistics::readSample(char * fileName)
{
	std::ifstream inS;
	float temp;
	inS.open(fileName);
	if (!inS.is_open()) {
		std::cout << "FILE couldn't be opened";
		return false;
	}
	while (!inS.eof()) {
		inS >> temp;
		if (!inS.eof()) {
			sampleData.push_back(temp);
		}
	}
	return true;
}

void statistics::initVars(std::vector<char>* in)
{
	int i=0;
	int j = 0;
	diagram node;
	total = in->size();
	
	for (i = 0; i < 26; i++) {
		lettersAmount.push_back(0);
		lettersPercent.push_back(0);
		letters.push_back('A' + i);
		for (j = 0; j < 26; j++) {
			node.one = 'A' + i;
			node.two = 'A' + j;
			diagrams.push_back(node);
			diagramAmount.push_back(0);
			diagramPercent.push_back(0);
			
		}
	}
}

std::vector<char>* statistics::getLetters()
{
	return &letters;
}

std::vector<float>* statistics::getStats()
{
	return &lettersPercent;
}
std::vector<float>* statistics::getSample()
{
	return &sampleData;
}

std::vector<float>* statistics::getDiagrams()
{
	return &diagramPercent;
}

float statistics::getIC()
{
	return IC;
}

void statistics::calcIC(std::vector<int>* in)
{
	int i = 0;
	double sum = 0;
	for (i = 0; i < 26; i++) {
		sum = sum + (double)(in->at(i) * ((double)in->at(i) - 1.0)) / ((double)total * ((double)total - 1.0));
	}
	IC = sum;
	return;
}


bool statistics::stats(std::vector<char>* in)
{
	unsigned int i = 0;
	unsigned int j = 0;
	char temp1;
	char temp2;
	for (i = 0; i < in->size(); i++) {
		lettersAmount.at(in->at(i) - 'A') = lettersAmount.at(in->at(i) - 'A') + 1;
	}
	for (i = 0; i < lettersAmount.size(); i++) {
		lettersPercent.at(i) = (float)lettersAmount.at(i) / (float)total;
	}

	for (i = 0; i < in->size()-1; i++) {
		temp1 = in->at(i);
		temp2 = in->at(i + 1);
		diagramAmount.at((temp1 - 'A') * 26 + (temp2 - 'A')) = diagramAmount.at((temp1 - 'A') * 26 + (temp2 - 'A')) + 1;
	}
	for (i = 0; i < diagramAmount.size(); i++) {
		diagramPercent.at(i) = (float)diagramAmount.at(i) / (float)(diagramAmount.size());
	}
	calcIC(&lettersAmount);
	return false;
}

void statistics::printStats()
{
	int index1 = 0;
	int index2 = 1;
	int index3 = 2;
	int index4 = 3;
	int index5 = 4;
	int i = 0;
	float tmp;
	for (i = 0; i < lettersPercent.size(); i++) {
		tmp = lettersPercent.at(i);
		if (tmp > lettersPercent.at(index1)) {
			index1 = i;
		}
		else if (tmp > lettersPercent.at(index2)) {
			index2 = i;
		}
		else if (tmp > lettersPercent.at(index3)) {
			index3 = i;
		}
		else if (tmp > lettersPercent.at(index4)) {
			index4 = i;
		}
		else if (tmp > lettersPercent.at(index5)) {
			index5 = i;
		}
	}
		std::cout << "Cipher text percents:" << std::endl << letters.at(index1) << "\t" << lettersPercent.at(index1) << std::endl <<
			letters.at(index2) << "\t" << lettersPercent.at(index2) << std::endl <<
			letters.at(index3) << "\t" << lettersPercent.at(index3) << std::endl <<
			letters.at(index4) << "\t" << lettersPercent.at(index4) << std::endl <<
			letters.at(index5) << "\t" << lettersPercent.at(index5) << std::endl;
		index1 = 0;
		index2 = 1;
		index3 = 2;
		index4 = 3;
		index5 = 4;
		for (i = 0; i < sampleData.size(); i++) {
			tmp = sampleData.at(i);
			if (tmp > sampleData.at(index1)) {
				index1 = i;
			}
			else if (tmp > sampleData.at(index2)) {
				index2 = i;
			}
			else if (tmp > sampleData.at(index3)) {
				index3 = i;
			}
			else if (tmp > sampleData.at(index4)) {
				index4 = i;
			}
			else if (tmp > sampleData.at(index5)) {
				index5 = i;
			}
		}
			std::cout << "English language percents:" << std::endl << letters.at(index1) << "\t" << sampleData.at(index1) << std::endl <<
				letters.at(index2) << "\t" << lettersPercent.at(index2) << std::endl <<
				letters.at(index3) << "\t" << lettersPercent.at(index3) << std::endl <<
				letters.at(index4) << "\t" << lettersPercent.at(index4) << std::endl <<
				letters.at(index5) << "\t" << lettersPercent.at(index5) << std::endl;
}

statistics::~statistics()
{
}



diagram::diagram()
{
}


diagram::~diagram()
{
}
