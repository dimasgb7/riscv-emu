#include "executer.h"
#include "op_codes.h"
#include "cpu_utils.h"
#include "base.c"

#define INST(OPCODE) OP_##OPCODE(context);

void EX::set_pc(uint32_t argv){

	pc = argv;
}

void EX::set_ctrl(CTRL_BITS argv){

	ctrl = argv;
}

void EX::set_imm(uint32_t argv){

	imm = argv;
}

void EX::set_rd(uint32_t argv){

	rd = argv;
}
void EX::set_rs1_val(uint32_t argv){

	rs1_val = argv;
}

void EX::set_rs2_val(uint32_t argv){

	rs2_val = argv;
}

void EX::set_type(unsigned char argc){

	type = argc;
}
bool EX::get_stall(){
	
	return 0;
}

bool EX::get_nop(){

	return 0;
}

bool EX::get_hazard(){

	inst_dep_check();

	return (inst_dep_flag && 1);
}

void EX::inst_debug(){
	
	std::cout << "EX STAGE:" << std::endl;
	my_opcode_name = get_opcode_name(ctrl.opcode,ctrl.funct3);

	switch(ctrl.opcode){
		case OPI:if(ctrl.funct3 == SRLI_F3) if(imm & 0x400) my_opcode_name = "SRAI";
				   break;
		case OP:
			   my_opcode_name = get_opcode_name(ctrl.opcode,ctrl.funct3,ctrl.funct7);
			   break;
	}
	
	std::cout << "-PC [" <<pc <<"]"
	 	  << " Instruction [" << my_opcode_name << "]" 
		  << " IMM [" <<imm<<"]" <<std::endl;
}

void EX::update_context(){
	
	context->pc = pc;
	context->imm = imm;
	context->rd = rd;
	context->rs1_val = rs1_val;
	context->rs2_val = rs2_val;
	context->result = 0;
}

void EX::opcode_table(){
	
	update_context();

	switch(ctrl.opcode){
	
		case LUI:   INST(LUI); break;
		case AUIPC: INST(AUIPC); break;
		//case JAL:   INST(JAL);break;
		//case JALR:  INST(JALR);break;
		case BRANCH:
			switch(ctrl.funct3){
				case BEQ_F3:	INST(BEQ);break;
				case BNE_F3:	INST(BNE);break;
				case BLT_F3:	INST(BLT);break;
				case BGE_F3:	INST(BGE);break;
				case BLTU_F3:	INST(BLTU);break;
				case BGEU_F3:	INST(BGEU);break;
			};
			break;
		
		case LOAD:
			switch(ctrl.funct3){ 
		    		case LB_F3: INST(LB);break;
			    	case LH_F3: INST(LH);break;
				case LW_F3: INST(LW);break;
				case LBU_F3: INST(LBU);break;
			 	case LHU_F3: INST(LHU);break;
				};
			break;
		
		case STORE:
			switch(ctrl.funct3){
				case SB_F3:INST(SB);break;
				case SH_F3:INST(SH);break;
				case SW_F3:INST(SW);break;
			};
			break;
		
		case OP:
			switch(ctrl.funct3){
				case ADD_F3: if(ctrl.funct7) INST(SUB)
					     else	INST(ADD);
				     	     break;
				case SLL_F3: INST(SLL);break;
				case SLT_F3: INST(SLT);break;
				case SLTU_F3: INST(SLTU);break;
				case XOR_F3: INST(XOR);break;
			        case SRL_F3: if(ctrl.funct7) INST(SRA)
					     else INST(SRL);
					     break;
				case OR_F3: INST(OR);break;
		       		case AND_F3: INST(AND);break;
		 	};
			break;			
		
		case OPI:
			switch(ctrl.funct3){
				case ADDI_F3:	INST(ADDI); break;
				case SLTI_F3:	INST(SLTI); break;
				case SLTIU_F3:	INST(SLTIU); break;
				case XORI_F3:	INST(XORI); break;
				case ORI_F3:	INST(ORI); break;
				case ANDI_F3:	INST(ANDI); break;
				case SLLI_F3:	INST(SLLI); break;
				case SRLI_F3:	INST(SRLI); break;
				}; 
			break;
		
		default:
			  std::cout << "Instruction not implemented" << std::endl;
			  break;

	};
}

void EX::write_to_reg(TEMP_REG* reg_table){
	
	reg_table[rd].in = context->result;
	
}

void EX::inst_dep_check(){
	
	if(!ctrl.nop)
	switch(ctrl.opcode)
	{
		case LUI:
		case JAL:
		case JALR:
		case OPI:
		case LOAD:
		case OP:	
		case AUIPC: inst_dep_flag = 1;break;
		
		case BRANCH:break;
		case STORE: break;

		default: inst_dep_flag = 0;

	}
	else inst_dep_flag = 0;
}

void EX::nop(bool arg){
	
	if(arg == true){	
	ctrl.nop = true;	
	rd = 0;
	rs1_val = 0;
	rs2_val = 0;
	ctrl.opcode = 0;
	}
        else 
	ctrl.nop = false;	

}
//void EX::branch(){
	
	
//}
