#include <fstream>
#include <iostream>
#include <string>
#include "decrypt.h"

//#include "statistics.h"

class menu
{
public:
	menu();
	int options();
	int options2();
	int options3();
	int options4();
	int options5();
	int crack(int input, std::vector<char>* in, statistics stats);
	int automatic(int input, std::vector<char>* in, statistics stats);
	void guess(int type);
	~menu();
};

