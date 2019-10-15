//Branch if Equal
void OP_BEQ(CPU_CONTEXT* context, int32_t imm, uint32_t rs2, uint32_t rs1, uint32_t rd ){

   	
	int32_t is_equal;
	
	is_equal = ( context->xreg[rs1] == context->xreg[rs2] );
	
	if(is_equal) 
	context->next_pc = context->pc + imm;

}

//Branch if NOT equal
void OP_BNE(CPU_CONTEXT* context, int32_t imm, uint32_t rs2, uint32_t rs1, uint32_t rd ){

   	
	int32_t is_equal;
	
	is_equal = (context->xreg[rs1] == context->xreg[rs2]);
	
	if(! is_equal) 
	context->next_pc = context->pc + imm;

}

//Branch if lower then 
void OP_BLT(CPU_CONTEXT* context, int32_t imm, uint32_t rs2, uint32_t rs1, uint32_t rd ){

	int32_t is_lower;
	
	is_lower = (context->xreg[rs1] < context->xreg[rs2]);
	
	if(is_lower) 
	context->next_pc = context->pc + imm;

}

//Branch if bigger then 
void OP_BGE(CPU_CONTEXT* context, int32_t imm, uint32_t rs2, uint32_t rs1, uint32_t rd ){
   	
	int32_t is_greater;
	
	is_greater = (context->xreg[rs1] > context->xreg[rs2]);
	
	if(is_greater) 
	context->next_pc = context->pc + imm;

}

//Branch if lower then 
void OP_BLTU(CPU_CONTEXT* context, int32_t imm, uint32_t rs2, uint32_t rs1, uint32_t rd ){

	int32_t is_lower;
	
	is_lower = ( (int32_t) context->xreg[rs1] < (int32_t) context->xreg[rs2] );
	
	if(is_lower) 
	context->next_pc = context->pc + imm;

}

//Branch if bigger then 
void OP_BGEU(CPU_CONTEXT* context, int32_t imm, uint32_t rs2, uint32_t rs1, uint32_t rd ){

	int32_t is_greater;
	
	is_greater = ( (int32_t) context->xreg[rs1] > (int32_t) context->xreg[rs2]);
	
	if(is_greater) 
	context->next_pc = context->pc + imm;

}


