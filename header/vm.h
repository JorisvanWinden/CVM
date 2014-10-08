#ifndef VM_H
#define VM_H

#include <iostream>
#include "sub.h"

#define MAX_SUBS 20

class VM {
public:
	VM();
	~VM();
	void run(std::ifstream & file);
private:
	Sub * subs[MAX_SUBS];
	int num_subs;
	
	void interpret(char bytecode[], int size);

	void make_sub(char bytecode[], int size);
};

#endif
