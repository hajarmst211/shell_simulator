FLAGS = -Wall -Wextra -ggdb
SRC = src

all :	
	gcc $(FLAGS) $(SRC)/*.c $(SRC)/lib/* -o main ; ./main

compile : 
	gcc $(FLAGS) $(SRC)/*.c $(SRC)/lib/* -o main 
debug : main
	gdb ./main

