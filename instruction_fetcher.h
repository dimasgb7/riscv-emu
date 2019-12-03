#ifndef INSTRUCTION_FETCHER_H
#define INSTRUCTION_FETCHER_H

#include "regs.h"

class IF
	{
	public:
		//INPUT METHODS	
		void set_inst(uint32_t* mem);
		void set_pc(uint32_t pc_arg);
		void set_branch_flag(bool argv);
		void set_type();
		
		//MAIN METHODS	
		void split_inst();
		void inst_debug();
		void nop();
		uint32_t get_inst();
	
		//OUTPUT METHODS	
		IMM get_imm();
		INST_REGS get_inst_regs();
		CTRL_BITS get_ctrl();
		uint32_t get_pc();	
		uint32_t get_opcode();
		uint32_t get_funct7();
		uint32_t get_funct3();
		uint32_t get_rd();
		uint32_t get_rs1();
		uint32_t get_rs2();
		bool get_stall();
		bool get_nop();
	
	private:
		//INPUTS
		uint32_t inst;
		uint32_t pc;
		uint32_t next_pc;
		uint32_t mem_position;
		uint32_t branch_flag;	
		
		//OUTPUTS	
		//Instruction parts to be sampled    
		uint32_t rd, rs1, rs2, funct3, funct7=0;
		IMM imm;
		INST_REGS inst_regs;
		CTRL_BITS ctrl;	
		unsigned char type;
	
		//DEBUG
		std::string my_opcode_name;


		
	}; 
#endif
