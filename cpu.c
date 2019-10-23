#include "cpu.h"
#include "cpu_utils.h"
#include "op_codes.h"
#include "table.c"
#include "test_functions.h"
//#include "<stdlib.h>" 



int cpu_execute(CPU_CONTEXT* context){
	//Dummy memory for test
	uint32_t *dummy_mem;
	dummy_mem = new uint32_t[10];
    //Build Instructions for test	
    uint32_t number_of_instructions = 9 ;
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
  	
   	uint32_t position = 0x1000; 
	RAM[position] = -37; //0x8F8F;
	//RAM[position] = 0x8F8F;
    	load_dummy_memory(dummy_mem, sizeof(TEST_INST), TEST_INST);
        
    	uint32_t inst;
    	uint32_t mem_position;	
    
    dump_all_regs(context);	
    print_bar();
    std::cout<<"BEGINING EXECUTION LOG:" <<std::endl<<std::endl;	
	//Main execution lpoop	
	while( context->cycle_count < number_of_instructions) { 	
		mem_position = context->pc / 4;
		inst = dummy_mem[ mem_position ];
        
        #ifdef SET_DEBUG
		std::cout<<"At cycle "<<context->cycle_count<<":"
                 <<" PC ["<< context->pc << "]" 
                 <<" Inst [" 
				 <<std::hex<<inst<<"] " ;
        #endif

		//Execute Instruction
		context->next_pc+=4;
		op_code_table(context, inst);
		
		//Missaligned fetch test		
		if(context->next_pc & 3) exit(1);

		context->pc = context->next_pc;
		context->cycle_count+=1;
	
	#ifdef SET_DEBUG		
		dump_reg(context,0);
        	dump_reg(context,1);
        	dump_reg(context,2);
		print_bar();
	#endif
	} 
}
