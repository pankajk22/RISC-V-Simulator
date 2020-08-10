#ifndef WRITEBACK_H_
#define WRITEBACK_H_
#include<stdint.h>

void writeback()
{	
	cout<<"WRITEBACK"<<endl;
	if( (Instruction_Label_2 == "add") || (Instruction_Label_2 == "sub") || (Instruction_Label_2 == "and") || 
(Instruction_Label_2 == "or") || (Instruction_Label_2 == "xor") || (Instruction_Label_2 == "mul") || 
(Instruction_Label_2 == "div") || (Instruction_Label_2 == "addi") || (Instruction_Label_2 == "xori") || 
(Instruction_Label_2 == "ori") || (Instruction_Label_2 == "andi") || (Instruction_Label_2 == "slli") || 
(Instruction_Label_2 == "srli") || (Instruction_Label_2 == "lb") || (Instruction_Label_2 == "lh") || 
(Instruction_Label_2 == "lbu") || (Instruction_Label_2 == "lhu") || (Instruction_Label_2 == "lw") ||
(Instruction_Label_2 == "slti") || (Instruction_Label_2 == "sltiu") || (Instruction_Label_2 == "sll") ||
(Instruction_Label_2 == "slt") || (Instruction_Label_2 == "sltu") || (Instruction_Label_2 == "srl") || 
(Instruction_Label_2 == "auipc") || (Instruction_Label_2 == "lui") || (Instruction_Label_2 == "rem") || 
(Instruction_Label_2 == "sra") || (Instruction_Label_2 == "srai") )
	//cout<<"------WB------"<<endl;
		Register[RD_INDEX_2] = RY;

	Register[0] = 0;
}

#endif
