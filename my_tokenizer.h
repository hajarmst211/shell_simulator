//my_tokenizer.h
#ifndef MY_TOKENIZER
#define MY_TOKENIZER

#include <stdlib.h>
#include "lib/my_string.h"
#include "lib/my_string.h"
#include "my_list_string.h"
#include <stdlib.h>


typedef enum 
{
    UNIX_COMMAND = 1,
    ARGUMENT =0,
} TOKEN_TYPE;

typedef struct MyToken
{
    TOKEN_TYPE type;
    char* value;
}MyToken;

typedef enum{
    PARSING_ERRORS = 1,


} TOKENIZER_ERRORS;

//my_tokenizer.c

MyString* parse_string(MyString* string);

MyToken* make_token(MyString* string, int token_type);

MyToken* new_token_list(void);

MyToken* new_token_list(void);

int append_token_to_list(MyToken* list, MyToken* token, int* list_size);

MyToken* parsed_to_tokenized_string(MyString* string_list);

MyToken* my_tokenizer(MyString* input_string);


#endif