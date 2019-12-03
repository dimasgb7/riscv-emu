#include "cpu.h"
#include "op_codes.h"

//#include "imediates.c"

#include "instruction_fetcher.c"
#include "instruction_decoder.c"
#include "executer.c"
//#include "writter.c"

//#include "table.c"
//#include "<stdlib.h>" 

static void dump_all_regs(CPU_CONTEXT* context);
static void dump_reg(CPU_CONTEXT* context, uint32_t my_reg);

//REGISTER METHODS
static void dump_all_regs(CPU_CONTEXT* context){
    print_bar();
    
    std::cout << "DUMPING ALL REGISTERS:"<<std::endl<<std::endl;
    for(int i=0; i < 31; i++){
    std::cout << "x"<<i <<":" << std::dec;
    std::cout << context->xreg[i] <<std::hex<<std::endl;
    }
    

}

static void dump_reg(uint32_t my_reg){
    
   
    std::cout <<"x" << my_reg << ":" << std::dec;
	    std::cout << std::hex << reg_table[my_reg].out << std::endl;
}

int cpu_execute(CPU_CONTEXT* context, uint32_t number_of_instructions){
	
	inst_fetcher.split_inst();
	
	uint32_t inst;
	uint32_t mem_position;	
	uint32_t number_of_cycles = number_of_instructions + 2;
	std::cout<<"BEGINING EXECUTION LOG:" <<std::endl<<std::endl;	
	
	//Main execution loop	
	while( context->cycle_count < number_of_cycles + 2) { 	
	 #ifdef SET_DEBUG
		 std::cout<<"At cycle "<<context->cycle_count<<":"
			 << std::endl ;
	 #endif
	
		//Update all latch structures
		update_latch(context);	
		
		//Prepare next instruction
		context->next_pc+=4;
		
		#ifdef SET_DEBUG
		inst_fetcher.inst_debug();
		inst_decoder.inst_debug();
		executer.inst_debug();
		#endif
		
		//Call all components methods
		update_component();

		//CTRL FLAGS CHECK
		branch_set();		
		hazard_judge();
	
		//TEMPORAL REGISTERS UPDATE
		update_regs();	
       		
		//Control PC while stall and NOP  	
		if(IF_STALL | IF_NOP) context->next_pc = context->pc;	
	       		
       		//Missaligned fetch test		
		if(context->next_pc & 3) exit(1);
		
		//Update next instruction path
		context->pc = context->next_pc;

		//End of a cycle
		context->cycle_count+=1;
	
	#ifdef SET_DEBUG
		std::cout<<std::endl;		
		dump_reg(0);
        	dump_reg(1);
        	dump_reg(2);
        	dump_reg(3);
        	dump_reg(4);
        	dump_reg(5);
        	dump_reg(6);
		print_bar();
	#endif
	} 
}


void update_regs(){
	for (int i = 0; i < 32; i++)
		reg_table[i].update(); 
}

void update_latch(CPU_CONTEXT* context){
	
	//EX Stage
	if(!EX_STALL){	
		executer.set_pc(inst_decoder.get_pc());
		executer.set_rd(inst_decoder.get_rd());
		executer.set_rs1_val(inst_decoder.get_rs1_val());
		executer.set_rs2_val(inst_decoder.get_rs2_val());
		executer.set_imm(inst_decoder.get_imm());
		executer.set_ctrl(inst_decoder.get_ctrl());
	} 
	//ID Stage
	if(!ID_STALL){
		inst_decoder.set_pc(inst_fetcher.get_pc() );	
		inst_decoder.set_ctrl(inst_fetcher.get_ctrl());
		inst_decoder.set_imm(inst_fetcher.get_imm());
		inst_decoder.set_regs(inst_fetcher.get_inst_regs());	
	}
	//IF Stage
	if(!IF_STALL){
		inst_fetcher.set_pc(context->pc);
		inst_fetcher.set_inst(RAM);
	}	

}

void update_component(){

	//IF STAGE
	if(!IF_NOP){ 
		inst_fetcher.split_inst();
	}
	else
	{
		inst_fetcher.nop();
	}
	//ID STAGE
	if(!ID_NOP){	
		inst_decoder.read_regs(reg_table);	
		inst_decoder.sel_imm();
		inst_decoder.branch_check();
	}
	else {
		inst_decoder.nop();
	}
	//EX STAGE
	if(!EX_NOP){	
		executer.opcode_table();
		executer.write_to_reg(reg_table);
	}
	else{
		std::cout<<"EXECUTION NOP SET!"<<std::endl;
		executer.nop(true);
	}
	
}

void hazard_judge(){ 
	
	bool dependency_hazard = inst_decoder.get_hazard() && executer.get_hazard();
	std::cout << "DECODER HAZARD:" << inst_decoder.get_hazard()<<std::endl;
	std::cout << "EXECUTER HAZARD:" << executer.get_hazard()<<std::endl;
	
	if( dependency_hazard ){
		std::cout << "HAZARD FOUND!!!!!!!!" <<std::endl;
		IF_NOP = false;
		ID_NOP = false;
		EX_NOP = true;
	}
	
	else {
		executer.nop(false);

		IF_NOP = false;
		ID_NOP = false;
		EX_NOP = false;
	}

	if( dependency_hazard ) {
		IF_STALL = true;
		ID_STALL = true;
		EX_STALL = true;
	}
	else { 
		IF_STALL = false;
		ID_STALL = false;
		EX_STALL = false;
	}
	

}

void check_nop(){ 



}

void check_stall(){

}


void branch_set(){

	inst_fetcher.set_branch_flag(inst_decoder.get_branch_flag());

}

