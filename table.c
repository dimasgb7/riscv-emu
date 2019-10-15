#include "op_codes.h"
#include "cpu_utils.h"
#include "imediates.c"
#include "base.c"

#define R_INST(OPCODE) OP_##OPCODE(context,funct7,rs2,rs1,funct3,rd); 
#define I_INST(OPCODE) OP_##OPCODE(context,I_IMMEDIATE(inst),rs1,rd); 
#define S_INST(OPCODE) OP_##OPCODE(context,S_IMMEDIATE(inst),rs2,rs1,funct3); 
#define B_INST(OPCODE) OP_##OPCODE(context,B_IMMEDIATE(inst),rs2,rs1,funct3); 
#define U_INST(OPCODE) OP_##OPCODE(context,U_IMMEDIATE(inst),rd); 
#define J_INST(OPCODE) OP_##OPCODE(context,J_IMMEDIATE(inst),rd); 
    

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
    	rs1 = (inst & RS1_MASK) >> RS1_OFFSET;
    	rs2 = (inst & RS2_MASK) >> RS2_OFFSET;
    	funct3 = (inst & FUNCT3_MASK)>>12;
    	imm = I_IMMEDIATE(inst);
    
    
    #ifdef SET_DEBUG
    //Instructions execution
    	std::cout<<"Instruction [" << get_opcode_name(opcode,funct3) <<"]" <<std::endl;
    #endif

	switch(opcode)
		{
            #ifdef SET_RV32I
            case LUI: U_INST(LUI);
                      break; 
			
            case AUIPC: U_INST(AUIPC);
                        break;
			
	    case JAL: J_INST(JAL);
			break;
	    case JALR: I_INST(JALR); 
		        break;
		    
            case BEQ_BNE_BLT_BGE_BLTU_BGEU: 
                   switch(funct3){
		       case 0x0: B_INST(BEQ);
                                 break;
                      
		       case 0x1: B_INST(BNE);
                                 break;
		       
		       case 0x4: B_INST(BLT); 
                                 break;
                       
		       case 0x5: B_INST(BGE);
                                 break;
                       
		       case 0x6: B_INST(BLTU);
                                 break;
                       
		       case 0x7: B_INST(BGEU);
                                 break;
                   };
                   
		   break; 
            

    
            #endif
			default: //unimplemented_inst();
				    std::cout << "Instruction not implemented"<< std::endl;
				    break;
		};


}

