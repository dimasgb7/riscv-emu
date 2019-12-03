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
