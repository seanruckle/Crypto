#include <vector>
#include <fstream>
#include <iostream>
#include <queue>

class diagram
{
public:
	diagram();
	char one;
	char two;
	~diagram();
};
class trigram
{
public:
	trigram();
	char one;
	char two;
	char three;
	~trigram();
};

class statistics
{
private:
	int total;
	double IC;
	trigram topTri;
	std::vector<float> sampleData;
	std::vector<char> letters;
	std::vector<int> lettersAmount;
	std::vector<float> lettersPercent;
	std::vector<diagram> diagrams;
	std::vector<int> diagramAmount;
	std::vector<float> diagramPercent;
	std::vector<trigram> trigrams;
	std::vector<int> trigramAmount;
	int trigramIndex;
	int vigenereKeyLength;

public:
	statistics();
	int findTri();
	float getLetPer(int i);
	float getSamPer(int i);
	char getLet(int i);
	char getCip(int i);
	bool readSample(char* fileName);
	void initVars(std::vector<char>* in);
	std::vector<char>* getLetters();
	std::vector<float>* getStats();
	std::vector<float>* getSample();
	std::vector<float>* getDiagrams();
	float getIC();
	void calcIC(std::vector<int>* in);
	bool stats(std::vector<char>* in);
	void printStats();
	int GCD(std::vector<char>* in);
	int gcdFun(int a, int b);
	int getKeyLength();
	float getEnglish(int i);
	~statistics();
};






