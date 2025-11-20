
#include "my_repl.h"
#include "my_tokenizer.h"
#include <sys/types.h>

char* read_line()
{
    void* buffer = malloc(11);
    if (!buffer) {
        return NULL;
    }
    ssize_t input = read(0,buffer,10);
    if(input <= 0){
        free(buffer);
        return NULL;
    }
    ((char*)buffer)[input] = '\0';
    return (char*)buffer;
}

int token_list_size(MyToken* tokens_list)
{
    int list_size = 0;
    for(int i = 0 ; i < 10; i++)
    {   
        if(tokens_list[i].type == -1){
            break;
        }
        list_size ++;
    }
    return list_size;
}

int execute(MyToken* tokens_list)
{
    int list_size = token_list_size(tokens_list);
    char* command = tokens_list[0].value;
    char* arguments[list_size-1];

    for(int i = 0; i < list_size-1 ; i++){
        arguments[i] = tokens_list[list_size +1].value;
    }
    pid_t pid = fork();

    if(pid == 0){
        execvp(command, arguments);
    }
    else{
        wait(&pid);
    }
    return 0;
}
