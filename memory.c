#include "memory.h"
#include "read_mem_op.c"
#include "write_mem_op.c"

void init_memory()
{
	for(int i =0; i<RAM_SIZE; i++) 
		write_mem_u32( (char)0x0, i);	
}

void check_memory()
{	
	uint32_t tmp;

	std::cout <<"Checking memory:" <<std::endl;
	for(int i = 0; i < RAM_SIZE; i++){
		read_mem_u32(&tmp, i);
		std::cout << "mem[" << i << "]=" <<tmp << std::endl;
		}
}
