const char print_bar(){

    std::cout <<"----------------------------------------------------------------------"<<std::endl;
}

void load_dummy_memory(uint32_t* d_mem, uint32_t size, uint32_t* data )
{
	uint32_t* buffer = &d_mem[0];
	for(int i=0;i<size;i++)
		buffer[i] = data[i];

}
//INSTRUCTIONS METHODS
uint32_t inst_build_R(uint32_t funct7, uint32_t rs2, 
                      uint32_t rs1,    uint32_t funct3, 
                      uint32_t rd,     uint32_t opcode ){
    
    uint32_t my_inst;

    std::cout <<"Funct7: " << std::hex << funct7;
    std::cout << "\n";
    std::cout <<"rs2:    "<< std::hex << rs2;
    std::cout << "\n";
    std::cout <<"rs1:    " <<std::hex << rs1;
    std::cout << "\n";
    std::cout <<"funct3: " <<std::hex << funct3;
    std::cout << "\n";
    std::cout <<"rd:     " <<std::hex << rd;
    std::cout << "\n";
    std::cout <<"opcode: " <<std::hex << opcode;
    std::cout << "\n";
    
    my_inst = 
                (funct7<<25)|
                (rs2<<20)|
                (rs1<<15)|
                (funct3<<12)|
                (rd<<7)|
                opcode;
    
    std::cout <<"R instruction generated:  " << std::hex << my_inst;
    std::cout << "\n";
    std::cout << "\n";

    return my_inst;
}

uint32_t inst_build_I(uint32_t imm11_0,     
                      uint32_t rs1,    uint32_t funct3, 
                      uint32_t rd,     uint32_t opcode ){
    
    uint32_t my_inst;

    std::cout <<"imm: " << std::hex << imm11_0;
    std::cout << "\n";
    std::cout <<"rs1:    " <<std::hex << rs1;
    std::cout << "\n";
    std::cout <<"funct3: " <<std::hex << funct3;
    std::cout << "\n";
    std::cout <<"rd:     " <<std::hex << rd;
    std::cout << "\n";
    std::cout <<"opcode: " <<std::hex << opcode;
    std::cout << "\n";
    
    my_inst = 
                (imm11_0<<20)|
                (rs1<<15)|
                (funct3<<12)|
                (rd<<7)|
                opcode;
    
    std::cout <<"I instruction generated:  " << std::hex << my_inst;
    std::cout << "\n";
    std::cout << "\n";

    return my_inst;
}

uint32_t inst_build_S(uint32_t imm_11_0,    uint32_t rs2, 
                      uint32_t rs1,        uint32_t funct3, 
                                           uint32_t opcode ){
    
    uint32_t my_inst;

    std::cout <<"imm: " << std::hex << imm_11_0;
    std::cout << "\n";
    std::cout <<"rs2:    "<< std::hex << rs2;
    std::cout << "\n";
    std::cout <<"rs1:    " <<std::hex << rs1;
    std::cout << "\n";
    std::cout <<"funct3: " <<std::hex << funct3;
    std::cout << "\n";
    std::cout <<"opcode: " <<std::hex << opcode;
    std::cout << "\n";

    uint32_t imm_11 = ((imm_11_0 << 20) & IMM_S_11_MASK) ;
    uint32_t imm_10_5 = ((imm_11_0 << 20) & IMM_S_10_5_MASK) ;
    uint32_t imm_4_1  = ((imm_11_0 << 7) & IMM_S_4_1_MASK) ;
    uint32_t imm_0  = ((imm_11_0 << 7) & IMM_S_0_MASK) ;
    
    my_inst = 
                imm_11|imm_10_5|
                (rs2<<20)     |
                (rs1<<15)     |
                (funct3<<12)  |
                (imm_4_1)|imm_0|
                opcode;
    
    std::cout <<"S instruction generated:  " << std::hex << my_inst;
    std::cout << "\n";
    std::cout << "\n";

    return my_inst;
}

