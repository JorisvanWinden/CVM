#ifndef SUB_H
#define SUB_H

#include "stack.h"

class Sub {
public:
	Sub(Sub ** subs, char * bytecode, int size);
	void run();
private:
	void execute(char inst, char par);

	void add();
	void subtract();
	void multiply();
	void divide();
	void store(int value);
	void print();

	Stack stack;
	char * bytecode;
	int size;

	Sub ** subs;
};

#endif