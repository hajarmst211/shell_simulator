//my_tokenizer.c

#include "my_tokenizer.h"
#include "lib/my_string.h"
#include "my_list_string.h"
#include <stdlib.h>
#include <stdio.h>

MyString* parse_string(MyString* string)
{//must free the return 
    MyString* list = malloc(10*sizeof(MyString));
    MyString holder = my_new_string("");
    int length = string->size;
    int list_size = 0;
    const char delimiter = ' ';

    for(int i = 0 ; i < length ; i++){
        char character = string->string_proper[i];
        if(character == delimiter){
            append_string_to_list(list, &holder, &list_size);
            my_destroy_string(&holder);
            holder = my_new_string("");
        }
        else{
            my_append_character(&holder, character);
        }
    }
    append_string_to_list(list, &holder, &list_size);
    return list; 
}

MyToken* make_token(MyString* string, int token_type){
    if(string ==NULL){
        return NULL;
    }
    MyToken* token = malloc(sizeof(MyToken));
    if(!token){
        return NULL;
    }
    token->value = string->string_proper;
    token->type = token_type;
    return token;
}

MyToken* new_token_list(void)
{
    MyToken* list = malloc(10*sizeof(MyToken));
    if(!list){
        return NULL;
    }

    for(int i = 0; i < 10 ; i++){
        list[i].type = -1;
        list[i].value = "";        
    }
    return list;
}  

int append_token_to_list(MyToken* list, MyToken* token, int* list_size)
{
    if(list == NULL) return 1;
    list[*list_size].type = token->type;
    list[*list_size].value = token->value;
    int tmp = *(list_size) + 1;
    *list_size = tmp;

    return 0;
}

MyToken* parsed_to_tokenized_string(MyString* parsed_list)
{
    int i = 0;
    MyString element;
    MyToken* token;
    MyToken* token_list = new_token_list();
    int list_size = 0;

    for(int i = 0 ; i < 10 ; i++){    
        element = parsed_list[i];
        if(i == 0){
            token = make_token(&element , UNIX_COMMAND);
        }
        else {
            token = make_token(&element , ARGUMENT);
        }
        append_token_to_list(token_list,token, &list_size);
    }
    return token_list;
}

MyToken* my_tokenizer(MyString* input_string){
    if(input_string == NULL){
        return NULL;
    }
    MyString* string_list = parse_string(input_string);

    if(string_list == NULL){
        return NULL;
    }

    MyToken* token_list = parsed_to_tokenized_string(string_list);

    free(string_list);

    return token_list;
}
