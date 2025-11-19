// preprocessing.c

#include"my_list_string.h"
#include "lib/my_string.h"
#include<stdio.h>

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
    printf("\n we are going to append now:\n");
    if(string_to_append == NULL){
        return -1;
    }
    MyString* tmp_list = list;
    if(tmp_list->string_proper == NULL)
    {
        tmp_list = string_to_append;
        MyString* next = tmp_list + 1;
        next = NULL;
        printf("this is the end---- the value of the list is: %s \n", tmp_list->string_proper);
        printf("The pointers value is: %p", tmp_list);
        return 0;
    }
    
    while(tmp_list){
        printf("this is what list is pointing to now: %s\n", tmp_list->string_proper);
        printf("The pointers value is: %p", tmp_list);
        tmp_list += 1;
    }
    printf("this is the list after the loop: %s\n", tmp_list->string_proper);
    tmp_list = string_to_append; 
    printf("this is the end---- the value of the list is: %s \n", tmp_list->string_proper);
    printf("The pointers value is: %p", tmp_list);
    return 0;
}

int append_literal_to_list(MyString* list, const char* literal_to_append)
{
    MyString string_to_append = my_new_string((char*) literal_to_append);
    return append_string_to_list(list, &string_to_append);
}
