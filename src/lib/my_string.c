// my_string.c
#include "my_string.h"
#include <stdlib.h>
int my_calculate_string_length(const char *string)
{
    if (string == NULL)
    {
        return 0;
    }
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}

MyString my_new_string(const char *literal)
{
    int length = my_calculate_string_length(literal);
    MyString new_string;
    new_string.size = length;
    new_string.capacity = 2 * new_string.size + 1;
    new_string.string_proper = (char *)malloc(sizeof(char) * new_string.capacity);
    if (new_string.string_proper == NULL)
    {
        new_string.size = 0;
        new_string.capacity = 0;
        return new_string;
    }
    for (int i = 0; i < new_string.size; i++)
    {
        new_string.string_proper[i] = literal[i];
    }
    new_string.string_proper[new_string.size] = '\0';
    return new_string;
}
MyString *my_new_string_reff(const char *literal)
{
    MyString *new_string = malloc(sizeof(MyString));
    int length = my_calculate_string_length(literal);
    new_string->size = length;
    new_string->capacity = 2 * new_string->size + 1;
    new_string->string_proper = (char *)malloc(sizeof(char) * new_string->capacity);
    if (new_string->string_proper == NULL)
    {
        new_string->size = 0;
        new_string->capacity = 0;
        return new_string;
    }
    for (int i = 0; i < new_string->size; i++)
    {
        new_string->string_proper[i] = literal[i];
    }
    new_string->string_proper[new_string->size] = '\0';
    return new_string;
}

void my_destroy_string(MyString *string)
{
    if (string == NULL)
    {
        return;
    }
    free(string->string_proper);
    string->capacity = 0;
    string->size = 0;
}

MyString my_copy_string(const MyString *string_to_copy)
{
    if (string_to_copy == NULL || string_to_copy->string_proper == NULL)
    {
        return my_new_string("");
    }
    MyString copied_string;
    copied_string.capacity = string_to_copy->capacity;
    copied_string.size = string_to_copy->size;
    copied_string.string_proper = (char *)malloc(sizeof(char) * copied_string.capacity);
    if (copied_string.string_proper == NULL)
    {
        copied_string.size = 0;
        copied_string.capacity = 0;
        return copied_string;
    }
    for (int i = 0; i < copied_string.size; i++)
    {
        copied_string.string_proper[i] = string_to_copy->string_proper[i];
    }
    copied_string.string_proper[copied_string.size] = '\0';
    return copied_string;
}

int my_append_literal(MyString *string, char *string_to_append)
{
    if (string == NULL || string_to_append == NULL)
    {
        return 1;
    }
    int string_to_append_size = my_calculate_string_length(string_to_append);
    int new_size = string_to_append_size + string->size;
    int old_size = string->size;
    if (new_size >= string->capacity)
    {
        string->capacity = new_size * 2;
        char *new_buffer = (char *)realloc(string->string_proper, string->capacity);
        if (new_buffer == NULL)
        {
            return 1;
        }
        string->size = new_size;
        string->string_proper = new_buffer;
    }
    for (int i = 0; i < string_to_append_size; i++)
    {
        string->string_proper[old_size + i] = string_to_append[i];
    }
    string->size = new_size;
    string->string_proper[string->size] = '\0';
    return 0;
}
int my_append_custom_literal(MyString *string, char *string_to_append, const size_t bytes_to_append)
{
    if (string == NULL || string_to_append == NULL)
    {
        return 1;
    }

    int new_size = string->size + bytes_to_append;
    int old_size = string->size;

    if (new_size >= string->capacity)
    {
        string->capacity = new_size * 2;
        char *new_buffer = (char *)realloc(string->string_proper, string->capacity);
        if (new_buffer == NULL)
        {
            return 1;
        }
        string->string_proper = new_buffer;
    }

    for (size_t i = 0; i < bytes_to_append; i++)
    {
        string->string_proper[old_size + i] = string_to_append[i];
    }

    string->size = new_size;
    string->string_proper[string->size] = '\0';

    return 0;
}
int my_append_character(MyString *string, char character_to_append)
{
    if (string == NULL)
        return 1;

    if (string->size + 1 >= string->capacity)
    {
        string->capacity = (string->size + 1) * 2;
        char *new_buffer = (char *)realloc(string->string_proper, string->capacity);
        if (new_buffer == NULL)
            return 1;
        string->string_proper = new_buffer;
    }

    string->string_proper[string->size] = character_to_append;
    string->size++;
    string->string_proper[string->size] = '\0';

    return 0;
}

