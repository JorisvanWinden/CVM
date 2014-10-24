#ifndef EXIT_H
#define EXIT_H

#include <iostream>
#include <cstdlib>

inline void quit(const char * msg) {
	if(msg) {
		std::cout << msg << std::endl;	
	}

	exit(1);
}

#endif