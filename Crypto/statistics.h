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

class statistics
{
private:
	int total;
	double IC;
	std::vector<float> sampleData;
	std::vector<char> letters;
	std::vector<int> lettersAmount;
	std::vector<float> lettersPercent;
	std::vector<diagram> diagrams;
	std::vector<int> diagramAmount;
	std::vector<float> diagramPercent;

public:
	statistics();
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
	~statistics();
};




