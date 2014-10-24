#include <stack.h>
#include <exit.h>
#include <iostream>
#include <log.h>

#define TAG "Stack"

Stack::Stack(int * stack, int size) : stack(stack), top(-1), size(size) {}

Stack::Stack(const Stack & source, int args) :
	stack(source.stack + source.top - args),
	top(args),
	size(source.size - source.top) {}

int Stack::peek() const {
	if(top < 0) quit
	("Stack underflow");
	log(TAG, "Peeking");
	return stack[top];
}

int Stack::pop() {
	if(top < 0) quit
	("Stack underflow");
	int val = stack[top--];
	log(TAG, "Popping");
	stack[top + 1] = 0;
	return val;
}

void Stack::push(int value) {
	if(top == size) quit
	("Stack overflow");
	log(TAG, "Pushing");
	stack[++top] = value;
}

void Stack::reset() {
	for(int i = 0; i < size; i++) {
		stack[i] = 0;
	}
	log(TAG, "Resetting");
	top = -1;
}