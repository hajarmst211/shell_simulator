//my_list_string.h

#ifndef MY_LIST_STRING
#define MY_LIST_STRING

#include "lib/my_string.h"

MyString* new_string_list(void);

int append_string_to_list(MyString* list, const MyString* string_to_append);

int append_literal_to_list(MyString* list, const char* literal_to_append);

#endif