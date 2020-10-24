.PHONY: run clean

mr: main.c aluno.c map.c aluno.h mr.h
	@gcc main.c -Wall -Wextra -pedantic -std=c11 -o mr

run: 
	@valgrind ./mr

clean:
	@rm -f mr
 