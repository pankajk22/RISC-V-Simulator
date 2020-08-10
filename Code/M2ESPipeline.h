#ifndef M2ESPIPELINE_H_
#define M2ESPIPELINE_H_
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
#include "clockcycle.h"
#include "pipeline.h"

void M2ESPipeline()
{
	stall++;
	if (flagi==1)
	RA=RY;
	if (flagi==2)
	RB=RY;
	if (flagi==3)
	{
		RA=RY;
		RB=RY;
	}
	
	flagi=0;
	
	if (IR!="ENDOFPROGRAM")
	{
		writeback();
		execute();
		decode();
		clk++;
		fetch();
	}
	
	else
	{
		writeback();
		execute();
		clk++;
		memory_access();
		clk++;
		writeback();
		clk++;
	}

	if (IR!="ENDOFPROGRAM")
	{
		memory_access();
		execute();
		decode();
		clk++;
		fetch();
	}	
	
	else
	{
		memory_access();
		if ((flagi==1)||(flagi==2)||(flagi==3))
		{
			M2ESPipeline();
			return;
		}
		execute();
		clk++;
		writeback();
		
	}
	
	while(IR!="ENDOFPROGRAM")
	{
//		cout<<"........10"<<endl;
		writeback();
		memory_access();
//		cout<<"ry="<<RY<<endl;
		execute();
//		cout<<"rz="<<RZ<<endl;
		decode();
//		cout<<"ra="<<RA<<"	rb="<<RB<<endl;
		clk++;
		fetch();
		
					
	}
		writeback();
		memory_access();
//		cout<<"ry="<<RY<<endl;
		execute();
//		cout<<"rz="<<RZ<<endl;
		clk++;
		writeback();
		memory_access();
//		cout<<"ry="<<RY<<endl;
		clk++;
		writeback();
		clk++;
}




#endif
