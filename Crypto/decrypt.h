#pragma once
#include "statistics.h"
#include <vector>

class decrypt
{
public:
	decrypt();
	int decryptShift(int shift, std::vector<char>* in);
	int decryptVigenere(std::string key, std::vector<char>* in);
	int decryptSub(std::string key, std::vector<char>* in);
	int decryptPerm(int key, std::vector<char>* in);
	~decrypt();
};

