#ifndef DECODE_H_
#define DECODE_H_
#include<sstream>
#include<bitset>
#include<string>
#include<stdint.h>
#include "register.h"
#include"clockcycle.h"
#include"branchp.h"
#include"knobs.h"


void decode()
{

	cout<<"DECODE"<<endl;
	int rs1_index;
	int rs2_index;

	string temp = IR;
    stringstream ss;
    ss << hex << temp;
    unsigned n;
    ss >> n;
    if(knob==1)
    {
    	if(iknob==3)
    	{
    bitset<32> machine_code(n);
    bitset<32> opcode_extraction(127);
    bitset<32> machine_code_opcode;
    machine_code_opcode = machine_code & opcode_extraction;
    bitset<32> func3_extraction(28672);
    bitset<32> machine_code_func3;
    machine_code_func3 = machine_code & func3_extraction;
    bitset<32> func7_extraction(4261412864);
    bitset<32> machine_code_func7;
    machine_code_func7 = machine_code & func7_extraction;
    bitset<32> rs1_extraction(1015808);
    bitset<32> machine_code_rs1;
    machine_code_rs1 = machine_code & rs1_extraction;
    machine_code_rs1 >>= 15;
    bitset<32> rs2_extraction(32505856);
    bitset<32> machine_code_rs2;
    machine_code_rs2 = machine_code & rs2_extraction;
    machine_code_rs2 >>= 20;
    bitset<32> rd_extraction(3968);
    bitset<32> machine_code_rd;
    machine_code_rd = machine_code & rd_extraction;
    machine_code_rd >>= 7;
    // IMMEDIATE for I-type
    bitset<32> imm_extraction(4293918720);
    bitset<32> machine_code_imm;
    machine_code_imm = machine_code & imm_extraction;
    machine_code_imm >>= 20;
    bitset<32> machine_code_imm_unsigned;
    machine_code_imm_unsigned = machine_code_imm; 
    //sign extension
    for(int i=12; i<16; i++)
			machine_code_imm[i] = machine_code_imm[11];

    // R-type
    //for add
    bitset<32> opcode(51);
    bitset<32> func3(0);
    bitset<32> func7(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "add";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}


    //for sub 
    opcode = bitset<32>(51);
    func3 = bitset<32>(0);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sub";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    	}

    //for and
    opcode = bitset<32>(51);
    func3 = bitset<32>(28672);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "and";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for or
    opcode = bitset<32>(51);
    func3 = bitset<32>(24576);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "or";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for xor
    opcode = bitset<32>(51);
    func3 = bitset<32>(16384);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "xor";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for sll
    opcode = bitset<32>(51);
    func3 = bitset<32>(4096);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sll";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for srl
    opcode = bitset<32>(51);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "srl";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for sra
    opcode = bitset<32>(51);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sra";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for slt
    opcode = bitset<32>(51);
    func3 = bitset<32>(8192);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "slt";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for sltu
    opcode = bitset<32>(51);
    func3 = bitset<32>(12288);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sltu";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }




	//for mul
    opcode = bitset<32>(51);
    func3 = bitset<32>(0);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "mul";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for div
    opcode = bitset<32>(51);
    func3 = bitset<32>(16384);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "div";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for rem
    opcode = bitset<32>(51);
    func3 = bitset<32>(24576);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "rem";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}


    //I-type
    //for addi
    opcode = bitset<32>(19);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "addi";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for xori
    opcode = bitset<32>(19);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "xori";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for ori
    opcode = bitset<32>(19);
    func3 = bitset<32>(24576);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "ori";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for andi
    opcode = bitset<32>(19);
    func3 = bitset<32>(28672);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "andi";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for slli
    opcode = bitset<32>(19);
    func3 = bitset<32>(4096);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "slli";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(slli)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for srli
    opcode = bitset<32>(19);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "srli";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(srli)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for srai
    opcode = bitset<32>(19);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "srai";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(srai)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for slti
    opcode = bitset<32>(19);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "slti";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for sltiu
    opcode = bitset<32>(19);
    func3 = bitset<32>(12288);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sltiu";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	uint16_t temp = (uint16_t)imm_value;
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for lb
    opcode = bitset<32>(3);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lb";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lh
    opcode = bitset<32>(3);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lh";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for lw
    opcode = bitset<32>(3);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lw";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lbu
    opcode = bitset<32>(3);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lbu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lhu
    opcode = bitset<32>(3);
    func3 = bitset<32>(20480);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lhu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for jalr
    opcode = bitset<32>(103);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "jalr";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //S-type
    //for sw
    opcode = bitset<32>(35);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sw";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;

    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}
	
    //for sb
    opcode = bitset<32>(35);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sb";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;
   
    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];	

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}

	//for sh
    opcode = bitset<32>(35);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sh";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;
   
    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];	

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}
	
    //UJ-type
    //for jal
    opcode = bitset<32>(111);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "jal";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(2145386496);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [21:30] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(1048576);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[20] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(1044480);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[12:19] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 20;
		machine_code_imm_part2 = machine_code_imm_part2 >> 9;
		machine_code_imm_part4 = machine_code_imm_part4 >> 11;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=21; i<32; i++)
			machine_code_imm_final[i] = machine_code_imm_final[20];	

		int32_t imm_value = (int32_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //U-type
    //for auipc
    opcode = bitset<32>(23);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "auipc";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_offset;
		bitset<32> machine_code_offset_extraction(4294963200);
		machine_code_offset = machine_code & machine_code_offset_extraction; //[12:31]
		int bound_check = (int)(machine_code_offset.to_ulong()); 
		bound_check = bound_check >> 12;
		if(bound_check < 0 || bound_check > 1048575)
    	{	cout<<"Immediate value out of range(auipc)"<<endl;
    		exit(1);
    	}
		int imm_value = (int)(machine_code_offset.to_ulong());
		IMMEDIATE = imm_value;
	}

	//for lui
    opcode = bitset<32>(55);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "lui";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_offset;
		bitset<32> machine_code_offset_extraction(4294963200);
		machine_code_offset = machine_code & machine_code_offset_extraction; //[12:31]
		int bound_check = (int)(machine_code_offset.to_ulong()); 
		bound_check = bound_check >> 12;
		if(bound_check < 0 || bound_check > 1048575)
    	{	cout<<"Immediate value out of range(lui)"<<endl;
    		exit(1);
    	}
		int imm_value = (int)(machine_code_offset.to_ulong());
		IMMEDIATE = imm_value;
	}

    //SB-type
    //for beq
    opcode = bitset<32>(99);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "beq";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bne
    opcode = bitset<32>(99);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bne";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for blt
    opcode = bitset<32>(99);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "blt";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bge
    opcode = bitset<32>(99);
    func3 = bitset<32>(20480);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bge";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bltu
    opcode = bitset<32>(99);
    func3 = bitset<32>(24576);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bltu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bgeu
    opcode = bitset<32>(99);
    func3 = bitset<32>(28672);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bgeu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}


