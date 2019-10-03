#include "op_codes.h"
#include "cpu_utils.h"

void op_code_table(CPU_CONTEXT* context, uint32_t inst){
	

	uint8_t opcode = inst & OP_CODE_MASK;
	uint32_t rd, rs1, rs2, funct3;
	
	opcode  = inst & OP_CODE_MASK;
	rd 	= inst & RD_MASK;


	

	std::cout << "------------------------------------------------------------->";	
	switch(opcode)
		{
			case LUI: std::cout<<"LUI" << std::endl;
				   break;
			case AUIPC: std::cout<<"AUIPC" << std::endl;
				   break;
			case JAL: std::cout<<"TOP" << std::endl;
				   break;
			case JALR: std::cout<<"TOP" << std::endl;
				   break;
			case BEQ_BNE_BLT_BGE_BLTU_BGEU: 
				   std::cout<<"TOP"<< std::endl;
				   break;

			default: //unimplemented_inst();
				   std::cout << "NAO TOP"<< std::endl;
				   break;
		};


}

void unimplemented_inst(void){
		
	std::cout<<"Error: Unimplemented Instruction \n";
	exit(1);
}

