FLAGS = -Wall -Wextra -ggdb
run :	
	gcc $(FLAGS) *.c -o main ; ./main

debug : main
	gdb ./main

