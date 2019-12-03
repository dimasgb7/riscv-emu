//Store 8bit value from memory and sign extended it 32b
void OP_SB(OP_CONTEXT* ct){
	
  uint32_t address;
  uint8_t val;
	  
  address = ct->rs1_val + ct->imm;
 
  val = ct->rs2_val;

  if(write_mem_u8(val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
  }

//Load 8bit value from memory and zero extend it 32b
void OP_SH(OP_CONTEXT* ct){
	
  uint32_t address;
  uint16_t val;
	  
  address = ct->rs1_val + ct->imm;
  
  val = ct->rs2_val;
 
  if(write_mem_u16(val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
}

//Load 16bit value from memory and sign extend it to 32bit value
void OP_SW(OP_CONTEXT* ct){
	
  uint32_t address;
  uint32_t val;
	  
  address = ct->rs1_val + ct->imm;
  val = ct->rs2_val;

  if(write_mem_u32(val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
}
