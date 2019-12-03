#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "instruction_fetcher.h"
#include "instruction_decoder.h"
#include "executer.h"
//#include "writter.h"

#include "regs.h"

struct CPU_CONTEXT;
typedef struct CPU_CONTEXT{
	
	uint32_t xreg[32]; //General purpose registers
	uint32_t next_pc;	
	uint32_t pc; //address of current instruction
	uint32_t cycle_count;
	uint32_t hazard_count;
	
	//uint32_t ram_start;
	//uint8_t ram[RAM_SIZE];
} CPU_CONTEXT;


bool IF_STALL;
bool ID_STALL;
bool EX_STALL;

bool IF_NOP;
bool ID_NOP;
bool EX_NOP;

IF inst_fetcher; 
ID inst_decoder;
EX executer;
TEMP_REG reg_table[32];

void update_latch(CPU_CONTEXT*);
void update_component(void);
void update_regs();
void check_stall(void);
void check_nop(void);
void branch_set();
void hazard_judge();
#endif
