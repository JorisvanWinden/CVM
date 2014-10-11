#ifndef STACK_H
#define STACK_H

class Stack {
public:
	explicit Stack(int * stack, int size);
	explicit Stack(const Stack & source, int start);

	int peek() const;
	int pop();
	void push(int val);
	void reset();
private:
	int * stack;
	int top;
	const int size;
};

#endif