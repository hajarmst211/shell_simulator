// my_shell.c

#include"header.h"
#include <stdio.h>

int main(){
    int status;
    char* input = NULL;

    while(1){
        input = read_line();
        if(!strcmp(input, "exit"))
            break;
        char* argv = select_args(input);
        printf("Argv : %s\n", argv);
        if(fork() == 0)
            execvp(&argv[0], (char* const*)(argv+1));

        wait(&status);
    }
    free(input);
    return 0;
}

