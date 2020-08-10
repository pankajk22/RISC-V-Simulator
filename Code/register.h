#ifndef REGISTER_H_
#define REGISTER_H_
#include<stdint.h>

int32_t Register[32];
string IR = "0";
string Instruction_Label = "not found";
string Instruction_Label_1 = "not found";
string Instruction_Label_2 = "not found";
string Instruction_Label_3 = "not found";
int32_t RA,RB,RD,RM,RZ,RY,IMMEDIATE,RD_INDEX,RD_INDEX_1,RD_INDEX_2;
int FLAG=0;//for m-->m case
int flagi=0;//for m-->e + stall case ; (rs1_index==rd_index_1 when 1) and (rs2_index==rd_index_1 when 2)
int iflag=0;

//bool Branch_Prediction; // 1=>taken, 0=>not-taken
bool Branch_Taken; //1=>Branch Actually Taken ; 2=>Banch Actually Not Taken
int state;//state in case of dyanamic branch prediction
int mispredictions;// no. of misredictions
bool is_BI=0;//if its a branch instruction

void init_Register()
{	for (int i=0; i<32; i++)
			Register[i] = 0;
	int32_t temp = std::stoul("0x7FFFFFF0", nullptr, 16);
	Register[2] = temp;
	temp = std::stoul("0x10000000", nullptr, 16);
	Register[3] = temp;
}

#endif
