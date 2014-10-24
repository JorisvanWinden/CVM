#include "sub.h"
#include "stack.h"
#include "instruction.h"
#include "exit.h"
#include "log.h"

#include <assert.h>
#include <iostream>

#define TAG "Sub"

Sub::Sub(Sub ** const subs, int * num_subs, const char * bytecode, const int size, const int args) : 
	bytecode(bytecode), size(size), args(args), num_subs(num_subs), subs(subs) {
		
	}

void Sub::run(Stack & stack) {
	log(TAG, "Running");
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
			if(par < 0 || par > *num_subs - 1) quit("Subroutine out of range");
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
	log(TAG, "Adding");
	stack.push(stack.pop() + stack.pop());
}

void Sub::subtract(Stack & stack) {
	log(TAG, "Subtracting");
	stack.push(stack.pop() - stack.pop());
}

void Sub::multiply(Stack & stack) {
	log(TAG, "Multiplying");
	stack.push(stack.pop() * stack.pop());
}

void Sub::divide(Stack & stack) {
	log(TAG, "Dividing");
	stack.push(stack.pop() / stack.pop());
}

void Sub::store(Stack & stack, int value) {
	log(TAG, "Storing");
	stack.push(value);
}

void Sub::print(Stack & stack) const {
	log(TAG, "Printing");
	std::cout << stack.peek() << std::endl;
}