#ifndef FETCH_H_
#define FETCH_H_
#include<algorithm>
#include<sstream>
#include<stdint.h>
#include "memory.h"
#include "register.h"
#include "pc.h"

void fetch()
{	
	cout<<"FETCH"<<endl;	
	string program_counter = PC;
	int index;
	for(index=0; index<4000; index++)
	{	if(Instruction_Memory_Address[index] == program_counter)
			break;
	}

	IR = Instruction_Memory_Data[index];
	//cout<<PC<<" "<<IR<<endl;  // PC and IR check
	int32_t temp = std::stoul(program_counter, nullptr, 16);
	temp = temp + 4;
	std::stringstream stream;
	stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    PC = stream.str();
    //cout<<program_counter<<endl; 
}

#endif
