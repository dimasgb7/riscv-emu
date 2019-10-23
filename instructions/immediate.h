//Load Imediate
void OP_LUI(CPU_CONTEXT* context, int32_t imm, uint32_t rd ){
 
   if(rd!=0)
    context->xreg[rd] = imm;                        
   
}
//Load immediate + PC
void OP_AUIPC(CPU_CONTEXT* context, int32_t imm, uint32_t rd ){
 
   if(rd!=0)
    context->xreg[rd] = context->pc + imm;
   
}
//ADD to immediate and store on register
void OP_ADDI(CPU_CONTEXT* context, int32_t imm, uint32_t rs1, uint32_t rd){
	
	if(rd!=0) 
	 context->xreg[rd] = (int32_t) (imm + context->xreg[rs1] );
}

//Set if less then immediate
void OP_SLTI(CPU_CONTEXT* context, int32_t imm, uint32_t rs1, uint32_t rd){
	if( (int32_t)context->xreg[rs1] < imm){
	if(rd!=0) 
	 context->xreg[rd] = 1;
	}
	else
	if(rd!=0)
	 context->xreg[rd] = 0;
	
}

//Set if less then immediate unsigned
void OP_SLTIU(CPU_CONTEXT* context, uint32_t imm, uint32_t rs1, uint32_t rd){
	if( context->xreg[rs1] < imm){
	if(rd!=0) 
	 context->xreg[rd] = 1;
	}
	else
	if(rd!=0)
	 context->xreg[rd] = 0;
	
}

//AND operation with immediate
void OP_ANDI(CPU_CONTEXT* context, int32_t imm, uint32_t rs1, uint32_t rd){
	
	if(rd!=0) 
	 context->xreg[rd] =  imm & context->xreg[rs1];

}

//OR operation with immediate
void OP_ORI(CPU_CONTEXT* context, int32_t imm, uint32_t rs1, uint32_t rd){
	
	if(rd!=0) 
	 context->xreg[rd] =  imm | context->xreg[rs1];
}

//XOR operation with immediate
void OP_XORI(CPU_CONTEXT* context, int32_t imm, uint32_t rs1, uint32_t rd){
	
	if(rd!=0) 
	 context->xreg[rd] = imm ^ context->xreg[rs1];
}

//Shift by immediate left logic unsigned
void OP_SLLI(CPU_CONTEXT* context, int32_t imm, uint32_t rs1, uint32_t rd){
	
	if(imm & ~(0x1f) != 0)
		std::cout << "EXCEPTION" <<std::endl;	

	if(rd!=0) 
	 context->xreg[rd] = (context->xreg[rs1] << (imm & 0x1f)) ;
}







uint32_t rotl32c(uint32_t x, uint32_t n)
{
	    return (x<<n) | (x>>(-n&31));
}

//Shift by immediate right arithmatric
void OP_SRAI(CPU_CONTEXT* context, int32_t imm, uint32_t rs1, uint32_t rd){
 	

	if(rd!=0) 
	 context->xreg[rd] =  (int32_t) context->xreg[rs1] >> (imm & 0x1f) ;
	
}

//Shift by immediate right logic
void OP_SRLI(CPU_CONTEXT* context, int32_t imm, uint32_t rs1, uint32_t rd){
	
	if(((imm & ~(0x1f)) & ~(0x400)) != 0) 
		std::cout << "EXCEPTION" <<std::endl;	
	
	if(imm & 0x400) OP_SRAI(context, imm, rs1, rd);
	else if(rd!=0) 
	 context->xreg[rd] = (context->xreg[rs1] >> (imm & 0x1f)) ;
}
