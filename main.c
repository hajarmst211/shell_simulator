
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
        printf("first string: %s\n",list[i].string_proper);

MyToken* tokened = parsed_to_tokenized_string(list);
for(int i = 0 ; i<2 ; i++) {
        printf("Token string : \n%s\nToken Tag : %d\n", tokened[i].value, tokened[i].type);
        printf("----------------------------------------------------\n");
}
/*
printf("\nthese are the list elements:\n ");
while(list){
        printf("%s\n", list->string_proper);
        list++;
}*/
}