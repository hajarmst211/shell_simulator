
/*
        Line line = read_line();
        ListLines line_parsed = parser(line);
        ListTokens tokens = tokenize(line_parsed);
        execute_tokens(tokens);
*/
#include "lib/my_string.h"
#include "my_repl.h"
#include "my_tokenizer.h"
#include <stdio.h>


int main(){

char * user_input = read_line();
MyString tmp = my_new_string(user_input);
MyString* list = parse_string(&tmp);
for(int i = 0 ; i < list->size ; i++){
        printf("this is the element: %d of the list %s", i, list->string_proper); 
}
}