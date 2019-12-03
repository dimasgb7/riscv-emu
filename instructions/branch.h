//Branch if Equal
void OP_BEQ(OP_CONTEXT* ct){
   	
	int32_t is_equal;
	
	is_equal = ( ct->rs1_val == ct->rs2_val );
	
	if(is_equal) 
	ct->result = ct->pc + ct->imm;

}

//Branch if NOT equal
void OP_BNE(OP_CONTEXT* ct){

   	
	int32_t is_equal;
	
	is_equal = (ct->rs1_val == ct->rs2_val);
	
	if(! is_equal) 
	ct->result = ct->pc + ct->imm;

}

//Branch if lower then 
void OP_BLT(OP_CONTEXT* ct){

	int32_t is_lower;
	
	is_lower = ( ct->rs1_val < ct->rs2_val );
	
	if(is_lower) 
	ct->result = ct->pc + ct->imm;

}

//Branch if bigger then 
void OP_BGE(OP_CONTEXT* ct){
   	
	int32_t is_greater;
	
	is_greater = (ct->rs1_val > ct->rs2_val);
	
	if(is_greater) 
	ct->result = ct->pc + ct->imm;

}

//Branch if lower then 
void OP_BLTU(OP_CONTEXT* ct){

	int32_t is_lower;
	
	is_lower = ( (int32_t) ct->rs1_val < (int32_t) ct->rs2_val );
	
	if(is_lower) 
	ct->result = ct->pc + ct->imm;

}

//Branch if bigger then 
void OP_BGEU(OP_CONTEXT* ct){

	int32_t is_greater;
	
	is_greater = ( (int32_t) ct->rs1_val > (int32_t) ct->rs2_val );
	
	if(is_greater) 
	ct->result = ct->pc + ct->imm;

}


