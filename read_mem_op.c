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
