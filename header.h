#ifndef HEADER
#define HEADER

#include<unistd.h>
#include <sys/wait.h>
#include <linux/limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


char* read_line();

char* select_args(char* input);

char* tokenize_string(char** input, char delimiter);

#endif