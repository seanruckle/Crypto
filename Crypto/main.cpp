#include "file.h"
#include "statistics.h"

int main(void) {
	file file;
	statistics stats;

	file.readFile("test.txt");
	stats.readSample("sample.txt");
	stats.initVars(file.getInput());
	stats.stats(file.getInput());

	file.print(stats.getStats(), stats.getSample(), stats.getDiagrams(), stats.getIC());
		std::getchar();
	return 0;
}