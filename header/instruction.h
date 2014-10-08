#ifndef INSTRUCTION_H
#define INSTRUCTION_H

enum Instruction {
	OPER_ADD = 0x00,
	OPER_SUB = 0x01,
	OPER_MUL = 0x02,
	OPER_DIV = 0x03,
	OPER_STO = 0x04,
	OPER_GET = 0x05,
	OPER_PNT = 0x06,
	OPER_MKS = 0x07,
	OPER_END = 0x08,
	OPER_ENT = 0x09
};

#endif