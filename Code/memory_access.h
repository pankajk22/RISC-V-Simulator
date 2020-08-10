#ifndef MEMORY_ACCESS_H_
#define MEMORY_ACCESS_H_
#include<string>
#include<vector>
#include<bitset>
#include<stdint.h>
#include "register.h"

void memory_access()
{
	cout<<"MEMORY_ACCESS"<<endl;
	RD_INDEX_2=RD_INDEX_1; 
	Instruction_Label_2=Instruction_Label_1;
	if( (Instruction_Label_1 == "add") || (Instruction_Label_1 == "sub") || (Instruction_Label_1 == "and") || 
(Instruction_Label_1 == "or") || (Instruction_Label_1 == "xor") || (Instruction_Label_1 == "mul") || 
(Instruction_Label_1 == "div") || (Instruction_Label_1 == "addi") || (Instruction_Label_1 == "xori") || 
(Instruction_Label_1 == "ori") || (Instruction_Label_1 == "andi") || (Instruction_Label_1 == "slli") || 
(Instruction_Label_1 == "srli") || (Instruction_Label_1 == "slti") || (Instruction_Label_1 == "sltiu") ||
(Instruction_Label_1 == "sll") || (Instruction_Label_1 == "slt") || (Instruction_Label_1 == "sltu") || 
(Instruction_Label_1 == "srl") || (Instruction_Label_1 == "auipc") || (Instruction_Label_1 == "lui") ||
(Instruction_Label_1 == "rem") || (Instruction_Label_1 == "sra") || (Instruction_Label_1 == "srai") )
		RY = RZ;

	

	//for lb
	if(Instruction_Label_1 == "lb")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Data_Memory_Data[index], nullptr, 16);
			temp &= 255;
			bitset<32> Sign_extended_temp(temp);
			for(int i=8; i<32; i++)
				Sign_extended_temp[i] = Sign_extended_temp[7];

			temp = (int32_t)(Sign_extended_temp.to_ulong());
			RY = temp;
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Stack_Memory_Data[index], nullptr, 16);
			temp &= 255;
			bitset<32> Sign_extended_temp(temp);
			for(int i=8; i<32; i++)
				Sign_extended_temp[i] = Sign_extended_temp[7];

			temp = (int32_t)(Sign_extended_temp.to_ulong());
			RY = temp;
    	}
	}



	//for lh
	if(Instruction_Label_1 == "lh")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Data_Memory_Data[index], nullptr, 16);
			temp &= 65535;
			bitset<32> Sign_extended_temp(temp);
			for(int i=16; i<32; i++)
				Sign_extended_temp[i] = Sign_extended_temp[15];

			temp = (int32_t)(Sign_extended_temp.to_ulong());
			RY = temp;
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Stack_Memory_Data[index], nullptr, 16);
			temp &= 65535;
			bitset<32> Sign_extended_temp(temp);
			for(int i=16; i<32; i++)
				Sign_extended_temp[i] = Sign_extended_temp[15];

			temp = (int32_t)(Sign_extended_temp.to_ulong());
			RY = temp;
    	}
	}

	// for lw
	if(Instruction_Label_1 == "lw")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Data_Memory_Data[index], nullptr, 16);
			RY = temp;
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Stack_Memory_Data[index], nullptr, 16);
			RY = temp;
    	}
    	
	}

	//for lbu
	if(Instruction_Label_1 == "lbu")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Data_Memory_Data[index], nullptr, 16);
			temp &= 255;
			RY = temp;
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Stack_Memory_Data[index], nullptr, 16);
			temp &= 255;
			RY = temp;
    	}
	}

	//for lhu
	if(Instruction_Label_1 == "lhu")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Data_Memory_Data[index], nullptr, 16);
			temp &= 65535;
			RY = temp;
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Stack_Memory_Data[index], nullptr, 16);
			temp &= 65535;
			RY = temp;
    	}
	}

	// for sb
	if(Instruction_Label_1 == "sb")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();
    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			temp &= 255;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Data_Memory_Data[index] = stream1.str();
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			temp &= 255;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Stack_Memory_Data[index] = stream1.str();
    	}
	}

	// for sh
	if(Instruction_Label_1 == "sh")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();
    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			temp &= 65535;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Data_Memory_Data[index] = stream1.str();
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			temp &= 65535;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Stack_Memory_Data[index] = stream1.str();
    	}
	}


	// for sw
	if(Instruction_Label_1 == "sw")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Data_Memory_Data[index] = stream1.str();
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Stack_Memory_Data[index] = stream1.str();
    	}		
	}

	
}

#endif
