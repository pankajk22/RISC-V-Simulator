#ifndef FILE_READ_H_
#define FILE_READ_H_
#include<iostream>
#include<fstream>
#include<stdint.h>
#include "memory.h"
using namespace std;

void file_read(char* file_name)
{	ifstream file(file_name);
	string first,second;

	if(!file)
	{	cout<<"Error opening input file"<<endl;
		exit(1);
	}

	int32_t data_segment = std::stoul("0x10000000", nullptr, 16);
	while(file>>first>>second)
	{	int32_t hex_value = std::stoul(first, nullptr, 16);
		if(hex_value < data_segment)
		{   int32_t temp = std::stoul(first, nullptr, 16);
			temp /= 4;				// index
			Instruction_Memory_Data[temp] = second;
		}
		else
		{ 	int32_t temp = std::stoul(first, nullptr, 16);
			temp = temp - data_segment;
			temp /= 4;				// index
		 	Data_Memory_Data[temp] = second;	
		}

	}
	/*
	for(int x=0;x<40;x++)
		cout<<Instruction_Memory_Address[x]<<" "<<Instruction_Memory_Data[x]<<endl;
	cout<<"*********************************************"<<endl;
for(int x=0;x<40;x++)
		cout<<Data_Memory_Address[x]<<" "<<Data_Memory_Data[x]<<endl;
	cout<<"*********************************************"<<endl;*/
}

#endif