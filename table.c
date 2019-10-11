#include "op_codes.h"
#include "cpu_utils.h"
#include "imediates.c"
#include "base.c"

#define R_INST(OPCODE) OP_##OPCODE(context,funct7,rs2,rs1,funct3,rd); 
#define I_INST(OPCODE) OP_##OPCODE(context,I_IMMEDIATE(inst),rs1,funct3,rd); 
#define S_INST(OPCODE) OP_##OPCODE(context,S_IMMEDIATE(inst),rs2,rs1,funct3); 
#define SB_INST(OPCODE) OP_##OPCODE(context,SB_IMMEDIATE(inst),rs2,rs1,funct3); 
#define U_INST(OPCODE) OP_##OPCODE(context,U_IMMEDIATE(inst),rd); 
#define UJ_INST(OPCODE) OP_##OPCODE(context,UJ_IMMEDIATE(inst),rd); 
    

void unimplemented_inst(void){
		
	std::cout<<"Error: Unimplemented Instruction \n";
	exit(1);
}

void op_code_table(CPU_CONTEXT* context, uint32_t inst){
    
    //Define instruction parts to be sampled    
	uint8_t opcode; 
	uint32_t rd, rs1, rs2, funct3;
    int32_t imm;
	
    //Break instruction on data sets to be sampled
	opcode  = inst & OP_CODE_MASK;
	rd 	= (inst & RD_MASK) >> RD_OFFSET;
    rs1 = inst & RS1_MASK;
    rs2 = inst & RS2_MASK;
    funct3 = (inst & FUNCT3_MASK)>>12;
    imm = I_IMMEDIATE(inst);
    
    
    #ifdef SET_DEBUG
    //Instructions execution
	std::cout << " ----------------------------------------> ";	
    std::cout<< get_opcode_name(opcode,funct3) << std::endl;
    #endif

	switch(opcode)
		{
            #ifdef SET_RV32I
            case LUI: U_INST(LUI);
                      break; 
			
            case AUIPC: U_INST(AUIPC);
                        break;
			
            case JAL:  
                        //imm = (inst & IMM_UJ_20_MASK) >> IMM_UJ_20_OFFSET 
                              

				        break;
			case JALR: 
				   break;
		    
            case BEQ_BNE_BLT_BGE_BLTU_BGEU: 
                   switch(funct3){
                       case 0x0: 
                                 break;
                       case 0x1: 
                                 break;
                       case 0x4: 
                                 break;
                       case 0x5: 
                                 break;
                       case 0x6: 
                                 break;
                       case 0x7: 
                                 break;
                   };
                   break; 
            

    
            #endif
			default: //unimplemented_inst();
				    std::cout << "Instruction not implemented"<< std::endl;
				    break;
		};


}

