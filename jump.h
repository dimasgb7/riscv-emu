//Jump Immediate and save next instruction
void OP_JAL(CPU_CONTEXT* context, int32_t imm, uint32_t rd ){

   if(rd!=0)
    context->xreg[rd] = context->pc + 4;
   context->next_pc = context->pc + imm;

}
//Jump immediate + register and save next instruction
void OP_JALR(CPU_CONTEXT* context, int32_t imm, uint32_t rs1, uint32_t rd ){

   if(rd!=0)
    context->xreg[rd] = context->pc + 4;
   context->next_pc = context->pc + imm + context->xreg[rs1] & ~1;

}
