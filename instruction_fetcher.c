#include "instruction_fetcher.h"
#include "op_codes.h"
#include "imediates.c"

void IF::split_inst(){

	//Break instructions ons data sets to be sampled
	ctrl.opcode  = inst & OP_CODE_MASK;
	inst_regs.rd 	= (inst & RD_MASK) >> RD_OFFSET;
	inst_regs.rs1 	= (inst & RS1_MASK) >> RS1_OFFSET;
	inst_regs.rs2 	= (inst & RS2_MASK) >> RS2_OFFSET;
	
	ctrl.funct3  = (inst & FUNCT3_MASK)>>12;
	ctrl.funct7  = inst & FUNCT7_MASK;
	
	imm.imm_i   = I_IMMEDIATE(inst);
	imm.imm_s   = S_IMMEDIATE(inst);
	imm.imm_b   = B_IMMEDIATE(inst);
	imm.imm_u   = U_IMMEDIATE(inst);
	imm.imm_j   = J_IMMEDIATE(inst);
}
void IF::set_pc(uint32_t pc_arg){

	pc = pc_arg;

}
void IF::set_inst(uint32_t* mem){
	inst = *((uint32_t *) (mem + pc));
	std::cout <<"INST FETCH:" <<inst << std::endl;
}

void IF::set_branch_flag(bool argv){

	branch_flag  = argv;
}
uint32_t IF::get_inst(){

	return inst;
}

uint32_t IF::get_rd() {
	return inst_regs.rd;
}
uint32_t IF::get_rs1(){
	return inst_regs.rs1;
}
uint32_t IF::get_rs2() {
	return inst_regs.rs2;
}

uint32_t IF::get_opcode() {
	return ctrl.opcode;
}
uint32_t IF::get_funct7() {
	return ctrl.funct7;
}
uint32_t IF::get_funct3() {
	return ctrl.funct3;
}

uint32_t IF::get_pc() {
	return pc;
}
bool IF::get_stall(){
	
	return (branch_flag & 1);
}

bool IF::get_nop(){
	
	return 0;
}
IMM IF::get_imm() {
	return imm;
}

INST_REGS IF::get_inst_regs() {
	return inst_regs;
}

CTRL_BITS IF::get_ctrl(){
	return ctrl;
}


void IF::set_type(){


	switch ( get_opcode() )
	{
		case 0x37:
		case 0x17:
			type = 'U'; break;
		case 0x6f:
			type = 'J'; break;
		case 0x67:
		case 0x13:
		case 0x1b:
			type = 'I'; break;
		case 0x03:
			type = 'L'; break;
		case 0x63:
			type = 'B'; break;
		case 0x23:
			type = 'S'; break;
		case 0x33:
		case 0x3b:
			type = 'R'; break;
		default: std::cout<<"Unknown inst"<<std::endl;
	}
}

void IF::inst_debug(){
	
	std::cout << "IF STAGE:" << std::endl;
	std::cout << "-PC [" <<pc <<"]"
		  << " Instruction [" << inst << "]" << std::endl;
}
void IF::nop(){

	ctrl.nop = true;
}
