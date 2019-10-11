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
    uint32_t number_of_instructions = 10 ;
    uint32_t TEST_INST[number_of_instructions];
    
    print_bar();
    std::cout<<"BUILDING INSTRUCTIONS: "<< std::endl<<std::endl; 
    TEST_INST[0] = inst_build_U(0xFFFFE , 1 , LUI);
    TEST_INST[1] = inst_build_U(0x0, 2 , AUIPC);
    TEST_INST[2] = inst_build_UJ(0xFFFFF , 0 , JAL);
    TEST_INST[3] = inst_build_I(0xFFFFF , 0 , 0 , 0 , JALR);
    TEST_INST[4] = inst_build_SB(0xFFFFF, 0 , 0 , 0 , BEQ); 
    TEST_INST[5] = inst_build_SB(0xFFFFF, 0 , 0 , 1 , BEQ); 
    TEST_INST[6] = inst_build_SB(0xFFFFF, 0 , 0 , 4 , BEQ); 
    TEST_INST[7] = inst_build_SB(0xFFFFF, 0 , 0 , 5 , BEQ); 
    TEST_INST[8] = inst_build_SB(0xFFFFF, 0 , 0 , 6 , BEQ); 
    TEST_INST[9] = inst_build_SB(0xFFFFF, 0 , 0 , 7 , BEQ); 
    
    //TEST_INST[2] = inst_build_S(0,0,0,4,0,BNE);
    //TEST_INST[3] = inst_build_U(0,0,0,4,0,BNE);
    
    uint32_t coco[number_of_instructions];
        for(int i=0; i < number_of_instructions; i++)
            coco[i] = TEST_INST[i];

    load_dummy_memory(dummy_mem, sizeof(coco), coco);
        
	uint32_t inst;
	
    dump_all_regs(context);	
    print_bar();
    std::cout<<"BEGINING EXECUTION LOG:" <<std::endl<<std::endl;	
	//Main execution lpoop	
	while( context->cycle_count < number_of_instructions) { 	
		inst   = dummy_mem[context->pc];
        
        #ifdef SET_DEBUG
		std::cout<<"At cycle "<<context->cycle_count<<":"
                 <<" PC ["<< context->pc << "]" 
                 <<" Inst [" 
				 <<std::hex<<inst<<"]" <<" executed:" <<std::endl;
        dump_reg(context,0);
        dump_reg(context,1);
        dump_reg(context,2);
        #endif

		//Find Execution on OP code table
		op_code_table(context, inst);			
	context->pc+=1;
	context->cycle_count +=1;
	} 
}
