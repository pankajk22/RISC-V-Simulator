# RISC-V-Simulator
*** CS204(computer architecture) - Project ***
				----------------------------------------------

Group members (entry number)-
	*Akash (2017CSB1066)
	*Ankit (20107CSB1069)
	*Shivang (20107CSB1109)
	*Pakaj (20107CSB1251)
	*Devendra Raj (20107CSB1136)


In this project we tried to simulate the RISC-V simulator like VENUS(https://www.kvakil.me/venus/) 
All the project was divided in 4 phases.

Problem Statement described as follows:
You have to build a simulator like venus. For more clearity I am dividing the project in different phases:


Phase 1: Conversion of Assembly code to Machine code
Here, you are doing the job of a 32bit RISC-V assembler. You will write a C/C++/Java program to take a .asm file as input and generate a .mc file.

i) .asm file will have a format like below (one assembly instruction in each line)
add x1, x2, x3
andi x5, x6, 10

ii) .mc file is expected to have a format like below (<address of instruction><delimiter - space><machine code of the instruction>, one in each line):
Just like Venus let us assume that code segment starts at 0x00000000 and data segment starts at 0x10000000, stack segment at 0x7FFFFFFC and heap segment at 0x10007FE8.
So, your code segment of .mc file would look like:
0x0 0x003100B3
0x4 0x00A37293
0x8 <your terminate code to signify end of text segment and in turn, end of the assmebly program>

0x10000000 0x10
....

As you would have sensed, your assembler code needs to parse the .asm file one or more times to precisely calculate and replace various labels appropriately.

Phase 2: Code for a 5 stage instruction execution.
Here, we would take the input from the .mc file (created above) and pick one instruction at a time, using the value in PC (0x0). You will write a C/C++/Java program. You would need to include structures for all the registers here - PC, IR, Register File, RA, RB, etc., five stages of execution as functions. To give an overall idea, I am sharing a rar file with you. It contains several files for a C like implementation. Reading the .mc file might be slightly different but the essence remains same.

Phase 3: Code for the pipeline version of Phase 2.
In this phase, you'll extend the Phase 2 code with pipelining features. I will share the exact details with you as we complete pipelining concepts in class.

Phase 4: Appending a cache like memory module to Phase 3.
In this phase, you'll create the instruction and data cache modules. Instead of directly reading from .mc file, you'll read the instructions, read/write data from these cache modules. Similar to Phase 3, you'll get more details as we go through the Memory module of the course.



