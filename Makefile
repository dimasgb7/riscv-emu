run:
	g++ emuRiscv.c -o ./my.out -fpermissive -w -std=c++11 -g -O0
	./my.out
full: 
	g++ emu8080.c -o ./my.out -fpermissive -w -std=c++11 -g -O0
	./my.out

limpa:
	rm ./*.out

