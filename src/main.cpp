#include <fstream>
#include <iostream>
#include "vm.h"

int main(int argc, char * argv[]) {
	VM vm;
	if(argc == 1) {
		std::cout << "You need to provide a file. Exiting." << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	std::cout << "Executing " << argv[1] << std::endl;
	vm.run(file);
	return 0;
}