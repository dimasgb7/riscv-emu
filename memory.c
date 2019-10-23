
#define RAM_SIZE 0x10000
uint32_t RAM[RAM_SIZE];
uint32_t ram_start;

bool read_mem_u8(uint8_t *p_val, uint32_t addr){
	
	addr -= ram_start;
	if(addr > RAM_SIZE){
		*p_val = 0;
		std::cout << "illegal read"<<std::endl;
		return 1;
	} else {
		uint32_t* p = RAM + addr;
		*p_val = p[0];
	}

	return 0;
}

bool read_mem_u16(uint16_t *p_val, uint32_t addr){
	
	addr -= ram_start;
	if(addr > RAM_SIZE){
		*p_val = 0;
		std::cout << "illegal read"<<std::endl;
		return 1;
	} else {
		uint32_t* p = RAM + addr;
		*p_val = p[0];
	}

	return 0;
}

bool read_mem_u32(uint32_t *p_val, uint32_t addr){
	
	addr -= ram_start;
	if(addr > RAM_SIZE){
		*p_val = 0;
		std::cout << "illegal read"<<std::endl;
		return 1;
	} else {
		uint32_t* p =  RAM + addr;
		*p_val = p[0];
	}

	return 0;
}

bool write_mem_u8(uint8_t val, uint32_t addr){
	
	addr -= ram_start;
	if(addr > RAM_SIZE){
		std::cout << "illegal write"<<std::endl;
		return 1;
	} else {
		uint32_t* p = RAM + addr;
		p[0] = val & 0xff;
	}

	return 0;
}

bool write_mem_u16(uint16_t val, uint32_t addr){
	
	addr -= ram_start;
	if(addr > RAM_SIZE){
		std::cout << "illegal write"<<std::endl;
		return 1;
	} else {
		uint32_t* p = RAM + addr;
		p[0] = val & 0xffff;
	}

	return 0;
}

bool write_mem_u32(uint32_t val, uint32_t addr){
	
	addr -= ram_start;
	if(addr > RAM_SIZE){
		std::cout << "illegal write"<<std::endl;
		return 1;
	} else {
		uint32_t* p = RAM + addr;
		p[0] = val & 0xffffffff;
	}

	return 0;
}
