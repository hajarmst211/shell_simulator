// preprocessing.c

#include"my_list_string.h"
#include "lib/my_string.h"


MyString* new_string_list(void)
{
    //caller must free
    MyString* list = malloc(10 * sizeof(MyString));
    if(!list){
        return NULL;
    }
    list->string_proper = NULL;
    list->capacity = 0;
    list->size = 0;
    return list;
}

int append_string_to_list(MyString* list, const MyString* string_to_append)
{
    if(string_to_append == NULL || list == NULL){
        return -1;
    }
    if(list->capacity <= string_to_append->size ){
        list =  realloc(list, list->capacity * 2 * sizeof(MyString));
        if(!list){
            return 1;
        }
        list->capacity *= 2;
    }
    while(list){
        list += 1;
    }
    list = (MyString*)string_to_append;
    return 0;
}

int append_literal_to_list(MyString* list, const char* literal_to_append)
{
    MyString string_to_append = my_new_string((char*) literal_to_append);
    return append_string_to_list(list, &string_to_append);
}
