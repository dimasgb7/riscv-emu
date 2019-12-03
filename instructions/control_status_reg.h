 void OP_CSRRW(CPU_CONTEXT* context, uint32_t imm, uint32_t rs1, uint32_t rd){
	
 	if( csr_read(&context->rs2,imm,true) ) { 
    		cout << "EXCEPTION";
	}
	
 }


