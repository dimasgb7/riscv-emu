#ifndef REGS_H
#define REGS_H
typedef struct _IMM
{
	uint32_t imm_i;
	uint32_t imm_s;
	uint32_t imm_b;
	uint32_t imm_u;
	uint32_t imm_j;
} IMM;

typedef struct _INST_REGS
{
	uint32_t rd;
	uint32_t rs1;
	uint32_t rs2;

} INST_REGS;

typedef struct _CTRL_BITS
{
	uint32_t funct3;
	uint32_t funct7;
	uint32_t  opcode;
	bool	 nop;

} CTRL_BITS;

typedef struct _TEMP_REG
{
	uint32_t in;
	uint32_t out;
	void update()
	{
		out = in;
		in  = out;
	}
} TEMP_REG;

struct OP_CONTEXT;
typedef struct OP_CONTEXT{
	uint32_t pc;
	uint32_t rd;
	uint32_t rs1_val;
	uint32_t rs2_val;
	uint32_t result;
	uint32_t imm;
} OP_CONTEXT; 
			
#endif 			
