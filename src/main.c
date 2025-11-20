
/*
        Line line = read_line();
        ListLines line_parsed = parser(line);
        ListTokens tokens = tokenize(line_parsed);
        execute_tokens(tokens);
*/
#include "./lib/my_string.h"
#include "my_repl.h"
#include "my_tokenizer.h"
#include "my_repl.h"
#include <stdlib.h>
#include<string.h>
#include<stdio.h>

int main()
{
char * user_input;
MyString user_input_string;
MyToken* tokens;
while(1){
        printf(">\n");
        user_input = read_line();
        user_input_string = my_new_string(user_input);

        if(strcmp(user_input,"exit\n") == 0){
                exit(0);
        }
        tokens = my_tokenizer(&user_input_string);
        execute(tokens);

}
free(user_input);
free(tokens);
free(&(user_input_string.string_proper));
return 0;
}