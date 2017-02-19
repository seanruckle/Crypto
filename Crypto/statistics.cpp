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

statistics::~statistics()
{
}



diagram::diagram()
{
}


diagram::~diagram()
{
}