/***********************TYPE OF DATA HAZARD AND PROPER ACTION ON IT****************************/

	if (rs1_index==RD_INDEX_1)
	{
		if(Instruction_Label_1=="auipc")
		{
			iflag=1;
		}
		if((Instruction_Label=="add")||(Instruction_Label=="sub")||(Instruction_Label=="addi")||(Instruction_Label=="and")||(Instruction_Label=="or")||(Instruction_Label=="xor")||(Instruction_Label=="sll")||(Instruction_Label=="srl")||(Instruction_Label=="sra")||(Instruction_Label=="slt")||(Instruction_Label=="sltu")||(Instruction_Label=="mul")||(Instruction_Label=="div")||(Instruction_Label=="rem")||(Instruction_Label=="xori")||(Instruction_Label=="ori")||(Instruction_Label=="andi")||(Instruction_Label=="slli")||(Instruction_Label=="srli")||(Instruction_Label=="srai")||(Instruction_Label=="slti")||(Instruction_Label=="sltiu"))
		{
			if((Instruction_Label_1=="lb")||(Instruction_Label_1=="lh")||(Instruction_Label_1=="lw")||(Instruction_Label_1=="lbu")||(Instruction_Label_1=="lhu")||(Instruction_Label_1=="lui"))
			{
				flagi=1;
				//cout<<"M->E and STALL...1"<<endl;
				datadep++;
				//stall++;
				//M-->E CASE
			}
			else
			{
				if((Instruction_Label_1=="add")||(Instruction_Label_1=="sub")||(Instruction_Label_1=="addi")||(Instruction_Label_1=="and")||(Instruction_Label_1=="or")||(Instruction_Label_1=="xor")||(Instruction_Label_1=="sll")||(Instruction_Label_1=="srl")||(Instruction_Label_1=="sra")||(Instruction_Label_1=="slt")||(Instruction_Label_1=="sltu")||(Instruction_Label_1=="mul")||(Instruction_Label_1=="div")||(Instruction_Label_1=="rem")||(Instruction_Label_1=="xori")||(Instruction_Label_1=="ori")||(Instruction_Label_1=="andi")||(Instruction_Label_1=="slli")||(Instruction_Label_1=="srli")||(Instruction_Label_1=="srai")||(Instruction_Label_1=="slti")||(Instruction_Label_1=="sltiu"))
				{
				RA=RZ;
				datadep++;
				//cout<<"E->E type forwarding...1"<<endl;
				}
			}
			
		}
	}
	
	if (rs1_index==RD_INDEX_2)
	{
		if((Instruction_Label=="add")||(Instruction_Label=="sub")||(Instruction_Label=="addi")||(Instruction_Label=="and")||(Instruction_Label=="or")||(Instruction_Label=="xor")||(Instruction_Label=="sll")||(Instruction_Label=="srl")||(Instruction_Label=="sra")||(Instruction_Label=="slt")||(Instruction_Label=="sltu")||(Instruction_Label=="mul")||(Instruction_Label=="div")||(Instruction_Label=="rem")||(Instruction_Label=="xori")||(Instruction_Label=="ori")||(Instruction_Label=="andi")||(Instruction_Label=="slli")||(Instruction_Label=="srli")||(Instruction_Label=="srai")||(Instruction_Label=="slti")||(Instruction_Label=="sltiu"))
		{				
			datadep++;	
			RA=RY;
			//cout<<"M->E type forwarding...1"<<endl;
		}
	}
	if (rs2_index==RD_INDEX_1)
	{
		if((Instruction_Label=="add")||(Instruction_Label=="sub")||(Instruction_Label=="addi")||(Instruction_Label=="and")||(Instruction_Label=="or")||(Instruction_Label=="xor")||(Instruction_Label=="sll")||(Instruction_Label=="srl")||(Instruction_Label=="sra")||(Instruction_Label=="slt")||(Instruction_Label=="sltu")||(Instruction_Label=="mul")||(Instruction_Label=="div")||(Instruction_Label=="rem")||(Instruction_Label=="xori")||(Instruction_Label=="ori")||(Instruction_Label=="andi")||(Instruction_Label=="slli")||(Instruction_Label=="srli")||(Instruction_Label=="srai")||(Instruction_Label=="slti")||(Instruction_Label=="sltiu"))
		{
			if((Instruction_Label_1=="lb")||(Instruction_Label_1=="lh")||(Instruction_Label_1=="lw")||(Instruction_Label_1=="lbu")||(Instruction_Label_1=="lhu")||(Instruction_Label_1=="lui"))
			{
				flagi=2;
				if (rs1_index==rs2_index)
				flagi=3;
				//cout<<"M->E and STALL...2"<<endl;
				datadep++;
				//stall++;
				//M-->E CASE
			}
			else
			{
				if((Instruction_Label_1=="add")||(Instruction_Label_1=="sub")||(Instruction_Label_1=="addi")||(Instruction_Label_1=="and")||(Instruction_Label_1=="or")||(Instruction_Label_1=="xor")||(Instruction_Label_1=="sll")||(Instruction_Label_1=="srl")||(Instruction_Label_1=="sra")||(Instruction_Label_1=="slt")||(Instruction_Label_1=="sltu")||(Instruction_Label_1=="mul")||(Instruction_Label_1=="div")||(Instruction_Label_1=="rem")||(Instruction_Label_1=="xori")||(Instruction_Label_1=="ori")||(Instruction_Label_1=="andi")||(Instruction_Label_1=="slli")||(Instruction_Label_1=="srli")||(Instruction_Label_1=="srai")||(Instruction_Label_1=="slti")||(Instruction_Label_1=="sltiu"))
				{
				RB=RZ;
				datadep++;
				//cout<<"E->E type forwarding...2"<<endl;
				}
			}
		}
	}
	if (rs2_index==RD_INDEX_2)
	{
		if((Instruction_Label=="add")||(Instruction_Label=="sub")||(Instruction_Label=="addi")||(Instruction_Label=="and")||(Instruction_Label=="or")||(Instruction_Label=="xor")||(Instruction_Label=="sll")||(Instruction_Label=="srl")||(Instruction_Label=="sra")||(Instruction_Label=="slt")||(Instruction_Label=="sltu")||(Instruction_Label=="mul")||(Instruction_Label=="div")||(Instruction_Label=="rem")||(Instruction_Label=="xori")||(Instruction_Label=="ori")||(Instruction_Label=="andi")||(Instruction_Label=="slli")||(Instruction_Label=="srli")||(Instruction_Label=="srai")||(Instruction_Label=="slti")||(Instruction_Label=="sltiu"))
		{
			RB=RY;
			datadep++;
			//cout<<"M->E type forwarding...2"<<endl;
		}
	}
	
	if(RD_INDEX==RD_INDEX_1)
	{	//cout<<"***********************************************************************************"<<endl;
		if((Instruction_Label_1=="lb")||(Instruction_Label_1=="lh")||(Instruction_Label_1=="lw")||(Instruction_Label_1=="lbu")||(Instruction_Label_1=="lhu")||(Instruction_Label_1=="lui"))
		{
			if((Instruction_Label=="sw")||(Instruction_Label=="sb")||(Instruction_Label=="sh"))
			{
				//M-->M CASE
				FLAG=1;
				//cout<<"M->M CASE.................."<<endl;
				datadep++;
			}
		}
		
		
	}
	
	
	
	
	/*cout<<"rs1_index="<<rs1_index<<"	rs2_index="<<rs2_index<<"	rd_index_1="<<RD_INDEX_1<<"	rd_index_2="<<RD_INDEX_2<<"	RD_INDEX="<<RD_INDEX<<endl;*/
	
	
	/**************************BRANCH PREDICTION***************************/
	if((Instruction_Label=="jal")||(Instruction_Label=="jalr"))
	{
		//new pc=im+pc-4
		int32_t temp1 = std::stoul(PC, nullptr, 16);
		temp1= temp1+IMMEDIATE-4;
		
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp1;
		PC = stream.str();
		
	}
	if((Instruction_Label=="beq")||(Instruction_Label=="bne")||(Instruction_Label=="blt")||(Instruction_Label=="bge")||(Instruction_Label=="bltu")||(Instruction_Label=="bgeu"))
	{
		if(getprediction()==true)
		{
			//new pc=im+pc-4
			int32_t temp1 = std::stoul(PC, nullptr, 16);
			temp1 = temp1+IMMEDIATE-4;
			
			std::stringstream stream;
			stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp1;
			PC = stream.str();
			
		}
		
	}
	
		cout<<"*****INSL***"<<Instruction_Label_1<<endl;
	if((Instruction_Label=="beq")||(Instruction_Label=="bne")||(Instruction_Label=="blt")||(Instruction_Label=="bge")||(Instruction_Label=="bltu")||(Instruction_Label=="bgeu"))
	{
		is_BI=1;//
	}
	
		else
		{
		is_BI=0;
		}
		cout<<"**********BI***********"<<is_BI<<endl;
	}
	else
	{
		
		bitset<32> machine_code(n);
    bitset<32> opcode_extraction(127);
    bitset<32> machine_code_opcode;
    machine_code_opcode = machine_code & opcode_extraction;
    bitset<32> func3_extraction(28672);
    bitset<32> machine_code_func3;
    machine_code_func3 = machine_code & func3_extraction;
    bitset<32> func7_extraction(4261412864);
    bitset<32> machine_code_func7;
    machine_code_func7 = machine_code & func7_extraction;
    bitset<32> rs1_extraction(1015808);
    bitset<32> machine_code_rs1;
    machine_code_rs1 = machine_code & rs1_extraction;
    machine_code_rs1 >>= 15;
    bitset<32> rs2_extraction(32505856);
    bitset<32> machine_code_rs2;
    machine_code_rs2 = machine_code & rs2_extraction;
    machine_code_rs2 >>= 20;
    bitset<32> rd_extraction(3968);
    bitset<32> machine_code_rd;
    machine_code_rd = machine_code & rd_extraction;
    machine_code_rd >>= 7;
    // IMMEDIATE for I-type
    bitset<32> imm_extraction(4293918720);
    bitset<32> machine_code_imm;
    machine_code_imm = machine_code & imm_extraction;
    machine_code_imm >>= 20;
    bitset<32> machine_code_imm_unsigned;
    machine_code_imm_unsigned = machine_code_imm; 
    //sign extension
    for(int i=12; i<16; i++)
			machine_code_imm[i] = machine_code_imm[11];

    // R-type
    //for add
    bitset<32> opcode(51);
    bitset<32> func3(0);
    bitset<32> func7(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "add";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}


    //for sub 
    opcode = bitset<32>(51);
    func3 = bitset<32>(0);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sub";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    	}

    //for and
    opcode = bitset<32>(51);
    func3 = bitset<32>(28672);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "and";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for or
    opcode = bitset<32>(51);
    func3 = bitset<32>(24576);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "or";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for xor
    opcode = bitset<32>(51);
    func3 = bitset<32>(16384);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "xor";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for sll
    opcode = bitset<32>(51);
    func3 = bitset<32>(4096);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sll";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for srl
    opcode = bitset<32>(51);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "srl";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for sra
    opcode = bitset<32>(51);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sra";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for slt
    opcode = bitset<32>(51);
    func3 = bitset<32>(8192);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "slt";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for sltu
    opcode = bitset<32>(51);
    func3 = bitset<32>(12288);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sltu";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }




	//for mul
    opcode = bitset<32>(51);
    func3 = bitset<32>(0);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "mul";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for div
    opcode = bitset<32>(51);
    func3 = bitset<32>(16384);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "div";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for rem
    opcode = bitset<32>(51);
    func3 = bitset<32>(24576);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "rem";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}


    //I-type
    //for addi
    opcode = bitset<32>(19);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "addi";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for xori
    opcode = bitset<32>(19);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "xori";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for ori
    opcode = bitset<32>(19);
    func3 = bitset<32>(24576);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "ori";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for andi
    opcode = bitset<32>(19);
    func3 = bitset<32>(28672);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "andi";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for slli
    opcode = bitset<32>(19);
    func3 = bitset<32>(4096);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "slli";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(slli)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for srli
    opcode = bitset<32>(19);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "srli";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(srli)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for srai
    opcode = bitset<32>(19);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "srai";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(srai)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for slti
    opcode = bitset<32>(19);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "slti";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for sltiu
    opcode = bitset<32>(19);
    func3 = bitset<32>(12288);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sltiu";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	uint16_t temp = (uint16_t)imm_value;
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for lb
    opcode = bitset<32>(3);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lb";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lh
    opcode = bitset<32>(3);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lh";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for lw
    opcode = bitset<32>(3);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lw";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lbu
    opcode = bitset<32>(3);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lbu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lhu
    opcode = bitset<32>(3);
    func3 = bitset<32>(20480);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lhu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for jalr
    opcode = bitset<32>(103);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "jalr";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //S-type
    //for sw
    opcode = bitset<32>(35);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sw";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;

    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}
	
    //for sb
    opcode = bitset<32>(35);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sb";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;
   
    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];	

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}

	//for sh
    opcode = bitset<32>(35);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sh";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;
   
    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];	

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}
	
    //UJ-type
    //for jal
    opcode = bitset<32>(111);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "jal";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(2145386496);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [21:30] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(1048576);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[20] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(1044480);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[12:19] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 20;
		machine_code_imm_part2 = machine_code_imm_part2 >> 9;
		machine_code_imm_part4 = machine_code_imm_part4 >> 11;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=21; i<32; i++)
			machine_code_imm_final[i] = machine_code_imm_final[20];	

		int32_t imm_value = (int32_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //U-type
    //for auipc
    opcode = bitset<32>(23);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "auipc";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_offset;
		bitset<32> machine_code_offset_extraction(4294963200);
		machine_code_offset = machine_code & machine_code_offset_extraction; //[12:31]
		int bound_check = (int)(machine_code_offset.to_ulong()); 
		bound_check = bound_check >> 12;
		if(bound_check < 0 || bound_check > 1048575)
    	{	cout<<"Immediate value out of range(auipc)"<<endl;
    		exit(1);
    	}
		int imm_value = (int)(machine_code_offset.to_ulong());
		IMMEDIATE = imm_value;
	}

	//for lui
    opcode = bitset<32>(55);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "lui";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_offset;
		bitset<32> machine_code_offset_extraction(4294963200);
		machine_code_offset = machine_code & machine_code_offset_extraction; //[12:31]
		int bound_check = (int)(machine_code_offset.to_ulong()); 
		bound_check = bound_check >> 12;
		if(bound_check < 0 || bound_check > 1048575)
    	{	cout<<"Immediate value out of range(lui)"<<endl;
    		exit(1);
    	}
		int imm_value = (int)(machine_code_offset.to_ulong());
		IMMEDIATE = imm_value;
	}

    //SB-type
    //for beq
    opcode = bitset<32>(99);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "beq";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bne
    opcode = bitset<32>(99);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bne";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for blt
    opcode = bitset<32>(99);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "blt";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bge
    opcode = bitset<32>(99);
    func3 = bitset<32>(20480);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bge";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bltu
    opcode = bitset<32>(99);
    func3 = bitset<32>(24576);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bltu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bgeu
    opcode = bitset<32>(99);
    func3 = bitset<32>(28672);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bgeu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}	
		
	}
	}
	
	else
	{
		
		bitset<32> machine_code(n);
    bitset<32> opcode_extraction(127);
    bitset<32> machine_code_opcode;
    machine_code_opcode = machine_code & opcode_extraction;
    bitset<32> func3_extraction(28672);
    bitset<32> machine_code_func3;
    machine_code_func3 = machine_code & func3_extraction;
    bitset<32> func7_extraction(4261412864);
    bitset<32> machine_code_func7;
    machine_code_func7 = machine_code & func7_extraction;
    bitset<32> rs1_extraction(1015808);
    bitset<32> machine_code_rs1;
    machine_code_rs1 = machine_code & rs1_extraction;
    machine_code_rs1 >>= 15;
    bitset<32> rs2_extraction(32505856);
    bitset<32> machine_code_rs2;
    machine_code_rs2 = machine_code & rs2_extraction;
    machine_code_rs2 >>= 20;
    bitset<32> rd_extraction(3968);
    bitset<32> machine_code_rd;
    machine_code_rd = machine_code & rd_extraction;
    machine_code_rd >>= 7;
    // IMMEDIATE for I-type
    bitset<32> imm_extraction(4293918720);
    bitset<32> machine_code_imm;
    machine_code_imm = machine_code & imm_extraction;
    machine_code_imm >>= 20;
    bitset<32> machine_code_imm_unsigned;
    machine_code_imm_unsigned = machine_code_imm; 
    //sign extension
    for(int i=12; i<16; i++)
			machine_code_imm[i] = machine_code_imm[11];

    // R-type
    //for add
    bitset<32> opcode(51);
    bitset<32> func3(0);
    bitset<32> func7(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "add";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}


    //for sub 
    opcode = bitset<32>(51);
    func3 = bitset<32>(0);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sub";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    	}

    //for and
    opcode = bitset<32>(51);
    func3 = bitset<32>(28672);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "and";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for or
    opcode = bitset<32>(51);
    func3 = bitset<32>(24576);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "or";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for xor
    opcode = bitset<32>(51);
    func3 = bitset<32>(16384);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "xor";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for sll
    opcode = bitset<32>(51);
    func3 = bitset<32>(4096);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sll";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for srl
    opcode = bitset<32>(51);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "srl";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for sra
    opcode = bitset<32>(51);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sra";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for slt
    opcode = bitset<32>(51);
    func3 = bitset<32>(8192);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "slt";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for sltu
    opcode = bitset<32>(51);
    func3 = bitset<32>(12288);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sltu";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }




	//for mul
    opcode = bitset<32>(51);
    func3 = bitset<32>(0);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "mul";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for div
    opcode = bitset<32>(51);
    func3 = bitset<32>(16384);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "div";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for rem
    opcode = bitset<32>(51);
    func3 = bitset<32>(24576);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "rem";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}


    //I-type
    //for addi
    opcode = bitset<32>(19);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "addi";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for xori
    opcode = bitset<32>(19);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "xori";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for ori
    opcode = bitset<32>(19);
    func3 = bitset<32>(24576);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "ori";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for andi
    opcode = bitset<32>(19);
    func3 = bitset<32>(28672);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "andi";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for slli
    opcode = bitset<32>(19);
    func3 = bitset<32>(4096);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "slli";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(slli)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for srli
    opcode = bitset<32>(19);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "srli";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(srli)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for srai
    opcode = bitset<32>(19);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "srai";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(srai)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for slti
    opcode = bitset<32>(19);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "slti";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for sltiu
    opcode = bitset<32>(19);
    func3 = bitset<32>(12288);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sltiu";
    	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	uint16_t temp = (uint16_t)imm_value;
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for lb
    opcode = bitset<32>(3);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lb";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lh
    opcode = bitset<32>(3);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lh";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for lw
    opcode = bitset<32>(3);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lw";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lbu
    opcode = bitset<32>(3);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lbu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lhu
    opcode = bitset<32>(3);
    func3 = bitset<32>(20480);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lhu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for jalr
    opcode = bitset<32>(103);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "jalr";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //S-type
    //for sw
    opcode = bitset<32>(35);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sw";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;

    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}
	
    //for sb
    opcode = bitset<32>(35);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sb";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;
   
    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];	

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}

	//for sh
    opcode = bitset<32>(35);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sh";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;
   
    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];	

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}
	
    //UJ-type
    //for jal
    opcode = bitset<32>(111);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "jal";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(2145386496);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [21:30] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(1048576);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[20] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(1044480);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[12:19] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 20;
		machine_code_imm_part2 = machine_code_imm_part2 >> 9;
		machine_code_imm_part4 = machine_code_imm_part4 >> 11;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=21; i<32; i++)
			machine_code_imm_final[i] = machine_code_imm_final[20];	

		int32_t imm_value = (int32_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //U-type
    //for auipc
    opcode = bitset<32>(23);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "auipc";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_offset;
		bitset<32> machine_code_offset_extraction(4294963200);
		machine_code_offset = machine_code & machine_code_offset_extraction; //[12:31]
		int bound_check = (int)(machine_code_offset.to_ulong()); 
		bound_check = bound_check >> 12;
		if(bound_check < 0 || bound_check > 1048575)
    	{	cout<<"Immediate value out of range(auipc)"<<endl;
    		exit(1);
    	}
		int imm_value = (int)(machine_code_offset.to_ulong());
		IMMEDIATE = imm_value;
	}

	//for lui
    opcode = bitset<32>(55);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "lui";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_offset;
		bitset<32> machine_code_offset_extraction(4294963200);
		machine_code_offset = machine_code & machine_code_offset_extraction; //[12:31]
		int bound_check = (int)(machine_code_offset.to_ulong()); 
		bound_check = bound_check >> 12;
		if(bound_check < 0 || bound_check > 1048575)
    	{	cout<<"Immediate value out of range(lui)"<<endl;
    		exit(1);
    	}
		int imm_value = (int)(machine_code_offset.to_ulong());
		IMMEDIATE = imm_value;
	}

    //SB-type
    //for beq
    opcode = bitset<32>(99);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "beq";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bne
    opcode = bitset<32>(99);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bne";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for blt
    opcode = bitset<32>(99);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "blt";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bge
    opcode = bitset<32>(99);
    func3 = bitset<32>(20480);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bge";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bltu
    opcode = bitset<32>(99);
    func3 = bitset<32>(24576);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bltu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bgeu
    opcode = bitset<32>(99);
    func3 = bitset<32>(28672);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bgeu";
	rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}	
	}	
	
}


#endif
