#ifndef MEMORY_H_
#define MEMORY_H_
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

string Instruction_Memory_Address[4000];
string Instruction_Memory_Data[4000];
string Data_Memory_Address[1000];
string Data_Memory_Data[1000];
string Stack_Memory_Address[1000];
string Stack_Memory_Data[1000];

void init_Instruction_Memory()
{	Instruction_Memory_Address[0] = "0x00000000";
	Instruction_Memory_Data[0] = "$";
	for (int i = 1; i < 4000; i++)
		{	int32_t temp = std::stoul(Instruction_Memory_Address[i-1], nullptr, 16);
			temp += 4;
			std::stringstream stream;
			stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
   			Instruction_Memory_Address[i] = stream.str();
			Instruction_Memory_Data[i] = "$";
		}
}

void init_Data_Memory()
{	Data_Memory_Address[0] = "0x10000000";
	Data_Memory_Data[0] = "$";
	for (int i = 1; i < 1000; i++)
		{	int32_t temp = std::stoul(Data_Memory_Address[i-1], nullptr, 16);
			temp += 4;
			std::stringstream stream;
			stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
   			Data_Memory_Address[i] = stream.str();
			Data_Memory_Data[i] = "$";
		}
}

void init_Stack_Memory()
{	Stack_Memory_Address[0] = "0x7ffffffc";
	Stack_Memory_Data[0] = "$";
	for (int i = 1; i < 1000; i++)
		{	int32_t temp = std::stoul(Stack_Memory_Address[i-1], nullptr, 16);
			temp -= 4;
			std::stringstream stream;
			stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
   			Stack_Memory_Address[i] = stream.str();
			Stack_Memory_Data[i] = "$";
		}
		/*
		for(int x=0;x<40;x++)
		cout<<Instruction_Memory_Address[x]<<" "<<Instruction_Memory_Data[x]<<endl;
	cout<<"*********************************************"<<endl;
for(int x=0;x<40;x++)
		cout<<Data_Memory_Address[x]<<" "<<Data_Memory_Data[x]<<endl;
	cout<<"*********************************************"<<endl;
for(int x=0;x<40;x++)
		cout<<Stack_Memory_Address[x]<<" "<<Stack_Memory_Data[x]<<endl;
	cout<<"*********************************************"<<endl;
	*/
}




#endif