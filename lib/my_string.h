// my_string.h
#ifndef STRING_WRAPPER_H
#define STRING_WRAPPER_H

#include <stdlib.h> // ONLY malloc and realloc and of courssse free

typedef struct MyString
{
    char *string_proper;
    int size;
    int capacity;
} MyString;

int my_calculate_string_length(const char *string);

MyString my_new_string(const char *string);
MyString *my_new_string_reff(const char *literal);

void my_destroy_string(MyString *string);

MyString my_copy_string(const MyString *string_to_copy);
int my_append_literal(MyString *string, char *string_to_append);
int my_append_custom_literal(MyString *string, char *string_to_append, const size_t bytes_to_append);
int my_append_character(MyString *string, char character_to_append);
int my_compare_strings(MyString *string1, const MyString *string2);
int my_compare_literals(const char *literal1, const char *literal2);
int my_append_string(MyString *string, MyString *string_to_append);
int my_insert_char(MyString *string, char character, int index);
int my_replace_char(MyString *string, char old_character, char new_character);
int my_reverse_string(MyString *string);
MyString my_int_to_string(int integer);
char my_int_to_digit_char(int single_number);
int my_find_first_occ_character(MyString *string, char character);
int my_find_first_occ_literal(MyString *string, char *character);
MyString my_slicing(MyString *string, int first_index, int last_index);

int my_is_digit(char character);
int my_is_alphabet(char character);
int my_is_upper_case(char character);
int my_is_lower_case(char character);
char my_to_upper(char c);
char my_to_lower(char c);

int my_make_lowercase(MyString *string);
int my_make_uppercase(MyString *string);
int my_count_character(MyString *string, char character);
MyString my_allocate_custom_size(const size_t size, const size_t capacity);

#endif
