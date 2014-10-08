#include "../header/sub.h"
#include "../header/stack.h"
#include "../header/instruction.h"

#include <assert.h>
#include <iostream>

Sub::Sub(Sub * subs[], char * bytecode, int size) : 
	bytecode(bytecode), size(size), subs(subs), stack(Stack(20)) {
		
	}

void Sub::run() {
	stack.reset();
	for(int i = 0; i * 2 < size; i++) {
		execute(bytecode[i * 2], bytecode[i * 2 + 1]);
	}
}

void Sub::execute(char inst, char par) {		
	switch(inst) {
		case OPER_STO:
			store(par);
			break;
		case OPER_PNT:
			print();
			break;
		case OPER_ADD:
			add();
			break;
		case OPER_SUB:
			subtract();
			break;
		case OPER_MUL:
			multiply();
			break;
		case OPER_DIV:
			divide();
			break;
		case OPER_ENT:
			subs[par]->run();
			break;
	}
	#ifdef NDEBUG
	print_stack();
	#endif
}

void Sub::add() {
	stack.push(stack.pop() + stack.pop());
}

void Sub::subtract() {
	stack.push(stack.pop() - stack.pop());
}

void Sub::multiply() {
	stack.push(stack.pop() * stack.pop());
}

void Sub::divide() {
	stack.push(stack.pop() / stack.pop());
}

void Sub::store(int value) {
	stack.push(value);
}

void Sub::print() {
	std::cout << stack.peek() << std::endl;
}