#ifndef CPU_UTILS_H
#define CPU_UTILS_H

//RV32I
#define OP_CODE_OFFSET      0
#define RD_OFFSET           7
#define FUNCT3_OFFSET       12
#define RS1_OFFSET          15
#define RS2_OFFSET          20
#define FUNCT7_OFFSET       25
#define IMM_I_OFFSET        20
#define IMM_S_H_OFFSET      25
#define IMM_S_L_OFFSET      7
#define IMM_U_OFFSET        12

#define OP_CODE_MASK 0x7F   
#define RD_MASK 0xF80   
#define RS1_MASK 0xF8000   
#define RS2_MASK 0x1F00000   
#define FUNCT7_MASK 0xFE000000   
#define FUNCT3_MASK 0x7000   

#define IMM_I_MASK 0xFFF00000   
#define IMM_S_H_MASK 0xFE000000  
#define IMM_S_L_MASK 0xF80  
#define IMM_U_MASK 0xFFFFF000   


//RV32G EXTENSION
#define IMM_SB_H_OFFSET     25
#define IMM_SB_L_OFFSET     7
#define IMM_UJ_OFFSET       12

#define IMM_SB_H_MASK 0xFE000000   
#define IMM_SB_L_MASK 0xF80  
#define IMM_UJ_MASK 0xFFFFF000   




#endif
