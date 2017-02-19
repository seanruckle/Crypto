#include "file.h"
//#include "statistics.h"
#include "menu.h"
class statistics;
int main(void) {
	int input = -1;
	file file;
	statistics stats;
	menu menu;

	file.readFile("test.txt");
	stats.readSample("sample.txt");
	stats.initVars(file.getInput());
	input = menu.options();
	stats.stats(file.getInput());
	if (input == 1) {
		
	}
	if (input == 2) {
		input= menu.options2();
		std::cout << "Enter key" << std::endl;
		menu.crack(input, file.getInput(), stats);
		file.printText();
	}
	file.print(stats.getStats(), stats.getSample(), stats.getDiagrams(), stats.getIC());
		std::getchar();
	return 0;
}