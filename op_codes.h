#ifndef RV32I_BASE_OP_CODES_H
#define RV32I_BASE_OP_CODES_H

enum RV32I_BASE_OP_CODES{
    #ifdef SET_RV32I
	LUI 	=	0b0110111,
	AUIPC	=	0b0010111,
	JAL	    =	0b1101111,
	JALR	=	0b1100111,
	
	BEQ	=	0b1100011,
	BNE	=	0b1100011,
	BLT	=	0b1100011,
	BGE	=	0b1100011,
	BLTU	=	0b1100011,
	BGEU	=	0b1100011,
    BEQ_BNE_BLT_BGE_BLTU_BGEU = 0b1100011

    #endif
};

enum RV32I_BASE_FUNCT3{
    #ifdef SET_RV32I
	JALR_FUNCT3	=	0b000,

	BEQ_FUNCT3	=	0b000,
	BNE_FUNCT3	=	0b001,
	BLT_FUNCT3	=	0b100,
	BGE_FUNCT3	=	0b101,
	BLTU_FUNCT3	=	0b110,
	BGEU_FUNCT3	=	0b111

    #endif
};

const char* get_opcode_name(uint8_t opcode, uint32_t funct3)
{

      switch (opcode)
      {
          case LUI:     return "LUI";
          case AUIPC:   return "AUIPC";
          case JAL:     return "JAL"; 
          case JALR:    return "JALR"; 
          case BEQ:     
                  switch(funct3)
                  {
                    case 0x0 : return "BEQ";
                    case 0x1 : return "BNE";
                    case 0x4 : return "BLT";
                    case 0x5 : return "BGE";
                    case 0x6 : return "BLTU";
                    case 0x7 : return "BGEU";
                    };


          
          default: return "NO MAPPING";         
      }


}; 
#endif
