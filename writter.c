#include "writter.h"
#include "op_codes.h"
#include "cpu_utils.h"


void WR_R::set_pc(uint32_t argv){

	pc = argv;
}

void WR_R::set_ctrl(CTRL_BITS argv){

	ctrl = argv;
}

void WR_R::set_rd(uint32_t argv){

	rd = argv;
}
void WR_R::set_result(uint32_t argv){

	result = argv;
}

void WR_R::set_type(unsigned char argc){

	type = argc;
}




