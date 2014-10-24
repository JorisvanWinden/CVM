#ifndef SUB_H
#define SUB_H

#include "stack.h"

class Sub {
public:
	explicit Sub(Sub ** const subs, int * num_subs, const char * bytecode, const int size, const int args);
	void run(Stack & stack);
	int get_args();
private:
	void execute(Stack & stack, const char inst, const char par);

	void add(Stack & stack);
	void subtract(Stack & stack);
	void multiply(Stack & stack);
	void divide(Stack & stack);
	void store(Stack & stack, int value);
	void print(Stack & stack) const;

	const char * bytecode;
	const int size;
	const int args;
	int * num_subs;

	Sub ** const subs;
};

#endif