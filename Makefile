

a.elf: main.cpp
	g++ main.cpp -o a.elf -lSDL2 -std=c++20

.PHONY = ct c

ct: a.elf
	./a.elf
	rm a.elf

c:
	rm a.elf	
