
#include "my_repl.h"

char* read_line(){
    void* buffer = malloc(ARG_MAX);
    if (!buffer) {
        return NULL;
    }
    ssize_t input = read(0,buffer,ARG_MAX-1);
    if(input <= 0){
        free(buffer);
        return NULL;
    }
    ((char*)buffer)[input] = '\0';
    return (char*)buffer;
}