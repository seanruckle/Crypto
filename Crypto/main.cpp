#include "file.h"
//#include "statistics.h"
#include "menu.h"
class statistics;
int main(void) {
	int input = -1;
	int input2 = -1;
	int type = 0;
	char tmp;
	file file;
	decrypt  decrypt;
	statistics stats;
	menu menu;

	file.readFile("test.txt");
	stats.readSample("sample.txt");
	stats.initVars(file.getInput());
	input = menu.options();
	stats.stats(file.getInput());
	if (input == 1) {
		type = decrypt.guessType(stats, file.getInput());
		switch (type) {
		case 1:
			std::cout << "This is probably a one time pad and not possible to decode" << std::endl;
			stats.printStats();
			input2 = menu.options5();
			break;
		case 2:
			std::cout << "This is probably a mono alphabetic cipher like a shift, columnar transposition, or a substitution cipher" << std::endl;		
			stats.printStats();
			input2 = menu.options4() + 3;
			break;
		case 3:
			std::cout << "This is probably a poly alphabetic cipher like a vigenere cipher or a one time pad" << std::endl;
			stats.printStats();
			input2 = menu.options3() + 6;
			break;
		}
		
	}
	if (input2 == 4) { //auto crack shift cipher
		if (decrypt.autoShift(stats, file.getInput(), 0)) {
			file.printText();
			std::cout << "Does this look correct y/n" << std::endl;
			std::cin >> tmp;
			if (tmp == 'Y' || tmp == 'y') {
				std::cout << "Congratulations" << std::endl;
			}
			else {
				std::cout << "Do you want to try manually solving y/n" << std::endl;
				std::cin >> tmp;
				if (tmp == 'Y' || tmp == 'y') {
					decrypt.autoShift(stats, file.getInput(), 1); // undoing the shift
					input = 2;
				}
				else {
					return 0;
				}
			}
		}
	}
	if (input == 2) {
		input= menu.options2();
		std::cout << "Enter key" << std::endl;
		menu.crack(input, file.getInput(), stats);
		file.printText();
	}
	//file.print(stats.getStats(), stats.getSample(), stats.getDiagrams(), stats.getIC());
	if (input2 == 2 || input2 == 6 || input2 == 9) {
		return 0;
	}
		std::getchar();
	return 0;
}