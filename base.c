#include "cpu_utils.h"

void load_rd(CPU_CONTEXT* context, uint32_t rd, uint32_t value) {
	
	if(rd!=0)
	 context->xreg[rd] = value;
}





#include "instructions/immediate.h"
#include "instructions/jump.h"
#include "instructions/branch.h"
#include "instructions/load.h"
#include "instructions/store.h"
#include "instructions/register.h"
