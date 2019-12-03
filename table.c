#include "op_codes.h"
#include "cpu_utils.h"
//#include "imediates.c"
#include "base.c"

#define R_INST(OPCODE) OP_##OPCODE(context, rs2,rs1,rd); 
#define I_INST(OPCODE) OP_##OPCODE(context,I_IMMEDIATE(inst),rs1,rd); 
#define S_INST(OPCODE) OP_##OPCODE(context,S_IMMEDIATE(inst),rs2,rs1); 
#define B_INST(OPCODE) OP_##OPCODE(context,B_IMMEDIATE(inst),rs2,rs1); 
#define U_INST(OPCODE) OP_##OPCODE(context,U_IMMEDIATE(inst),rd); 
#define J_INST(OPCODE) OP_##OPCODE(context,J_IMMEDIATE(inst),rd); 
    

void unimplemented_inst(void){
		
	std::cout<<"Error: Unimplemented Instruction \n";
	exit(1);
}

void op_code_table(CPU_CONTEXT* context, uint32_t inst){
    
    //Define instruction parts to be sampled    
	uint8_t opcode; 
	uint32_t rd, rs1, rs2, funct3, funct7=0;
    	int32_t imm;
	
    //Break instruction on data sets to be sampled
	opcode  = inst & OP_CODE_MASK;
	rd 	= (inst & RD_MASK) >> RD_OFFSET;
    	rs1 = (inst & RS1_MASK) >> RS1_OFFSET;
    	rs2 = (inst & RS2_MASK) >> RS2_OFFSET;
    	funct3 = (inst & FUNCT3_MASK)>>12;
	funct7 = inst & FUNCT7_MASK;
    	imm    = I_IMMEDIATE(inst);
    
    
    #ifdef SET_DEBUG
    //Instructions execution
	std::string my_opcode_name;

	my_opcode_name = get_opcode_name(opcode,funct3);

	switch(opcode){
		case SRLI: if(I_IMMEDIATE(inst) & 0x400) my_opcode_name ="SRAI";
			   break;
		case OP:
			 my_opcode_name = get_opcode_name(opcode,funct3,funct7);
			 break;
	}
					
/*
	if(opcode == SRLI){  
    		if( I_IMMEDIATE(inst) & 0x400) my_opcode_name = "SRAI";
		else my_opcode_name = get_opcode_name(opcode,funct3);	}
	else if (opcode == ADD | opcode == SRL) funct7 = inst & FUNCT7_MASK;	
    		my_opcode_name = get_opcode_name(opcode,funct3,funct7);} 
*/
	std::cout<<"Instruction [" << my_opcode_name <<"]" <<std::endl;

    #endif

	switch(opcode)
		{
            #ifdef SET_RV32I
            case LUI: 	U_INST(LUI);break; 
	    case AUIPC: U_INST(AUIPC);break;
	    case JAL: 	J_INST(JAL);break;
	    case JALR: 	I_INST(JALR);break;
            case BRANCH: 
                   switch(funct3){
		       case BEQ_F3: B_INST(BEQ);break;
		       case BNE_F3: B_INST(BNE);break;
		       case BLT_F3: B_INST(BLT);break;
		       case BGE_F3: B_INST(BGE);break;
		       case BLTU_F3: B_INST(BLTU);break;
		       case BGEU_F3: B_INST(BGEU);break;
                   };
		   break; 
            
	    case LOAD: 
                   switch(funct3){
		       case LB_F3: I_INST(LB);break;
		       case LH_F3: I_INST(LH);break;
		       case LW_F3: I_INST(LW);break;
		       case LBU_F3: I_INST(LBU);break;
		       case LHU_F3: I_INST(LHU);break;
                   };
		   break; 
	    
	    case STORE: 
                   switch(funct3){
		       case SB_F3: S_INST(SB);break;
		       case SH_F3: S_INST(SH);break;
		       case SW_F3: S_INST(SW);break;
                   };
		   break; 

	    case OPI: 
                   switch(funct3){
		       case ADDI_F3: I_INST(ADDI); break;
		       case SLTI_F3: I_INST(SLTI); break;
		       case SLTIU_F3: I_INST(SLTIU); break;
		       case XORI_F3: I_INST(XORI); break;
		       case ORI_F3:  I_INST(ORI); break;
		       case ANDI_F3: I_INST(ANDI); break;
		       case SLLI_F3: I_INST(SLLI); break;
		       case SRLI_F3: I_INST(SRLI); break; //SRAI instruction implemented insided her
                   };
		   break;
   	    
	    case OP: 
                   switch(funct3){
		       case ADD_F3: if(funct7) R_INST(SUB) 
				    else       R_INST(ADD); 
				    break;
		       case SLL_F3: R_INST(SLL); break;
		       case SLT_F3: R_INST(SLT); break;
		       case SLTU_F3:  R_INST(SLTU); break;
		       case XOR_F3: R_INST(XOR); break;
		       case SRL_F3: if(funct7) R_INST(SRA) 
				    else R_INST(SRL);
				    break;
		       case OR_F3: R_INST(OR); break; 
		       case AND_F3: R_INST(AND); break; 
                   };
		   break;
 
            #endif
		default: //unimplemented_inst();
		        std::cout << "Instruction not implemented"<< std::endl;
		  break;
		};


}

