#include "../regs.h"
//Load Imediate
void OP_LUI(OP_CONTEXT* ct){
 
    if(ct->rd!=0)
     ct->result = (int32_t) ct->imm;                        
   
}
//Load immediate + PC
void OP_AUIPC(OP_CONTEXT* ct){
 
   if(ct->rd != 0)
    ct->result = (int32_t) (ct->pc + (int32_t)(ct->imm) );
   
}

//ADD to immediate and store on register
void OP_ADDI(OP_CONTEXT* ct){
	
	if(ct->rd!=0) 
	 ct->result = (int32_t) ( (int32_t) ct->imm + ct->rs1_val);
}

//Set if less then immediate
void OP_SLTI(OP_CONTEXT* ct){
	
	if( (int32_t)ct->rs1_val < (int32_t) ct->imm){
	if(ct->rd!=0) 
	 ct->result = 1;
	}
	else
	if(ct->rd!=0)
	 ct->result = 0;
	
}

//Set if less then immediate unsigned
void OP_SLTIU(OP_CONTEXT* ct){
	if(ct->imm == 1){
		if(ct->rs1_val <= ct->imm){
			if(ct->rd!=0)
				ct->result = 1;
		} 
		else 
		if(ct->rd!=0)
			ct->result = 0;
	}else 
	{ 
	if( ct->rs1_val < (uint32_t) (int32_t) ct->imm){
	if(ct->rd!=0) 
	 ct->result = 1;
	}
	else
	if(ct->rd!=0)
	 ct->result = 0;
	}
	
}

//AND operation with immediate
void OP_ANDI(OP_CONTEXT* ct){
	
	if(ct->rd!=0) 
	 ct->result =  ct->imm & ct->rs1_val;

}

//OR operation with immediate
void OP_ORI(OP_CONTEXT* ct){
	
	if(ct->rd!=0) 
	 ct->result =  ct->imm | ct->rs1_val;
}

//XOR operation with immediate
void OP_XORI(OP_CONTEXT* ct){
	
	if(ct->rd!=0) 
	 ct->result = ct->imm ^ ct->rs1_val;
}

//Shift by immediate left logic unsigned
void OP_SLLI(OP_CONTEXT* ct){
	
	if(ct->imm & ~(0x1f) != 0)
		std::cout << "EXCEPTION" <<std::endl;	

	if(ct->rd!=0) 
	 ct->result = (ct->rs1_val << (ct->imm & 0x1f)) ;
}

//Shift by immediate right arithmatric
void OP_SRAI(OP_CONTEXT* ct){
 	

	if(ct->rd!=0) 
	 ct->result =  (int32_t) ct->rs1_val >> (ct->imm & 0x1f) ;
	
}

//Shift by immediate right logic
void OP_SRLI(OP_CONTEXT* ct){
	
	if(((ct->imm & ~(0x1f)) & ~(0x400)) != 0) 
		std::cout << "EXCEPTION" <<std::endl;	
	
	if(ct->imm & 0x400) OP_SRAI(ct);
	else if(ct->rd!=0) 
	 ct->result = (ct->rs1_val >> (ct->imm & 0x1f)) ;
}
