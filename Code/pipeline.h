#ifndef PIPELINE_H_
#define PIPELINE_H_
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
#include "FPipeline.h"


using namespace std;

void Pipeline ()
{	
	fetch();
	//cout<<"........0...."<<IR<<endl;
	if (IR!="ENDOFPROGRAM")
	{
		clk++;
		decode();
		//cout<<"ra="<<RA<<"	rb="<<RB<<endl;
		clk++;
		fetch();
		//cout<<"........1...."<<IR<<endl;
	}
	
	else
	return;
	
	if(IR!="ENDOFPROGRAM")
	{
		execute();
		if ((Branch_Taken!=getprediction())&&(is_BI==1))
		{
			FPipeline();
			is_BI=0;
			return;
		}
		//cout<<"rz="<<RZ<<endl;
		decode();
		//cout<<"ra="<<RA<<"	rb="<<RB<<endl;
		clk++;
		fetch();
		//cout<<"........2....."<<IR<<endl;
		
	}
	else
	{
		execute();
		if ((Branch_Taken!=getprediction())&&(is_BI==1))
		{
			FPipeline();
			is_BI=0;
			return;
		}
		//cout<<"rz="<<RZ<<endl;
		clk++;
		memory_access();
		//cout<<"ry="<<RY<<endl;
		clk++;
		writeback();
		clk++;
		return ;		
	}	
	if(IR!="ENDOFPROGRAM")
	{	
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
		}
		//cout<<"rz="<<RZ<<endl;
		decode();
		//cout<<"ra="<<RA<<"	rb="<<RB<<endl;
		clk++;
		fetch();
		//cout<<"........4...."<<IR<<endl;
		
					
	}
	else
	{
		//cout<<"........5"<<endl;
		
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
		}
		//cout<<"rz="<<RZ<<endl;
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
		return ;
			
	}
	if(IR!="ENDOFPROGRAM")
	{
		//cout<<"........6"<<endl;
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
		}
		//cout<<"rz="<<RZ<<endl;
		decode();
		//cout<<"ra="<<RA<<"	rb="<<RB<<endl;
		clk++;
		fetch();
		
					
	}
	else
	{	
		//cout<<"........7"<<endl;
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
		}
		//cout<<"rz="<<RZ<<endl;
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
		return ;
			
	}
	if(IR!="ENDOFPROGRAM")
	{
		//cout<<"........8"<<endl;
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
		}
		//cout<<"rz="<<RZ<<endl;
		decode();
		//cout<<"ra="<<RA<<"	rb="<<RB<<endl;
		clk++;
		fetch();

					
	}
	
	else
	{
		//cout<<"........9"<<endl;
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
		}
		//cout<<"rz="<<RZ<<endl;
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
		return ;
			
	}
	while(IR!="ENDOFPROGRAM")
	{
		//cout<<"........10"<<endl;
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
		}
		//cout<<"rz="<<RZ<<endl;
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
		}
		//cout<<"rz="<<RZ<<endl;
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
		
}
#endif
