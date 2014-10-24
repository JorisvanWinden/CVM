#ifndef VM_H
#define VM_H

#include <iostream>
#include "sub.h"

#define MAX_SUBS 20

class VM {
public:
	explicit VM();
	~VM();
	void run(std::ifstream & file);
private:
	Sub * subs[MAX_SUBS];
	int num_subs;
	
	void interpret(const char bytecode[], const int size);

	void make_sub(const char bytecode[], const int size, const int args);
};

#endif
