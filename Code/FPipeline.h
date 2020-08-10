#ifndef FPIPELINE_H_
#define FPIPELINE_H_
#include<iostream>
#include<fstream>
#include<stdint.h>
#include "memory.h"
#include "register.h"
#include "pc.h"
#include "file_read.h"
#include "fetch.h"
#include "decode.h"
#include "execute.h"
#include "memory_access.h"
#include "writeback.h"
#include"clockcycle.h"
#include "M2ESPipeline.h"
#include "branchp.h"



void FPipeline()
{	
	brmp++;
	cout<<"**********************FLUSHED PIPELINE******************"<<endl;
	if (Branch_Taken==1)
	{
		cout<<"*******************************************************"<<endl;
		//new pc=im+pc-4
		int32_t temp1 = std::stoul(PC, nullptr, 16);
		temp1 = temp1+IMMEDIATE-8;
		
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp1;
		PC = stream.str();
		cout<<PC;
		cout<<"****************";
		
	}
	
	else
	{
				cout<<"*******************************************************"<<endl;
		//PC=PC-IMMEDIATE;
		//PC=PC+4;
		int32_t temp1 = std::stoul(PC, nullptr, 16);
		temp1 = temp1-IMMEDIATE+0;
		
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp1;
		PC = stream.str();
	}
	is_BI=0;
	clk++;
	fetch();
	
	if (IR!="ENDOFPROGRAM")
	{
		cout<<"...................1"<<endl;
		writeback();
		memory_access();
		decode();
		clk++;
		fetch();
	}
	else
	{
		cout<<"...................2"<<endl;
		writeback();
		memory_access();
		clk++;
		writeback();
		clk++;
		return;
	}
	
	if (IR!="ENDOFPROGRAM")
	{
		cout<<"...................3"<<endl;
		writeback();
		execute();
		if ((Branch_Taken!=getprediction())&&(is_BI==1))
		{
			cout<<"...................3...(a)"<<endl;
			is_BI=0;
			FPipeline();
			
			return;
		}
		decode();
		clk++;
		fetch();
	}
	else
	{
		cout<<"...................4"<<endl;
		writeback();
		execute();
		if ((Branch_Taken!=getprediction())&&(is_BI==1))
		{
			FPipeline();
			is_BI=0;
			return;
		}
		clk++;
		memory_access();
		clk++;
		writeback();
		clk++;
	}
	
	while(IR!="ENDOFPROGRAM")
	{
		cout<<"........10"<<endl;
		writeback();
		memory_access();
		if ((flagi==1)||(flagi==2)||(flagi==3))
		{
			M2ESPipeline();
			return;
		}
		//cout<<"ry="<<RY<<endl;
		execute();
		if ((Branch_Taken!=getprediction())&&(is_BI==1))
		{
			FPipeline();
			is_BI=0;
			return;
		}//cout<<"rz="<<RZ<<endl;
		decode();
		//cout<<"ra="<<RA<<"	rb="<<RB<<endl;
		clk++;
		fetch();
		
	}
	
		writeback();
		memory_access();
		if ((flagi==1)||(flagi==2)||(flagi==3))
		{
			M2ESPipeline();
			return;
		}
		//cout<<"ry="<<RY<<endl;
		execute();
		if ((Branch_Taken!=getprediction())&&(is_BI==1))
		{
			FPipeline();
			is_BI=0;
			return;
		}//cout<<"rz="<<RZ<<endl;
		clk++;
		writeback();
		memory_access();
		if ((flagi==1)||(flagi==2)||(flagi==3))
		{
			M2ESPipeline();
			return;
		}
		//cout<<"ry="<<RY<<endl;
		clk++;
		writeback();
		clk++;

	is_BI=0;
}

#endif