int my_compare_strings(MyString *string1, const MyString *string2)
// 1 : string1 = string2
{
    if (string1 == NULL || string2 == NULL || string1->string_proper == NULL || string2->string_proper == NULL)
    {
        return 0;
    }
    if (string1->size != string2->size)
    {
        return 0;
    }
    for (int i = 0; i < string1->size; i++)
    {
        if (string1->string_proper[i] != string2->string_proper[i])
        {
            return 0;
        }
    }
    return 1;
}

int my_append_string(MyString *string, MyString *string_to_append)
{
    if (string_to_append == NULL)
    {
        return 1;
    }
    return my_append_literal(string, string_to_append->string_proper);
}

int my_insert_char(MyString *string, char character, int index)
{
    if (string == NULL)
    {
        return 1;
    }
    if (index < 0 || index > string->size)
    {
        return 1;
    }
    if (string->capacity == 0)
    {
        char s_character[2];
        s_character[0] = character;
        s_character[1] = '\0';
        my_append_literal(string, s_character);
        return 0;
    }
    if (string->size + 1 >= string->capacity)
    {
        string->capacity *= 2;
        char *new_buffer = (char *)realloc(string->string_proper, string->capacity);
        if (new_buffer == NULL)
        {
            return 1;
        }
        string->string_proper = new_buffer;
    }
    if (string->string_proper == NULL)
    {
        return 1;
    }
    for (int i = string->size; i > index; i--)
    {
        string->string_proper[i] = string->string_proper[i - 1];
    }
    string->string_proper[index] = character;
    string->size++;
    string->string_proper[string->size] = '\0';
    return 0;
}

int my_replace_char(MyString *string, char old_character, char new_character)
{
    if (string == NULL || string->string_proper == NULL)
    {
        return 1;
    }
    for (int i = 0; i < string->size; i++)
    {
        if (string->string_proper[i] == old_character)
        {
            string->string_proper[i] = new_character;
        }
    }
    return 0;
}

int my_reverse_string(MyString *string)
{
    if (string == NULL)
    {
        return 1;
    }
    if (string->string_proper == NULL)
    {
        return 1;
    }

    for (int i = 0; i < string->size / 2; i++)
    {
        char temp = string->string_proper[i];
        string->string_proper[i] = string->string_proper[string->size - 1 - i];
        string->string_proper[string->size - 1 - i] = temp;
    }
    return 0;
}

char my_int_to_digit_char(int single_number)
{
    return single_number + '0';
}

MyString my_int_to_string(int integer)
{
    if (integer == 0)
    {
        return my_new_string("0");
    }
    MyString output = my_new_string("");
    int new_integer = abs(integer);
    char string_remainder = 0;
    char holder[2];
    while (new_integer != 0)
    {

        int remainder = new_integer % 10;
        string_remainder = my_int_to_digit_char(remainder);
        holder[0] = string_remainder;
        holder[1] = '\0';

        my_append_literal(&output, holder);
        new_integer = (new_integer - remainder) / 10;
    }
    if (integer < 0)
    {

        holder[0] = '-';
        my_append_literal(&output, holder);
    }

    my_reverse_string(&output);
    return output;
}

int my_find_first_occ_character(MyString *string, char character)
{
    if (string == NULL || string->string_proper == NULL)
    {
        return -1;
    }
    for (int i = 0; i < string->size; i++)
    {
        if (string->string_proper[i] == character)
        {
            return i;
        }
    }
    return -1;
}

