#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H
#include "regs.h"

class ID
	{
	public:
	
		//SETUP METHODS
		void set_pc(uint32_t argv);
		void set_regs(INST_REGS argv);
		void set_imm(IMM argv);
		void set_ctrl(CTRL_BITS argv);
		void set_regs_val();
		
		//MAIN METHODS	
		void read_regs(TEMP_REG* reg);
		void sel_imm();
		void branch_check();
		void nop();
		
		//OUTPUT METHODS
		uint32_t get_pc();
		uint32_t get_rd();
		uint32_t get_rs1_val();
		uint32_t get_rs2_val();
		uint32_t get_imm();
		bool 	 get_branch_flag();
		bool 	 get_stall();
		bool 	 get_nop();
		bool 	 get_hazard();
		unsigned char get_type();
		CTRL_BITS get_ctrl();

		//DEBUG
		void inst_debug();


			

	private:
		//INPUTS
		uint32_t pc;
		IMM imm;
		INST_REGS inst_regs;
		CTRL_BITS ctrl;
		unsigned char type;
		
		//OUTPUTS 
		uint32_t rs1_val, rs2_val;
		uint32_t my_imm;
		bool branch_flag;
		bool inst_dep_flag;
		
		//MAIN
		void inst_dep_check();
		void imm_mux();
		
		//DEBUG	
		std::string my_opcode_name;
	}; 
#endif



