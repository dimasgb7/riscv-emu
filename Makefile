run:
	g++ emuRiscv.cpp -o ./my.out -fpermissive -w -std=c++11 -g -O0
	./my.out

limpa:
	rm ./*.out

