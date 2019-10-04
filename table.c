#include "op_codes.h"
#include "cpu_utils.h"

void op_code_table(CPU_CONTEXT* context, uint32_t inst){
    
    //Define instruction parts to be sampled    
	uint8_t opcode; 
	uint32_t rd, rs1, rs2, funct3;
	
    //Break instruction on data sets to be sampled
	opcode  = inst & OP_CODE_MASK;
	rd 	= inst & RD_MASK;
    rs1 = inst & RS1_MASK;
    rs2 = inst & RS2_MASK;
    funct3 = (inst & FUNCT3_MASK)>>12;

    //Instructions execution
	std::cout << "------------------------------------------------------------->";	
	switch(opcode)
		{
			case LUI: std::cout<<"LUI" << std::endl;
				   break;
			case AUIPC: std::cout<<"AUIPC" << std::endl;
				   break;
			case JAL: std::cout<<"JAL" << std::endl;
				   break;
			case JALR: std::cout<<"JALR" << std::endl;
				   break;
			case BEQ_BNE_BLT_BGE_BLTU_BGEU: 
                   switch(funct3){
                       case 0x0: std::cout << "BEQ" << std::endl;
                                 break;
                       case 0x1: std::cout << "BNE" << std::endl;
                                 break;
                       case 0x4: std::cout << "BLT" << std::endl;
                                 break;
                       case 0x5: std::cout << "BGE" << std::endl;
                                 break;
                       case 0x6: std::cout << "BLTU" << std::endl;
                                 break;
                       case 0x7: std::cout << "BGEU" << std::endl;
                                 break;
                   };
                   break; 
                    

			default: //unimplemented_inst();
				    std::cout << "Instruction not implemented"<< std::endl;
				    break;
		};


}

void unimplemented_inst(void){
		
	std::cout<<"Error: Unimplemented Instruction \n";
	exit(1);
}

