#ifndef SUB_H
#define SUB_H

#include "stack.h"

class Sub {
public:
	Sub(Sub ** subs, char * bytecode, int size, int args);
	void run(Stack & stack);
	int get_args();
private:
	void execute(Stack & stack, char inst, char par);

	void add(Stack & stack);
	void subtract(Stack & stack);
	void multiply(Stack & stack);
	void divide(Stack & stack);
	void store(Stack & stack, int value);
	void print(Stack & stack);

	char * bytecode;
	int size;
	const int args;

	Sub ** subs;
};

#endif