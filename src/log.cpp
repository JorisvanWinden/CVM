#include "log.h"
#include <iostream>
#include <string>

void log(const std::string & tag, const std::string & msg) {
	std::cout << tag << ": " << msg << std::endl;
}