int my_find_first_occ_literal(MyString *string, char *character)
{
    if (string == NULL || string->string_proper == NULL || character == NULL)
    {
        return -1;
    }
    int string_length = string->size;
    int character_length = my_calculate_string_length(character);
    int character_index;
    for (int string_index = 0; string_index <= string_length - character_length; string_index++)
    // we dont need to check the last character_length characters of the text
    {
        character_index = 0;
        while (character_index < character_length &&
               string->string_proper[character_index + string_index] == character[character_index])
        {
            character_index++;
        }
        if (character_index == character_length)
        {
            return string_index;
        }
    }
    return -1;
}

MyString my_slicing(MyString *string, int first_index, int last_index)
{
    if (string == NULL || string->string_proper == NULL)
    {
        return my_new_string("");
    }
    int range = last_index - first_index;
    if (range <= 0 || last_index > string->size || first_index < 0)
    {
        return my_new_string("");
    }
    MyString slice;
    slice.size = range;
    slice.capacity = range * 2 + 1;
    slice.string_proper = malloc(slice.capacity);
    if (slice.string_proper == NULL)
    {
        slice.size = 0;
        slice.capacity = 0;
        return slice;
    }
    for (int i = 0; i < range; i++)
    {
        slice.string_proper[i] = string->string_proper[i + first_index];
    }
    slice.string_proper[range] = '\0';
    return slice;
}

int my_is_digit(char character)
{
    return (character >= '0' && character <= '9');
}
int my_is_alphabet(char character)
{
    return ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z'));
}
int my_is_upper_case(char character)
{
    return (character >= 'A' && character <= 'Z');
}
int my_is_lower_case(char character)
{
    return (character >= 'a' && character <= 'z');
}

char my_to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - ('a' - 'A'); // or c - 32
    }
    return c;
}

char my_to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + ('a' - 'A'); // or c + 32
    }
    return c;
}

int my_make_uppercase(MyString *string)
{
    if (string == NULL || string->string_proper == NULL)
    {
        return 1;
    }
    if (string->size == 0)
        return 1;

    for (int i = 0; i < string->size; i++)
    {
        char ch = string->string_proper[i];
        if (my_is_lower_case(ch))
        {
            string->string_proper[i] = my_to_upper(ch);
        }
    }

    return 0;
}
int my_make_lowercase(MyString *string)
{
    if (string == NULL || string->string_proper == NULL)
    {
        return 1;
    }
    if (string->size == 0)
        return 1;

    for (int i = 0; i < string->size; i++)
    {
        char ch = string->string_proper[i];
        if (my_is_upper_case(ch))
        {
            string->string_proper[i] = my_to_lower(ch);
        }
    }

    return 0;
}

int my_character_to_int(char character)
{
    if (character >= '0' && character <= '9')
    {
        return character - '0';
    }
    else
    {
        return -1;
    }
}

int my_count_character(MyString *string, char character)
{
    if (string == NULL || string->string_proper == NULL)
    {
        return 0;
    }
    int counter = 0;
    for (int i = 0; i < string->size; i++)
    {
        if (string->string_proper[i] == character)
        {
            counter++;
        }
    }
    return counter;
}
int my_compare_literals(const char *literal1, const char *literal2)
{ // Yeah i will use the object I am that insane >:)
    MyString string1 = my_new_string(literal1);
    MyString string2 = my_new_string(literal2);
    int result = my_compare_strings(&string1, &string2);
    my_destroy_string(&string1);
    my_destroy_string(&string2);
    return result;
}
MyString my_allocate_custom_size(const size_t size, const size_t capacity)
{
    MyString output;
    if (capacity < size)
    {
        output.size = 0;
        output.capacity = 0;
        output.string_proper = NULL;
        return output;
    }
    output.size = size;
    output.capacity = capacity;
    output.string_proper = malloc(capacity);
    if (!output.string_proper)
    {
        output.size = 0;
        output.capacity = 0;
        output.string_proper = NULL;
        return output;
    }
    return output;
}
