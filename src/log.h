#ifndef LOG_H
#define LOG_H

#define LOG

#include <string>

inline void log(const std::string & tag, const std::string & msg) {
	#ifdef LOG
	std::cout << tag << ": " << msg << std::endl;
	#endif
}

#endif