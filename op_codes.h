#ifndef RV32I_BASE_OP_CODES_H
#define RV32I_BASE_OP_CODES_H

enum RV32I_BASE_OP_CODES{
    #ifdef SET_RV32I
	LUI 	=	0b0110111,
	AUIPC	=	0b0010111,
	JAL	    =	0b1101111,
	JALR	=	0b1100111,
	
    	BRANCH  = 	0b1100011,
	BEQ	=	0b1100011,
	BNE	=	0b1100011,
	BLT	=	0b1100011,
	BGE	=	0b1100011,
	BLTU	=	0b1100011,
	BGEU	=	0b1100011,
	
	LOAD	= 	0b0000001,	
	LB	= 	0b0000001,	
	LH	= 	0b0000001,	
	LW	= 	0b0000001,	
	LBU	= 	0b0000001,	
	LHU	= 	0b0000001,
	
	STORE 	= 	0b0100011,	
	SB 	= 	0b0100011,	
	SH 	= 	0b0100011,	
	SW 	= 	0b0100011,
	
	OPI	=	0b0010011,
	ADDI	=	0b0010011,
	SLTI	=	0b0010011,
	SLTIU	=	0b0010011,
	XORI	=	0b0010011,
	ORI	=	0b0010011,
	ANDI	=	0b0010011,
	SLLI	=	0b0010011,
	SRLI	=	0b0010011,
	SRAI	=	0b0010011,

	OP	=	0b0110011,
	ADD	=	0b0110011,
	SUB	=	0b0110011,
	SRL	=	0b0110011

    #endif
};

enum RV32I_BASE_FUNCT3{
    #ifdef SET_RV32I
	JALR_F3	=	0b000,

	BEQ_F3	=	0b000,
	BNE_F3	=	0b001,
	BLT_F3	=	0b100,
	BGE_F3	=	0b101,
	BLTU_F3	=	0b110,
	BGEU_F3	=	0b111,
	
	LB_F3	=	0b000,
	LH_F3	=	0b001,
	LW_F3	=	0b010,
	LBU_F3	=	0b100,
	LHU_F3	=	0b101,

	SB_F3	=	0b000,
	SH_F3	=	0b001,
	SW_F3	=	0b010,

	ADDI_F3	=	0b000,
	SLTI_F3	=	0b010,
	SLTIU_F3=	0b011,
	XORI_F3	=	0b100,
	ORI_F3	=	0b110,
	ANDI_F3	=	0b111,
	SLLI_F3	=	0b001,
	SRLI_F3	=	0b101,
	SRAI_F3	=	0b101,
	
	ADD_F3 	= 	0b000,
	SUB_F3 	= 	0b000,
	SLL_F3 	= 	0b001,
	SLT_F3 	= 	0b010,
	SLTU_F3	= 	0b011,
	XOR_F3 	= 	0b100,
	SRL_F3 	= 	0b101,
	SRA_F3 	= 	0b101,
	OR_F3 	= 	0b110,
	AND_F3 	= 	0b111,



    
	#endif
};

const char* get_opcode_name(uint8_t opcode, uint32_t funct3=0, uint32_t funct7=0)
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
                    case BEQ_F3 : return "BEQ";
                    case BNE_F3 : return "BNE";
                    case BLT_F3 : return "BLT";
                    case BGE_F3 : return "BGE";
                    case BLTU_F3 : return "BLTU";
                    case BGEU_F3 : return "BGEU";
                    };
	  case LOAD:
		  switch(funct3)
		  {
		    case LB_F3 : return "LB";
		    case LH_F3 : return "LH";
		    case LW_F3 : return "LW";
		    case LBU_F3 : return "LBU";
		    case LHU_F3 : return "LHU";
		  };	       
	  
	  case STORE:
		  switch(funct3)
		  {
		    case SB_F3 : return "SB";
		    case SH_F3 : return "SH";
		    case SW_F3 : return "SW";
		  };	       
	
	  case OPI:
		  switch(funct3)
		  {
		    case ADDI_F3 : return "ADDI";
		    case SLTI_F3 : return "SLTI";
		    case SLTIU_F3: return "SLTIU";
		    case XORI_F3 : return "XORI";
		    case ORI_F3  : return "ORI";
		    case ANDI_F3 : return "ANDI";
		    case SLLI_F3 : return "SLLI";
		    case SRLI_F3 : return "SRLI";
		    //case SRAI_F3 : return "SRAI";
		  };	       
          
	  case OP:
		  switch(funct3)
		  {
		    case ADD_F3 : if(funct7) return "SUB"; else return "ADD" ;
		    case SLL_F3 : return "SLL";
		    case SLT_F3	: return "SLT";
		    case XOR_F3 : return "XOR";
		    case SRL_F3  : if(funct7) return "SRA"; else return "SRL";
		    case OR_F3 	 : return "OR";
		    case AND_F3  : return "AND";
		  };	       
          

          default: return "NO MAPPING";         
      }


}; 

#endif
