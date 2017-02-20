#include "statistics.h"




statistics::statistics()
{
}

int statistics::findTri()
{
	int i = 0;
	int k = 1;
	int index = 0;;
	int tmp1;
	int tmp2;
	std::vector<int> temp;
	std::priority_queue<std::pair<double, int>> q;
	for (int i = 0; i < trigramAmount.size(); ++i) {
		if (trigramAmount.at(i) > trigramAmount.at(index)) {
			index = i;
		}
		tmp1 = trigramAmount.at(index);
		tmp2 = trigramAmount.at(14504);
		//temp = trigramIndexes.at(index);
		//q.push(std::pair<double, int>(trigramAmount.at(i), i));
	}
	//index = q.top().second; 
	//q.pop();
	//i = 0;
	trigramIndex = index;
	return index;
}

float statistics::getLetPer(int i)
{
	return lettersPercent.at(i);
}

float statistics::getSamPer(int i)
{
	return sampleData.at(i);
}

char statistics::getLet(int i)
{
	return letters.at(i);
}

char statistics::getCip(int i)
{
	return 0;
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
	int k = 0;
	diagram node;
	trigram temp;
	std::vector<int> tmp;
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
			for (k = 0; k < 26; k++) {
				temp.one = 'A' + i;
				temp.two = 'A' + j;
				temp.three = 'A' + k;
				trigrams.push_back(temp);
				trigramAmount.push_back(0);
			}
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
	char temp3;
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
	for (i = 0; i < in->size() - 2; i++) {
		temp1 = in->at(i);
		temp2 = in->at(i + 1);
		temp3 = in->at(i + 2);
		trigramAmount.at((temp1 - 'A') * 26 * 26 + (temp2 - 'A') * 26 + (temp3 - 'A') ) = trigramAmount.at((temp1 - 'A') * 26 * 26 + (temp2 - 'A') * 26 + (temp3 - 'A') ) + 1;
	}
	for (i = 0; i < diagramAmount.size(); i++) {
		diagramPercent.at(i) = (float)diagramAmount.at(i) / (float)(diagramAmount.size());
	}
	calcIC(&lettersAmount);
	findTri();
	GCD(in);
	return false;
}

void statistics::printStats()
{
	//float tmp;
	int i = 0;
	int k = 5;
	int array1[5];
	int array2[5];

	std::priority_queue<std::pair<double, int>> q;
	std::priority_queue<std::pair<double, int>> w;
	for (int i = 0; i < lettersPercent.size(); ++i) {
		q.push(std::pair<double, int>(lettersPercent[i], i));
	}
	for (int i = 0; i < k; ++i) {
		int ki = q.top().second;
		array1[i] = ki;
		q.pop();
	}
	for (int i = 0; i < sampleData.size(); ++i) {
		w.push(std::pair<double, int>(sampleData[i], i));
	}
	for (int i = 0; i < k; ++i) {
		int ki = w.top().second;
		array2[i] = ki;
		w.pop();
	}

	std::cout << "Cipher text percents:" << std::endl;
	for (i = 0; i < 5; i++) {
		std::cout << letters.at(array1[i]) << "\t" << lettersPercent.at(array1[i]) << std::endl;
	}
	std::cout << "English language percents:" << std::endl;
	for (i = 0; i < 5; i++) {
		std::cout << letters.at(array2[i]) << "\t" << sampleData.at(array2[i]) << std::endl;
	}
	std::cout << "IC: " << IC << std::endl;
}

int statistics::GCD(std::vector<char>* in)
{
	char tmp1;
	char tmp2;
	char tmp3;
	int result;
	int temp;
	int k=0;
	float sum = 0;;
	std::vector<int> index;
	std::vector<int> gcd;
	int i = 0;
	for (i = 0; i < in->size() - 2; i++) {
		tmp1 = in->at(i);
		tmp2 = in->at(i+1);
		tmp3 = in->at(i+2);
		if ((trigrams.at(trigramIndex).one) == tmp1 && ((trigrams.at(trigramIndex).two) == tmp2) && ((trigrams.at(trigramIndex).three) == tmp3)) {
			index.push_back(i);
		}
	}
	for (i = 0; i < index.size() - 1; i++) {
		gcd.push_back(index.at(i + 1) - index.at(i));
	}
	result = gcd.at(1);
	for (i = 0; i < gcd.size(); i++) {
		temp = gcdFun(result, gcd.at(i));
		if (temp != 1) {
			result = temp;
			sum = sum + result;
			k++;
		}
		
	}
	sum = sum / k;
	vigenereKeyLength = int(sum);
	return 0;
}

int statistics::gcdFun(int a, int b)
{
	int tmp;
	while (b > 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int statistics::getKeyLength()
{
	return vigenereKeyLength;
}

float statistics::getEnglish(int i)
{
	return sampleData.at(i);
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


trigram::trigram()
{
}


trigram::~trigram()
{
}
