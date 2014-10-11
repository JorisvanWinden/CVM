#include "../header/sub.h"
#include "../header/stack.h"
#include "../header/instruction.h"

#include <assert.h>
#include <iostream>

Sub::Sub(Sub * subs[], const char * bytecode, const int size, const int args) : 
	bytecode(bytecode), size(size), subs(subs), args(args) {
		
	}

void Sub::run(Stack & stack) {
	for(int i = 0; i * 2 < size; i++) {
		execute(stack, bytecode[i * 2], bytecode[i * 2 + 1]);
	}
	stack.reset();
}

int Sub::get_args() {
	return args;
}

void Sub::execute(Stack & stack, const char inst, const char par) {		
	switch(inst) {
		case OPER_STO:
			store(stack, par);
			break;
		case OPER_PNT:
			print(stack);
			break;
		case OPER_ADD:
			add(stack);
			break;
		case OPER_SUB:
			subtract(stack);
			break;
		case OPER_MUL:
			multiply(stack);
			break;
		case OPER_DIV:
			divide(stack);
			break;
		case OPER_ENT:
			Sub * sub = subs[par];
			Stack nstack(stack, sub->get_args());
			sub->run(nstack);
			break;
	}
	#ifdef NDEBUG
	print_stack(stack);
	#endif
}

void Sub::add(Stack & stack) {
	stack.push(stack.pop() + stack.pop());
}

void Sub::subtract(Stack & stack) {
	stack.push(stack.pop() - stack.pop());
}

void Sub::multiply(Stack & stack) {
	stack.push(stack.pop() * stack.pop());
}

void Sub::divide(Stack & stack) {
	stack.push(stack.pop() / stack.pop());
}

void Sub::store(Stack & stack, int value) {
	stack.push(value);
}

void Sub::print(Stack & stack) const {
	std::cout << stack.peek() << std::endl;
}