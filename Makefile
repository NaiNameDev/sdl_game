

a.elf: main.cpp
	g++ main.cpp -o a.elf -lSDL2 -lSDL2_image -std=c++20

.PHONY = ct c

ct: a.elf
	./a.elf
	rm a.elf

c:
	rm a.elf	
