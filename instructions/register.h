//ADD RS2 and RS1 registers
void OP_ADD(OP_CONTEXT* ct){
	
	if(ct->rd!=0) 
	 ct->result = (int32_t)  (ct->rs1_val + ct->rs2_val );
}
//SUBtract RS2 and RS1 registers
void OP_SUB(OP_CONTEXT* ct){
	
	if(ct->rd!=0) 
	 ct->result = (int32_t) (ct->rs1_val - ct->rs2_val);
}

//Is RS2 bigger than RS1 signed
void OP_SLL(OP_CONTEXT* ct){
	
	if(ct->rd!=0) 
		ct->result = (int32_t) ct->rs1_val << (0x1f & ct->rs2_val) ; 
}


//Is RS2 bigger than RS1 signed
void OP_SLT(OP_CONTEXT* ct){
	
	switch( (int32_t) ct->rs2_val > (int32_t) ct->rs1_val) {
		case 0: if(ct->rd != 0) ct->result = 0;break;	
		case 1: if(ct->rd != 0) ct->result = 1;break;
	}	

}
//Is RS2 bigger than RS1 unsigned
void OP_SLTU(OP_CONTEXT* ct){
	
	switch( ct->rs2_val >  ct->rs1_val ) {
		case 0: if(ct->rd!=0) ct->result = 0;break;	
		case 1: if(ct->rd!=0) ct->result = 1;break;
	}	

}


//XOR operation between RS1 and RS2	
void OP_XOR(OP_CONTEXT* ct){
	
	if(ct->rd!=0) 
	 ct->result = (ct->rs1_val ^ ct->rs2_val );
}

//Shift Righ Logic
void OP_SRL(OP_CONTEXT* ct){
	
	if(ct->rd!=0)
		ct->result = (int32_t) ((uint32_t) ct->rs1_val >> (0x1f & ct->rs2_val));

}

//Shift Right Arithmetric
void OP_SRA(OP_CONTEXT* ct){
	
	if(ct->rd!=0)
		ct->result = (int32_t) ct->rs1_val >> (0x1f & ct->rs2_val);

}

//AND operation between RS1 and RS2
void OP_AND(OP_CONTEXT* ct){
	
	if(ct->rd!=0) 
	 ct->result = (ct->rs1_val & ct->rs2_val );
}
//OR operation between RS1 and RS2
void OP_OR(OP_CONTEXT* ct){
	
	if(ct->rd!=0) 
	 ct->result = (ct->rs1_val | ct->rs2_val);
}
