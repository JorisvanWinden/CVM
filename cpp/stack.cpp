#include "../header/stack.h"
#include <assert.h>
#include <iostream>
#include "../header/log.h"

Stack::Stack(int * stack, int size) : size(size), top(-1), stack(stack) {}

Stack::Stack(const Stack & source, int args) :
	stack(source.stack + source.top - args),
	top(args),
	size(source.size - source.top) {}

int Stack::peek() const {
	assert(top > -1);
	return stack[top];
}

int Stack::pop() {
	assert(top > -1);
	int val = stack[top--];
	stack[top + 1] = 0;
	return val;
}

void Stack::push(int value) {
	assert(top != size);
	stack[++top] = value;
}

void Stack::reset() {
	for(int i = 0; i < size; i++) {
		stack[i] = 0;
	}
	top = -1;
}