
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
for(int i = 0 ; i<2 ; i++)
        printf("first string: %c\n",list->string_proper[i]);

/*
printf("\nthese are the list elements:\n ");
while(list){
        printf("%s\n", list->string_proper);
        list++;
}*/
}