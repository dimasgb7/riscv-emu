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
