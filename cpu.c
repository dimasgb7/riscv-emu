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
    uint32_t number_of_instructions = 4;
    uint32_t TEST_INST[number_of_instructions];
    
    TEST_INST[0] = inst_build_I(12,0,0,0,JALR);
    TEST_INST[1] = inst_build_U(12,0,LUI);
    TEST_INST[2] = inst_build_I(12,0,0,0,JALR);
    TEST_INST[3] = inst_build_U(12,0,LUI);
    

    
    
    //TEST_INST[2] = inst_build_S(0,0,0,4,0,BNE);
    //TEST_INST[3] = inst_build_U(0,0,0,4,0,BNE);
    
    uint32_t coco[number_of_instructions];
        for(int i=0; i < number_of_instructions; i++)
            coco[i] = TEST_INST[i];

    load_dummy_memory(dummy_mem, sizeof(coco), coco);
        
	uint32_t inst;
	
	
	//Main execution lpoop	
	while( context->cycle_count < number_of_instructions) { 	
		inst   = dummy_mem[context->pc];
		std::cout<<"At cycle "<<context->cycle_count<<" instruction "
				<<std::hex<<inst <<" was executed."<<std::endl;
		
		//Find Execution on OP code table
		op_code_table(context, inst);			
	
	context->pc+=1;
	context->cycle_count +=1;
	} 
}
