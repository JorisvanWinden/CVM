#include "../header/vm.h"
#include "../header/stack.h"
#include "../header/instruction.h"

#include <iostream>
#include <fstream>
#include <assert.h>

#define NDEBUG

VM::VM() : num_subs(0) {}

VM::~VM() {
	for(int i = 0; i < num_subs; i++) {
		delete subs[i];
	}
}

void VM::run(std::ifstream & file) {
	file.seekg(0, file.end);
	int len = file.tellg();
	file.seekg(0, file.beg);

	char * bytes = new char[len];

	file.read(bytes, len);
	interpret(bytes, len);

	delete[] bytes;
}

void VM::interpret(const char bytecode[], const int size) {
	for(int i = 0; i < size; i++) {
		if(bytecode[i] == OPER_MKS) {
			for(int j = i; j < size; j++) {
				if(bytecode[j] == OPER_END) {
					int start = i;
					int size = j - i + 1;
					make_sub(bytecode + start, size, bytecode[start + 1]);
					break;
				}
			}
		}
	}
	int * stack_arr = new int[20];
	Stack stack(stack_arr, 20);
	subs[0]->run(stack);

	delete[] stack_arr;
}

void VM::make_sub(const char bytecode[], const int size, const int args) {
	subs[num_subs] = new Sub(subs, bytecode, size, args);
	num_subs++;
}