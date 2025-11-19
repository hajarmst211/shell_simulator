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
    for ( int i = 0 ; i < 10 ; i ++) {
	    list[i].string_proper = NULL;
	    list[i].capacity = 0;
	    list[i].size = 0;
    }
    return  list;
}

int list_length(MyString* list){
    int length = 0;
    while(list[length].string_proper != NULL){
        length++;
    }
    return length;
}

int append_string_to_list(MyString* list, const MyString* string_to_append)
{
    printf("we are going to append now:\n");
    if(string_to_append == NULL){
        return -1;
    }
    if(list == NULL){
        list = new_string_list();
    }
    int length = list_length(list);
    *(list+length) = my_copy_string(string_to_append);

    //To debug:
    printf("this is the length: %d\n",length);
    printf("The element: %s was copied into this pointer %p\n", string_to_append->string_proper, list+length);

    return 0;
}

int append_literal_to_list(MyString* list, const char* literal_to_append)
{
    MyString string_to_append = my_new_string((char*) literal_to_append);
    return append_string_to_list(list, &string_to_append);
}
