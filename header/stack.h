#ifndef STACK_H
#define STACK_H

class Stack {
public:
	Stack(int * stack, int size);
	Stack(const Stack & source, int start);

	int peek();
	int pop();
	void push(int val);
	void reset();
private:
	int * stack;
	int top;
	const int size;
};

#endif