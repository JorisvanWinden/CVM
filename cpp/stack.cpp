#include "../header/stack.h"
#include <assert.h>

Stack::Stack(int size) : size(size), top(-1), stack(new int[size]) {}

Stack::~Stack() {
	delete[] stack;
}

int Stack::peek() {
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