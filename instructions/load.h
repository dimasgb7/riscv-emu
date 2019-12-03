//Load 8bit value from memory and sign extended it 32b
void OP_LB(OP_CONTEXT* ct){
	
  uint32_t address;
  uint8_t val;
	  
  address = ct->rs1_val + ct->imm;
  if(read_mem_u8(&val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
   if(ct->rd!=0)
    ct->result = (int8_t) val;

}
//Load 8bit value from memory and zero extend it 32b
void OP_LBU(OP_CONTEXT* ct ){
	
  uint32_t address;
  uint8_t val;
	  
  address = ct->rs1_val + ct->imm;
  if(read_mem_u8(&val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
   if(ct->rd!=0)
    ct->result = val;

}

//Load 16bit value from memory and sign extend it to 32bit value
void OP_LH(OP_CONTEXT* ct ){
	
  uint32_t address;
  uint16_t val;
	  
  address = ct->rs1_val + ct->imm;
  
  if(read_mem_u16(&val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
   if(ct->rd!=0)
    ct->result = (int16_t) val;

}

//Load 16bit value from memory and zero extend it to 32bit value
void OP_LHU(OP_CONTEXT* ct ){
	
  uint32_t address;
  uint16_t val;

  std::cout << "OOI: "<<ct->imm<<std::endl;  
  std::cout << "OOI: "<<ct->rs1_val<<std::endl; 

  address = ct->rs1_val + ct->imm;
  if(read_mem_u16(&val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
   if(ct->rd!=0)
    ct->result = val;
}

//Load 32bit value from memory and sign extend it
void OP_LW(OP_CONTEXT* ct){
	
  uint32_t address;
  uint32_t val;
	  
  address = ct->rs1_val + ct->imm;
  if(read_mem_u32(&val, address)){
	std::cout <<"Fill exception function "<< std::endl;	 
  } 
  
   if(ct->rd!=0)
    ct->result = val;

}




