#ifndef CPU_UTILS_H
#define CPU_UTILS_H

#define OP_CODE_MASK 0x7F   
#define RD_MASK 0xF80   
#define RS1_MASK 0xF8000   
#define RS2_MASK 0x1F00000   
#define FUNC7_MASK 0xFE000000   
#define FUNC3_MASK 0x7000   

#define IMM_I_MASK 0xFFF00000   
#define IMM_S_MASK 0xFE000000  
#define IMM_B_MASK 0xFE000000   
#define IMM_U_MASK 0xFFFFF000   
#define IMM_J_MASK 0xFFFFF000   

#endif
