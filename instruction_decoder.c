#include "instruction_decoder.h"
//#include "imediates.c"

void ID::set_pc(uint32_t argv){

	pc = argv;

} 

void ID::set_regs(INST_REGS argv){

	//Check for instruction dependency
	if(argv.rs1 == inst_regs.rd | argv.rs2 == inst_regs.rd) inst_dep_check();
	else inst_dep_flag = 0;
	inst_regs = argv;
	
}

void ID::set_imm(IMM argv){

	imm = argv;
	
}

void ID::set_ctrl(CTRL_BITS argv){
	
	ctrl = argv;

}

void ID::read_regs(TEMP_REG* reg){
	rs1_val = reg[inst_regs.rs1].out;
	rs2_val = reg[inst_regs.rs2].out;
}

uint32_t ID::get_pc(){ 
	
	return pc;
}

uint32_t ID::get_rd(){

	return inst_regs.rd;
}
uint32_t ID::get_rs1_val(){

	return rs1_val;
}
uint32_t ID::get_rs2_val(){
	
	return rs2_val;
}
uint32_t ID::get_imm(){
	
	return my_imm; 
}


unsigned char ID::get_type(){
	
	return type;
}	

bool ID::get_branch_flag(){
	
	return branch_flag; 
}

bool ID::get_stall(){
	
	return (branch_flag && inst_dep_flag && 1);
}

bool ID::get_nop(){
	
	return (inst_dep_flag && 1);

}

bool ID::get_hazard(){
		
	return (inst_dep_flag && 1);

}
CTRL_BITS ID::get_ctrl(){
	
	return ctrl;
}

void ID::sel_imm(){
	switch(ctrl.opcode)
	{
		case LUI:
		case AUIPC: my_imm = imm.imm_u; break;
		
		case JAL: my_imm = imm.imm_j; break;
		
		case JALR:
		case OPI:
		case LOAD: my_imm = imm.imm_i; break;

		case BRANCH: my_imm = imm.imm_b; break;
		
		case STORE: my_imm = imm.imm_s; break;

	}

}

void ID::branch_check(){
	
	if(ctrl.opcode == BRANCH) branch_flag = 1;

}

void ID::inst_debug(){
	
	std::cout << "ID STAGE:" << std::endl;

	my_opcode_name = get_opcode_name(ctrl.opcode,ctrl.funct3);

	switch(ctrl.opcode){
		case OPI:if(ctrl.funct3 == SRLI_F3) if(my_imm & 0x400) my_opcode_name = "SRAI";
				   break;
		case OP:
			   my_opcode_name = get_opcode_name(ctrl.opcode,ctrl.funct3,ctrl.funct7);
			   break;
	}
	
	std::cout << "-PC [" <<pc <<"]"
	 	  << " Instruction [" << my_opcode_name << "]" 
		  <<std::endl;
}

void ID::inst_dep_check(){

	switch(ctrl.opcode)
	{
		case BRANCH:
		case STORE: 	
		case JALR:
		case OPI:
		case OP:
		case LOAD:  inst_dep_flag = 1;break;
		
		case LUI:
		case JAL:
		case AUIPC: inst_dep_flag = 0;break;

	}
}

void ID::nop(){

	ctrl.nop = true;
}
