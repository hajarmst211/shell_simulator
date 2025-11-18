


#include "header.h"
#include <stdlib.h>
int main (void) {

    while (1) {
/* The line `Line line = read_line();` is calling a function named `read_line()` to read a line of
input and store it in a variable of type `Line`. The `Line` type likely represents a string or a
line of text in this context. */
        Line line = read_line();
        ListLines line_parsed = parser(line);
        ListTokens tokens = tokenize(line_parsed);
        execute_tokens(tokens);
        // free ur variables
    }
    return EXIT_SUCCESS;
}