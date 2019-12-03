#ifndef WRITTER_h
#define WRITTER_H

#include "regs.h"

class WR_R
	{
	public:
		//INPUTS
		uint32_t pc;
		uint32_t rd;
		uint32_t result;
		CTRL_BITS ctrl;
		unsigned char type;		
		//OUTPUTS

		//SETUP METHODS
		void set_pc(uint32_t argv);
		void set_rd(uint32_t argv);
		void set_ctrl(CTRL_BITS argv);
		void set_result(uint32_t argv);
		void set_type(unsigned char argc);
		
		//MAIN METHODS
		void write_to_reg(TEMP_REG* argv);
		void branch_pc();
	private:;
	};
#endif 
