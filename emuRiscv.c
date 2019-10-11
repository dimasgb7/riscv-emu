#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdexcept>
#include <sstream>
#include <new>

#include "./cfg_defines.h"
#include "./my_functions_file.c"

#include "./cpu.c"

//Temporary switchs for different ISA extensions


int main (){
	//Dump log to output file
    //freopen("out.txt","w",stdout);
    
    //Variables
	int number1, number2;
	std::string line;

	uint32_t *my_mem;
	my_mem = malloc(0x10000);
			

	//Fetch Data from ROM Files
	
	
	FetchData("rom", my_mem, 0x0);
/*
	FetchData("rom", my_mem, 0x800);
	FetchData("rom", my_mem, 0x1000);
	FetchData("rom", my_mem, 0x1800);
	PrintMem(my_mem);
*/	

	//Diassemble ROM file
	//run_diassembler(10, my_mem);	

	CPU_CONTEXT* my_context = calloc(1,sizeof(CPU_CONTEXT));

	cpu_execute(my_context);




	return 0;
}