uint32_t inst_build_U(uint32_t imm_31_12,  
                      uint32_t rd,     uint32_t opcode ){
    
    uint32_t my_inst;

    std::cout <<"imm: " << std::hex << imm_31_12;
    std::cout << "\n";
    std::cout <<"rd:     " <<std::hex << rd;
    std::cout << "\n";
    std::cout <<"opcode: " <<std::hex << opcode;
    std::cout << "\n";
    
    my_inst = 
                (imm_31_12 << 12)|
                (rd << RD_OFFSET)|
                opcode;
    
    std::cout <<"U instruction generated:  " << std::hex << my_inst;
    std::cout << "\n";
    std::cout << "\n";

    return my_inst;
}

uint32_t inst_build_B(uint32_t imm_12_1,    uint32_t rs2, 
                      uint32_t rs1,        uint32_t funct3, 
                                           uint32_t opcode ){
    
    uint32_t my_inst;

    std::cout <<"imm: " << std::hex << imm_12_1;
    std::cout << "\n";
    std::cout <<"rs2:    " << std::hex << rs2;
    std::cout << "\n";
    std::cout <<"rs1:    " << std::hex << rs1;
    std::cout << "\n";
    std::cout <<"funct3: " << std::hex << funct3;
    std::cout << "\n";
    std::cout <<"opcode: " << std::hex << opcode;
    std::cout << "\n";

    uint32_t imm_12 =   ((imm_12_1 << 20) & IMM_SB_12_MASK ) ; 
    uint32_t imm_10_5 = ((imm_12_1 << 21) & IMM_SB_10_5_MASK) ;
    uint32_t imm_4_1  = ((imm_12_1 << 8)  & IMM_SB_4_1_MASK) ;
    uint32_t imm_11   = ((imm_12_1 >> 3)  & IMM_SB_11_MASK);
    
    my_inst = 
                imm_12 | imm_10_5|
                (rs2 << RS2_OFFSET)        |
                (rs1 << RS1_OFFSET)        |
                (funct3 << FUNCT3_OFFSET)  |
                imm_4_1 | imm_11|
                opcode;
    
    std::cout <<"SB instruction generated:  " << std::hex << my_inst;
    std::cout << "\n";
    std::cout << "\n";

    return my_inst;
}

uint32_t inst_build_J( uint32_t imm_20_1, 
                        uint32_t rd,     uint32_t opcode ){
    
    uint32_t my_inst;

    std::cout <<"imm: " <<std::hex << imm_20_1;
    std::cout << "\n";
    std::cout <<"rd:     " <<std::hex << rd;
    std::cout << "\n";
    std::cout <<"opcode: " <<std::hex << opcode;
    std::cout << "\n";
   
    uint32_t imm_20   = ((imm_20_1 << 12) & IMM_UJ_20_MASK);
    uint32_t imm_10_5 = ((imm_20_1 << 21) & IMM_UJ_10_5_MASK);
    uint32_t imm_4_1  = ((imm_20_1 << 21) & IMM_UJ_4_1_MASK);
    uint32_t imm_11   = ((imm_20_1 << 10) & IMM_UJ_20_MASK);
    uint32_t imm_19_15   = ((imm_20_1 << 1)  & IMM_UJ_19_15_MASK);
    uint32_t imm_14_12   = ((imm_20_1 << 1)  & IMM_UJ_14_12_MASK);

    my_inst = 
                imm_20|
                imm_10_5|
                imm_4_1|
                imm_11|imm_19_15|imm_14_12|
                (rd<<7)|
                opcode;
    
    std::cout <<"UJ instruction generated:  " << std::hex << my_inst;
    std::cout << "\n";
    std::cout << "\n";

    return my_inst;
}



//REGISTER METHODS
static void dump_all_regs(CPU_CONTEXT* context){
    print_bar();
    
    std::cout << "DUMPING ALL REGISTERS:"<<std::endl<<std::endl;
    for(int i=0; i < 31; i++){
    std::cout << "x"<<i <<":" << std::dec;
    std::cout << context->xreg[i] <<std::hex<<std::endl;
    }
    

}

static void dump_reg(CPU_CONTEXT* context, uint32_t my_reg){
    
    std::cout <<"x" << my_reg << ":" << std::dec;
    std::cout <<std::hex <<context->xreg[my_reg] << std::endl;
}


