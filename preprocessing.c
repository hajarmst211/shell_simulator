// preprocessing.c

#include"header.h"

int length_string(char* string){
    int length=0;
    while(*string != '\0'){
        length ++;
        string++;
    }
    return length;
}




char* tokenize_string(char** input, char delimiter){
    if(input == NULL){
        return NULL;
    }

    char* last_ptr = *input;
    char* token = malloc(10);
    int i = 0;

    while(last_ptr[i] != delimiter || last_ptr[i] == '\n'){
        token[i] = last_ptr[i];
        i++;
    }
    token[i] = '\0';
    *input += i;
    return token;
}

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

char* select_args(char* input){
    return tokenize_string(&input,' ');
}
