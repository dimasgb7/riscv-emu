//Store 8bit value from memory and sign extended it 32b
void OP_SB(CPU_CONTEXT* context, int32_t imm, uint32_t rs2, uint32_t rs1){
	
  uint32_t address;
  uint8_t val;
	  
  address = context->xreg[rs1] + imm;
 
  val = context->xreg[rs2];

  if(write_mem_u8(val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
  }

//Load 8bit value from memory and zero extend it 32b
void OP_SH(CPU_CONTEXT* context, int32_t imm, uint32_t rs2, uint32_t rs1){
	
  uint32_t address;
  uint16_t val;
	  
  address = context->xreg[rs1] + imm;
  
  val = context->xreg[rs2];
 
  if(write_mem_u16(val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
}

//Load 16bit value from memory and sign extend it to 32bit value
void OP_SW(CPU_CONTEXT* context, int32_t imm, uint32_t rs2, uint32_t rs1){
	
  uint32_t address;
  uint32_t val;
	  
  address = context->xreg[rs1] + imm;
  val = context->xreg[rs2];

	std::cout <<"IMMEDIATE "<<imm <<std::endl;	 
  if(write_mem_u32(val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
}
