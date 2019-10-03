//BIG FUNCTION FILE
void run_diassembler(uint32_t range);
void diassembler(uint32_t *rom_mem, int pc);
void FetchData(char *file_name, uint16_t *mem_position, int offset);
void PrintMem(uint32_t *my_mem);

void PrintMem(uint32_t *my_mem) 
{
	int count = 0;
	//Print whole Memory 
	std::cout <<  "Printing Whole Memory Allocated:";	
	for(int i=0; i < 0x800  + 0x800 + 0x800 + 0x800 ; i++ ) 
	{	
		if (count % 16 == 0){
		       	std::cout << std::endl;
		        count = 0;
		} 	
		std::cout << std::hex << my_mem[i] <<" ";
    	 	count = count + 1;
	}	
	std::cout << std::endl;	
}
void FetchData(char *file_name, uint32_t *mem_add, int offset)
{
	//Open Rom file and fetch its data
	FILE *f = fopen(file_name,"rb");
	if(f == NULL) std::cout << "error";
       	
	fseek(f, 0L, SEEK_END);	
	int fsize = ftell(f);
	fseek(f, 0L, SEEK_SET);

	//Set a pointer buffer to our main memory address
	uint32_t *buffer = &mem_add[offset];
	
	//Variable to fetch strings from file
	unsigned char *foo;
	foo = malloc(0x10000);

	//Use This in case of binary Data
		//fread(buffer, 1 , fsize , f);
	

	//Create a String stream and throw hex strings on it
	std::stringstream ss;
	while(fgets(foo,fsize, f) ) {
	//std::cout <<"foo:"<< foo << std::endl;
	ss << std::hex << foo;
	};

	//Fetch the Hex values from the Stream to our main memory
	for(int i=0; i < 0x800 ; i++ ) ss >> buffer[i];

	fclose(f);

}

void run_diassembler(uint32_t range, uint32_t* my_mem){
	
	std::cout << "Instructions from ROM file : " << std::endl;
	
	int pc = 0;
	do{	
	diassembler(my_mem,pc);
	pc += 1;
	} while (pc != range );

}
void diassembler(uint32_t *rom_mem, int pc)
{

	uint32_t *inst = &rom_mem[pc];
	//std::cout <<std::hex<< *inst << " ";
	std::cout << std::hex << std::setfill('0') << std::setw(3) << pc << " ";

	switch(*inst){

	       //Control	
		case 0x00: std::cout << "NOP" <<std::endl; break;
		case 0xFB: std::cout << "EI" <<std::endl;  break;
		case 0xF3: std::cout << "DI" <<std::endl;  break;
		case 0x76: std::cout << "HLT" <<std::endl; break;

		//Move, Load and Store
		case 0x40: std::cout << "MOV 	B,B" <<std::endl; break;
		case 0x41: std::cout << "MOV 	B,C" <<std::endl; break;
		case 0x42: std::cout << "MOV 	B,D" <<std::endl; break;
		case 0x43: std::cout << "MOV 	B,E" <<std::endl; break;
		case 0x44: std::cout << "MOV 	B,H" <<std::endl; break;
		case 0x45: std::cout << "MOV 	B,L" <<std::endl; break;
		case 0x46: std::cout << "MOV 	B,Memory" <<std::endl; break;
		case 0x47: std::cout << "MOV 	B,A" <<std::endl; break;
		
		default: std::cout<< "OP CODE NOT IMPLEMENTED YET!"<<std::endl;
	};	
 	
	std::cout << std::endl;
}



