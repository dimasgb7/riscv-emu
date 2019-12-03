#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdexcept>
#include <sstream>
#include <new>

#define RAM_SIZE 0x10000



uint32_t *dummy_mem;

#include "cpu_utils.h"
#include "./cfg_defines.h"
#include "./my_functions_file.c"
#include "./memory.c"
#include "./test_functions.h"
#include "./cpu.c"

//Temporary switchs for different ISA extensions



int main (int argc, char *argv[]){
	//Dump log to output file
    	freopen("out.txt","w",stdout);
    
    	//Variables
	int number1, number2;
	std::string line;

	uint32_t *my_mem;
	my_mem = malloc(0x10000);
			

	//Fetch Data from ROM Files
	FetchData("rom", my_mem, 0x0);
	FetchData("rom", my_mem, 0x800);
	FetchData("rom", my_mem, 0x1000);
	FetchData("rom", my_mem, 0x1800);
	PrintMem(my_mem);

	//Initalize RAM memory
	  init_memory();
	  //check_memory();
	
	
	    //Build Instructions for test	
	    uint32_t number_of_instructions = 0;
	    
	    #ifdef SET_UI_TEST 
	  	 number_of_instructions = 16;
	    #endif
	    #ifdef SET_DEP_TEST 
	  	 number_of_instructions = 5;
	    #endif
	    #ifdef SET_BRANCH_TEST 
	  	 number_of_instructions = 2;
	    #endif
	    #ifdef SET_LOADSTORE_TEST 
	  	 number_of_instructions = 9;
	    #endif
	    #ifdef SET_OP_TEST 
	  	 number_of_instructions = 32;
	    #endif
	    #ifdef SET_BASIC_TEST 
	  	 number_of_instructions = 14;
	    #endif
	    
	    uint32_t TEST_INST[number_of_instructions];
	    
	    print_bar();
	    std::cout<<"BUILDING INSTRUCTIONS: "<< std::endl<<std::endl; 
	    
	    
	    /*
	    INSTRUCTION BUILDING CHEAT SHEET
	
	    inst_build_R(funct7, rs2, rs1, funct3, rd, opcode);
	    inst_build_I(imm, rs1, funct3, rd, opcode);
	    inst_build_S(imm, rs2, rs1, funct3, opcode);
	    inst_build_B(imm, rs2, rs1, funct3, opcode);
	    inst_build_U(imm, rd, opcode);
	    inst_build_J(imm, rd, opcode);
	    */
	
	    //U and I TYPE TEST
	    #ifdef SET_UI_TEST	
	    TEST_INST[0] = inst_build_U(0xF, 1, LUI);
	    TEST_INST[1] = inst_build_U(0xe, 2, LUI);
	    TEST_INST[2] = inst_build_U(0x0, 3, AUIPC);
	    
	    //I TYPE TEST
	    TEST_INST[3] = inst_build_I(0x8, 2, ADDI_F3, 2, OPI); 
	    TEST_INST[4] = inst_build_I(0x9, 3, SLTI_F3, 4, OPI); 
	    TEST_INST[5] = inst_build_I(0x7, 3, SLTI_F3, 4, OPI); 
	    TEST_INST[6] = inst_build_I(-0x9, 3, SLTIU_F3, 4, OPI); 
	    TEST_INST[7] = inst_build_I(-0x7, 3, SLTIU_F3, 4, OPI); 
	    TEST_INST[8] = inst_build_I(0x1, 4, SLTIU_F3, 4, OPI);
	    TEST_INST[9] = inst_build_I(0x0, 4, ANDI_F3, 4, OPI); 
	    TEST_INST[10] = inst_build_I(0x1, 5, ANDI_F3, 5, OPI); 
	    TEST_INST[11] = inst_build_I(0x1, 5, ORI_F3, 5, OPI); 
	    TEGT_INST[12] = inst_build_I(0x1, 5, XORI_F3, 5, OPI); 
	    TEST_INST[13] = inst_build_I(0x1, 5, SLLI_F3, 5, OPI); 
	    TEST_INST[14] = inst_build_I(0x1, 5, SRLI_F3, 5, OPI); 
	    TEST_INST[15] = inst_build_I(-0011, 5, SRAI_F3, 5, OPI); 
	    #endif

	    //Instruction Dependency test
	    #ifdef SET_DEP_TEST
	    TEST_INST[0] = inst_build_U(0xF, 1, LUI);
	    TEST_INST[1] = inst_build_I(0x4, 2, ADDI_F3, 2, OPI); 
	    TEST_INST[2] = inst_build_I(0x4, 2, ADDI_F3, 3, OPI); 
	    TEST_INST[3] = inst_build_U(0xA, 4, LUI);
	    TEST_INST[4] = inst_build_U(0xA, 5, LUI);
	    #endif
	    
	    //Branch Test 
	    #ifdef SET_BRANCH_TEST
	    TEST_INST[3] = inst_build_B(0xF, 1,2, BEQ_F3, BRANCH);
	    TEST_INST[4] = inst_build_B(0xF, 1,2, BEQ_F3, BRANCH);
	    #endif	

	    
	    //LOAD AND STORE TESTS
	    #ifdef SET_LOADSTORE_TEST
	    //Negative number stored on 0x1000 memory addreess
	    //Load adddress to register 1
	    //Test loading value from memory on register 2 to 5 and check
	    //if its sign extended or zero extended according to instruction
	    //requirement
	    TEST_INST[0] = inst_build_U(0x1, 1, LUI);
	    TEST_INST[1] = inst_build_I(0x0, 1, LHU_F3, 2, LOAD); 
	    TEST_INST[2] = inst_build_I(0x0, 1, LBU_F3, 3, LOAD);
	    TEST_INST[3] = inst_build_I(0x0, 1, LW_F3, 4, LOAD);
	    TEST_INST[4] = inst_build_I(0x0, 1, LH_F3, 5, LOAD);
	    TEST_INST[5] = inst_build_I(0x0, 1, LB_F3, 6, LOAD);
	    
	    //Load a different value on on register 2
	    //Store the value of register two on the memory position referenced
	    //by register 1
	    //load the value on memory position referenced by register 1 on register 3 
	    TEST_INST[6] = inst_build_U(0x2, 2, LUI);
	    TEST_INST[7] = inst_build_S(0x0, 2, 1, SW_F3, STORE);
	    TEST_INST[8] = inst_build_I(0x0, 1, LW_F3, 3, LOAD); 
	    #endif

	    
	    //OP TESTS
	    #ifdef SET_OP_TEST
	    TEST_INST[0] = inst_build_I(0x4, 0, ADDI_F3, 1, OPI); 
	    TEST_INST[1] = inst_build_I(0x8, 0, ADDI_F3, 2, OPI); 
	    TEST_INST[2] = inst_build_R(0x0, 1, 2, ADD_F3, 3, OP);
	    TEST_INST[3] = inst_build_R(0x186a0, 1, 2, SUB_F3, 4, OP);
	    TEST_INST[4] = inst_build_R(0x0, 2, 1, SLT_F3, 5, OP);
	    TEST_INST[5] = inst_build_R(0x0, 1, 2, SLT_F3, 6, OP);


	    TEST_INST[6] = inst_build_R(0x0, 0, 1, AND_F3, 1, OP); 
	    TEST_INST[7] = inst_build_R(0x0, 0, 2, AND_F3, 2, OP); 
	    TEST_INST[8] = inst_build_R(0x0, 0, 3, AND_F3, 3, OP); 
	    TEST_INST[9] = inst_build_R(0x0, 0, 4, AND_F3, 4, OP); 
	    TEST_INST[10] = inst_build_R(0x0, 0, 5, AND_F3, 5, OP); 
	    TEST_INST[11] = inst_build_R(0x0, 0, 6, AND_F3, 6, OP); 
	    
	    TEST_INST[12] = inst_build_I(0x1, 0, ADDI_F3, 1, OPI); 
	    TEST_INST[13] = inst_build_R(0x0, 0, 1, OR_F3, 1, OP); 
	    TEST_INST[14] = inst_build_R(0x0, 1, 2, OR_F3, 2, OP); 
	    TEST_INST[15] = inst_build_R(0x0, 2, 3, OR_F3, 3, OP); 
	    TEST_INST[16] = inst_build_R(0x0, 3, 4, OR_F3, 4, OP); 
	    TEST_INST[17] = inst_build_R(0x0, 4, 5, OR_F3, 5, OP); 
	    TEST_INST[18] = inst_build_R(0x0, 5, 6, OR_F3, 6, OP); 
	    
	    TEST_INST[19] = inst_build_I(0x0, 0, ADDI_F3, 1, OPI); 
	    TEST_INST[20] = inst_build_R(0x0, 1, 1, XOR_F3, 1, OP); 
	    TEST_INST[21] = inst_build_R(0x0, 2, 2, XOR_F3, 2, OP); 
	    TEST_INST[22] = inst_build_R(0x0, 3, 3, XOR_F3, 3, OP); 
	    TEST_INST[23] = inst_build_R(0x0, 4, 4, XOR_F3, 4, OP); 
	    TEST_INST[24] = inst_build_R(0x0, 5, 5, XOR_F3, 5, OP); 
	    TEST_INST[25] = inst_build_R(0x0, 6, 6, XOR_F3, 6, OP); 
	    #endif



	    //Basic Run test
	    #ifdef SET_BASIC_TEST
	    TEST_INST[0] = inst_build_U(0xF, 1, LUI);
	    TEST_INST[1] = inst_build_U(0xF, 2, LUI); 
	    TEST_INST[2] = inst_build_B(0x4, 2, 1, BEQ_F3, BRANCH); 
	    TEST_INST[3] = inst_build_U(0xFFF, 1, LUI);
	    TEST_INST[4] = inst_build_U(0x1, 1, LUI);
	    TEST_INST[5] = inst_build_I(0x0, 1, LW_F3, 2, LOAD);
	    TEST_INST[6] = inst_build_S(0x1, 2, 1, SW_F3, STORE);
	    TEST_INST[7] = inst_build_I(0x1, 1, LW_F3, 1, LOAD);
	    TEST_INST[8] = inst_build_I(0x1, 1, SRLI_F3, 1, OPI);
	    TEST_INST[9] = inst_build_I(0x401, 2, SRAI_F3, 1, OPI);
	    TEST_INST[10] = inst_build_U(0xE, 1, LUI);
	    TEST_INST[11] = inst_build_U(0x1, 2, LUI);
	    TEST_INST[12] = inst_build_R(0x0, 2, 1, ADD_F3, 3, OP);
	    TEST_INST[13] = inst_build_R(0x1, 2, 1, SUB_F3, 3, OP);
            #endif

	    uint32_t position = 0x1000; 
	    write_mem_u32( -20, position);
	    
	    //Load RAM memory 
	    for(int i = 0; i < number_of_instructions*4; i=i+4)
	    	write_mem_u32(TEST_INST[i/4],i); 
	
	//Call Context    
	CPU_CONTEXT* my_context = calloc(1,sizeof(CPU_CONTEXT));
	
	print_bar();
	
	//Initiate Execution loop 
	cpu_execute(my_context, number_of_instructions);




	return 0;
}


