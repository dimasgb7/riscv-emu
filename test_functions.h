void load_dummy_memory(uint32_t* d_mem, uint32_t size, uint32_t* data )
{
	uint32_t* buffer = &d_mem[0];
	for(int i=0;i<size;i++)
		buffer[i] = data[i];

}

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

    uint32_t imm_11_5 = ((imm_11_0 << IMM_S_H_OFFSET) & IMM_S_H_MASK) ;
    uint32_t imm_4_0  = ((imm_11_0 << IMM_S_L_OFFSET) & IMM_S_L_MASK) ;
    
    my_inst = 
                imm_11_5      |
                (rs2<<20)     |
                (rs1<<15)     |
                (funct3<<12)  |
                (imm_4_0)     |
                opcode;
    
    std::cout <<"S instruction generated:  " << std::hex << my_inst;
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
                (imm_31_12 << IMM_U_OFFSET)|
                (rd << RD_OFFSET)|
                opcode;
    
    std::cout <<"U instruction generated:  " << std::hex << my_inst;
    std::cout << "\n";

    return my_inst;
}


#ifdef RV32G_EXTENSION
uint32_t inst_build_SB(uint32_t imm_11_0,    uint32_t rs2, 
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

    uint32_t imm_11_5 = ((imm_11_0 << IMM_S_H_OFFSET) & IMM_S_H_MASK) ;
    uint32_t imm_4_0  = ((imm_11_0 << IMM_S_L_OFFSET) & IMM_S_L_MASK) ;
    
    my_inst = 
                imm_11_5      |
                (rs2<<20)     |
                (rs1<<15)     |
                (funct3<<12)  |
                (imm_4_0)     |
                opcode;
    
    std::cout <<"S instruction generated:  " << std::hex << my_inst;
    std::cout << "\n";

    return my_inst;
}

uint32_t inst_build_UJ(uint32_t funct7, uint32_t rs2, 
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
    
    std::cout <<"Instruction generated:  " << std::hex << my_inst;
    std::cout << "\n";

    return my_inst;
}
#endif
