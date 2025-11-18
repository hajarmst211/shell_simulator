FLAGS = -Wall -Wextra -ggdb
all :	
	gcc $(FLAGS) *.c ./lib/* -o main ; ./main

compile : 
	gcc $(FLAGS) *.c ./lib/* -o main 
debug : main
	gdb ./main

