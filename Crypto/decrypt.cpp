#include "decrypt.h"



decrypt::decrypt()
{
}

int decrypt::decryptShift(int shift, std::vector<char>* in)
{
	int i;
	for (i = 0; i < in->size(); i++) {
		in->at(i) = (((in->at(i) - 'A') + shift) % 26) + 'A';
	}
	return 0;
}

int decrypt::decryptVigenere(std::string key, std::vector<char>* in)
{
	int i = 0;
	char tmp;
	for (i = 0; i < in->size(); i++) {
		tmp = (in->at(i) - 'A') - (key.at(i % key.size()) - 'A');
		if (tmp < 0) {
			tmp = tmp + 26;
		}
		tmp = tmp + 'A';
		in->at(i) = tmp;
	}
	return 0;
}

int decrypt::decryptSub(std::string key, std::vector<char>* in)
{
	int i = 0;
	std::cout << std::endl << std::endl << "Current substitutions" << std::endl;
	std::cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << std::endl;
	for (i = 0; i < key.size(); i++) {
		std::cout << key.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "Cipher text:     ";
	for (i = 0; i < 100; i++) {
		std::cout << in->at(i);
	}
	std::cout << std::endl << std::endl;
	std::cout << "Decrypt attempt: ";
	for (i = 0; i < 100; i++) {
		std::cout << key.at(in->at(i) - 'A');
	}
	std::cout << std::endl;
	/*for (i = 0; i < 50; i++) {
		std::cout << in->at(i);
	}*/

	return 0;
}

int decrypt::decryptPerm(int key, std::vector<char>* in)
{
	int i = 0;
	int j = 0;
	int k;
	int rows = ceil((float)in->size() / (float)key);
	std::vector<std::vector<char>> matrix;
	std::vector<char> tmp;
	std::vector<char> plain;
	for (i = 0; i < key; i++) {
		matrix.push_back(tmp);
	}
	for (i = 0; i < rows; i++) {
		for (j = 0; j < key; j++) {
			matrix.at(j).push_back(' ');
		}
	}
	k = in->size() % key;
	if (k == 0) {
		for (i = 0; i < key; i++) {
			for (j = 0; j < rows; j++) {
				matrix.at(i).at(j) = in->at((i * rows) + j);
			}
		}
	}
	else {
		for (i = 0; i < k; i++) {
			for (j = 0; j < rows; j++) {
				matrix.at(i).at(j) = in->at((i * rows) + j);
			}
		}
		j = j;
		while (i < key) {
			for (j = 0; j < rows - 1; j++) {
				if (((i * rows) + j) < in->size()) {
					matrix.at(i).at(j) = in->at((i * rows) + j);
				}
			}
			i++;
		}
	}
	for (i = 0; i < rows; i++) {
		for (j = 0; j < key; j++) {
			plain.push_back(matrix.at(j).at(i));
		}
	}
	for (i = 0; i < in->size(); i++) {
		in->at(i) = plain.at(i);
	}
	i = 2;
	return 0;
}

int decrypt::guessType(statistics stats, std::vector<char>* in)
{
	if (stats.getIC() <= 0.039 && stats.getIC() >= 0.037) {
		return 1; //one time pad	(polyalphabetic)
	}
	else if (stats.getIC() >= 0.06) {
		return 2; //substirurion, shift, englsih (mono alphabetic)
	}
	else if (stats.getIC() < 0.06) {
		return 3;
	}
	return 0;
}

int decrypt::autoShift(statistics stats, std::vector<char>* in, int var)
{
	int i = 0;
	int k = 5;
	int tmp1;
	int tmp2;
	int array1[5];
	int array2[5];

	std::priority_queue<std::pair<double, int>> q;
	std::priority_queue<std::pair<double, int>> w;
	for (int i = 0; i < 26; ++i) {
		q.push(std::pair<double, int>(stats.getLetPer(i), i));
	}
	for (int i = 0; i < k; ++i) {
		int ki = q.top().second;
		array1[i] = ki;
		q.pop();
	}
	for (int i = 0; i < 26; ++i) {
		w.push(std::pair<double, int>(stats.getSamPer(i), i));
	}
	for (int i = 0; i < k; ++i) {
		int ki = w.top().second;
		array2[i] = ki;
		w.pop();
	}
	tmp1 = array1[0] - array2[0];
	tmp2 = array1[1] - array2[1];
	 
	if (tmp1 < 0) {
		tmp1 = tmp1 * -1;
	}
	if (tmp2 < 0) {
		tmp2 = tmp2 * -1;
	}
	if (tmp1 == tmp2) {
		if (var = 1) {
			decryptShift(26 - tmp1, in);
		}
		else {
			decryptShift(tmp1, in);
		}
		return 1;
	}

	return 0;
}

int decrypt::autoVig(statistics stats, std::vector<char>* in)
{
	int i;
	int j;
	int k = 0;
	std::string key;
	int tmp = 3000;
	int index;
	int length;
	
	char matrix[100] = { 0 };
	length = stats.getKeyLength();
	for (k = 0; k < stats.getKeyLength(); k++) {
		float cs[26] = { 0 };
		tmp = 3000;
		for (i = 0; i < 100; i++) {
			matrix[i] = in->at(i*length + k);
		}
		for (j = 0; j < 26; j++) {
			int lettersAmount[26] = { 0 };
			for (i = 0; i < 100; i++) {
				lettersAmount[matrix[i] - 'A'] = lettersAmount[matrix[i] - 'A'] + 1;
			}
			for (i = 0; i < 26; i++) {
				cs[j] = cs[j] + ((lettersAmount[i] - (100 * stats.getEnglish(i))) * (lettersAmount[i] - (100 * stats.getEnglish(i)))) / (100 * stats.getEnglish(i));
			}
			for (i = 0; i < 100; i++) {
				matrix[i] = (((matrix[i] - 'A') + 1) % 26) + 'A';
			}
			i = 0;
		}
		for (i = 0; i < 26; i++) {
			if (cs[i] < tmp) {
				tmp = cs[i];
				index = i;
			}
		}
		key += (char)'A' + 26 - index;
	}
	decryptVigenere(key, in);
	i = 0;
	return 0;
}


float decrypt::calcIC(char matrix[100], int num)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int a[26] = {0};
	float avg = 0;;
	double sum = 0;
	for (j = 0; j < num; j++) {
		for (i = 0; i < 100; i++) {
			a[matrix[i] - 'A'] = a[matrix[i] - 'A'] + 1;
		}
		sum = 0;
		for (k = 0; k < 26; k++) {
			sum = sum + (double)(a[k] * ((double)a[k] - 1.0)) / ((double)100 * ((double)100 - 1.0));
		}
		
		avg = avg + sum;
	}
	avg = avg / num;
	
	return avg;
}


decrypt::~decrypt()
{
}
