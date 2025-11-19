#ifndef MY_REPL
#define MY_REPL

#include"my_tokenizer.h"
#include <sys/wait.h>
#include <unistd.h>


char* read_line();

int execute(MyToken* tokens_list);

int token_list_size(MyToken* tokens_list);

#endif