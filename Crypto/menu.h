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
	int crack(int input, std::vector<char>* in);
	void guess(int type);
	~menu();
};

