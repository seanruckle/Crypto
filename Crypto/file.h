#include <fstream>
#include <iostream>
#include <vector>

class file
{
private:
	std::vector<char> input;

public:

	file();
	bool readFile(char* fileName);
	std::vector<char>* getInput();
	void print(std::vector<float>* in, std::vector<float>* sample, std::vector<float>* diagrams, float IC);
	~file();
};

