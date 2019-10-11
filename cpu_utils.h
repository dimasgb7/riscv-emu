#ifndef CPU_UTILS_H
#define CPU_UTILS_H

//RV32I
//DEFAULTS
#define OP_CODE_OFFSET      0
#define RD_OFFSET           7
#define FUNCT3_OFFSET       12
#define RS1_OFFSET          15
#define RS2_OFFSET          20
#define FUNCT7_OFFSET       25

//I-TYPE
#define IMM_I_11_OFFSET     31
#define IMM_I_10_5_OFFSET   25
#define IMM_I_4_1_OFFSET    21
#define IMM_I_0_OFFSET      20

//S-TYPE
#define IMM_S_11_OFFSET     31
#define IMM_S_10_5_OFFSET   25
#define IMM_S_4_1_OFFSET    8
#define IMM_S_0_OFFSET      7

//U-TYPE
#define IMM_U_31_OFFSET     31
#define IMM_U_30_20_OFFSET  20
#define IMM_U_19_15_OFFSET  15
#define IMM_U_14_12_OFFSET  12

//SB-TYPE
#define IMM_SB_12_OFFSET     31
#define IMM_SB_10_5_OFFSET   25
#define IMM_SB_4_1_OFFSET    8
#define IMM_SB_11_OFFSET     7
//UJ-TYPE
#define IMM_UJ_20_OFFSET       31
#define IMM_UJ_10_5_OFFSET     25
#define IMM_UJ_4_1_OFFSET      21
#define IMM_UJ_11_OFFSET       20
#define IMM_UJ_19_15_OFFSET    15
#define IMM_UJ_14_12_OFFSET    12


//DEFAULTS
#define OP_CODE_MASK 0x7F   
#define RD_MASK 0xF80   
#define RS1_MASK 0xF8000   
#define RS2_MASK 0x1F00000   
#define FUNCT7_MASK 0xFE000000   
#define FUNCT3_MASK 0x7000   

//I-TYPE
#define IMM_I_MASK      0xFFF00000   
#define IMM_I_11_MASK   0x80000000   
#define IMM_I_10_5_MASK 0x7E000000   
#define IMM_I_4_1_MASK  0x1E00000  
#define IMM_I_0_MASK    0x100000 

//S-TYPE
#define IMM_S_11_MASK   0x80000000  
#define IMM_S_10_5_MASK 0x7E000000  
#define IMM_S_4_1_MASK  0xF00  
#define IMM_S_0_MASK    0x80  

//SB-TYPE
#define IMM_SB_12_MASK   0x80000000  
#define IMM_SB_10_5_MASK 0x7E000000  
#define IMM_SB_4_1_MASK  0xF00  
#define IMM_SB_11_MASK   0x80  

//U-TYPE
#define IMM_U_31_12_MASK  0xFFFFF000   
#define IMM_U_31_MASK     0x80000000 
#define IMM_U_30_20_MASK  0x7FF00000
#define IMM_U_19_15_MASK  0xF8000
#define IMM_U_14_12_MASK  0x7000

//UJ-TYPE
#define IMM_UJ_20_MASK     0x80000000 
#define IMM_UJ_10_5_MASK   0x7E000000
#define IMM_UJ_4_1_MASK    0x1E00000
#define IMM_UJ_11_MASK     0x100000
#define IMM_UJ_19_15_MASK  0xF8000
#define IMM_UJ_14_12_MASK  0x7000


#endif
