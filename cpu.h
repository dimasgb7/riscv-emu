#ifndef CPU_H
#define CPU_H

#include <stdint.h>

struct CPU_CONTEXT;
typedef struct CPU_CONTEXT{
	
	uint32_t xreg[32]; //General purpose registers
	
	uint32_t pc; //address of current instruction
	uint32_t cycle_count;
} CPU_CONTEXT;

#endif