//my_tokenizer.c

#include "my_tokenizer.h"
#include "lib/my_string.h"
#include "my_list_string.h"
#include <stdlib.h>
#include <stdio.h>

MyString* parse_string(MyString* string)
{//must free the return 
    if(string == NULL){
        return NULL;
    }

    MyString* list = new_string_list();
    MyString argument = my_new_string("");
    int length = string->size;
    int appending_result;
    const char delimiter = ' ';

    for(int i = 0 ; i < length ; i++){

        if(string->string_proper[i] == delimiter){
            append_string_to_list(list, &argument);
            printf("this is the complete  %s\n", argument.string_proper);
            my_destroy_string(&argument);
            argument = my_new_string("");
        }
        if(string->string_proper[i] == '\n'){
            append_string_to_list(list, &argument);
            printf("last element appended %s\n",argument.string_proper );
            my_destroy_string(&argument);
        }

        else{
            appending_result = my_append_character(&argument, string->string_proper[i]);
        }
    }
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
    MyToken* list = malloc(10* sizeof(MyToken));
    if(!list){
        return NULL;
    }
    list->type = -1;
    list->value = "";
    return list;
}  

int append_token_to_list(MyToken* list, MyToken* token)
{
    if(list == NULL) return 1;
    while(list){
        list++;
    }
    list = token;
    return 0;
}

MyToken* parsed_to_tokenized_string(MyString* string_list)
{
    int i = 0;
    MyString element;
    MyToken* token;
    MyToken* token_list = new_token_list();

    while(string_list){    
        element = string_list[i];
        if(i == 0){
            token = make_token(&element , UNIX_COMMAND);
            append_token_to_list(token_list,token);
        }
        else {
            token = make_token(&element , ARGUMENT);
        }
        i++;
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
