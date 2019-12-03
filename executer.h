#ifndef EXECUTER_H
#define EXECUTER_H

#include "regs.h"

class EX
	{
	public:
		//SETUP METHODS 
		void set_pc(uint32_t argv);
		void set_rd(uint32_t argv);
		void set_rs1_val(uint32_t argv);
	        void set_rs2_val(uint32_t argv);
		void set_imm(uint32_t argv);
		void set_ctrl(CTRL_BITS argv);
		void set_type(unsigned char argc);
			
		//MAIN METHODS
		void opcode_table();
		void write_to_reg(TEMP_REG* argv);
		void nop(bool arg);
		OP_CONTEXT* context = calloc(1, sizeof(OP_CONTEXT));
		
		//OUTPUT METHODS	
		bool get_stall();
		bool get_nop();
		bool get_hazard();
	
		//DEBUG
		void inst_debug();	
	
	private:
		//INPUTS
		uint32_t pc;
		uint32_t rd;
		uint32_t rs1_val, rs2_val;
		uint32_t imm;
		CTRL_BITS ctrl;
		unsigned char type;
		uint32_t inst_dep_flag;
		//OUTPUTS
		uint32_t next_pc;
		uint32_t rd_update_val;
		
		//MAIN METHODS
		void inst_dep_check();
		void update_context();
		
		//DEBUG
		std::string my_opcode_name;
	};
#endif

