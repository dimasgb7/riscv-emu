#include "cpu_utils.h"
void OP_LUI(CPU_CONTEXT* context, int32_t imm, uint32_t rd ){
 
   if(rd!=0)
    context->xreg[rd] = imm;                        
   
}

void OP_AUIPC(CPU_CONTEXT* context, int32_t imm, uint32_t rd ){
 
   if(rd!=0)
    context->xreg[rd] = context->pc + imm;
   
}

void OP_JAL(CPU_CONTEXT* context, int32_t imm, uint32_t rd ){
 
   if(rd!=0)
    context->xreg[rd] = context->pc + 1;


   
}
