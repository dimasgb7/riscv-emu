#include "cpu.h"
#include "cpu_utils.h"
#include "op_codes.h"
#include "table.c"
//#include "<stdlib.h>" 


void load_dummy_memory(uint32_t* d_mem, uint32_t size, uint32_t* data )
{
	uint32_t* buffer = &d_mem[0];
	for(int i=0;i<size;i++)
		buffer[i] = data[i];

}

int cpu_execute(CPU_CONTEXT* context){
	//Dummy memory for test
	uint32_t *dummy_mem;
	dummy_mem = new uint32_t[10];
	uint32_t coco[]= {LUI,AUIPC,JAL,JALR,BEQ};
	load_dummy_memory(dummy_mem, sizeof(coco), coco);
        
	uint32_t inst;
	
	
	//Main execution lpoop	
	while( context->cycle_count < 10) { 	
		inst   = dummy_mem[context->pc];
		std::cout<<"At cycle "<<context->cycle_count<<" instruction "
				<<std::hex<<inst <<" was executed."<<std::endl;
		
		//Find Execution on OP code table
		op_code_table(context, inst);			
	
	context->pc+=1;
	context->cycle_count +=1;
	} 
}
