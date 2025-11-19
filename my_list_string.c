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



int append_string_to_list(MyString* list, const MyString* string_to_append, int *list_size_ptr)
{   int list_size = *list_size_ptr;
    MyString string_copy = my_copy_string(string_to_append);

    list[list_size]=string_copy;
    *list_size_ptr=list_size +1;
    return 0;
}

