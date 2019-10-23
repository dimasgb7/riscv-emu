//Load 8bit value from memory and sign extended it 32b
void OP_LB(CPU_CONTEXT* context, int32_t imm ,uint32_t rs1, uint32_t rd ){
	
  uint32_t address;
  uint8_t val;
	  
  address = context->xreg[rs1] + imm;
  if(read_mem_u8(&val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
   if(rd!=0)
    context->xreg[rd] = (int8_t) val;

}
//Load 8bit value from memory and zero extend it 32b
void OP_LBU(CPU_CONTEXT* context, int32_t imm ,uint32_t rs1, uint32_t rd ){
	
  uint32_t address;
  uint8_t val;
	  
  address = context->xreg[rs1] + imm;
  if(read_mem_u8(&val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
   if(rd!=0)
    context->xreg[rd] = val;

}

//Load 16bit value from memory and sign extend it to 32bit value
void OP_LH(CPU_CONTEXT* context, int32_t imm ,uint32_t rs1, uint32_t rd ){
	
  uint32_t address;
  uint16_t val;
	  
  address = context->xreg[rs1] + imm;
  
  if(read_mem_u16(&val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
   if(rd!=0)
    context->xreg[rd] = (int16_t) val;

}

//Load 16bit value from memory and zero extend it to 32bit value
void OP_LHU(CPU_CONTEXT* context, int32_t imm ,uint32_t rs1, uint32_t rd ){
	
  uint32_t address;
  uint16_t val;
	  
  address = context->xreg[rs1] + imm;
  if(read_mem_u16(&val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
   if(rd!=0)
    context->xreg[rd] = val;
}

//Load 32bit value from memory and sign extend it
void OP_LW(CPU_CONTEXT* context, int32_t imm ,uint32_t rs1, uint32_t rd ){
	
  uint32_t address;
  uint32_t val;
	  
  address = context->xreg[rs1] + imm;
  if(read_mem_u32(&val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
   if(rd!=0)
    context->xreg[rd] = val;

}




