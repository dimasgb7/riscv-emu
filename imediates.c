int32_t I_IMMEDIATE(uint32_t inst) {

    return ( (inst & IMM_I_MASK) >> 20 );
    
}

int32_t S_IMMEDIATE(uint32_t inst) {

    return (inst & IMM_S_11_MASK) >> (31 - 11) |
           (inst & IMM_S_10_5_MASK) >> (25 - 5) |
           (inst & IMM_S_4_1_MASK) >> ( 8 - 1) |
           (inst & IMM_S_0_MASK >> (7 - 0));
    
}

int32_t SB_IMMEDIATE(uint32_t inst) {

    return ((inst & IMM_SB_12_MASK) >> (31 - 11)) |
           ((inst & IMM_SB_11_MASK) << (11 - 7)) |
           ((inst & IMM_SB_10_5_MASK) >> ( 25 - 5)) |
           ((inst & IMM_SB_4_1_MASK) >> (8 - 1));
    
    
}

int32_t U_IMMEDIATE(uint32_t inst) {

    return  (inst & IMM_U_31_12_MASK) ;
    
}

int32_t UJ_IMMEDIATE(uint32_t inst) {

    return ( (inst & IMM_UJ_20_MASK) >> 20 )|
           ( (inst & IMM_UJ_19_15_MASK )) |
           ( (inst & IMM_UJ_14_12_MASK )) |
           ( (inst & IMM_UJ_11_MASK >> (20 - 11))) |
           ( (inst & IMM_UJ_10_5_MASK >> (25 - 5))) |
           ( (inst & IMM_UJ_4_1_MASK >> (21 - 1)));
    
}
