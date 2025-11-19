#  Informations about the project:
1. Name of the project: mini shell
2. Coding language of the project: c
4. Motivation of the project: Learning and skill developpement purposes
3. Goal of the project: This project aims to mimic the behavoir of a real unix shell. 
4. Limitations of the project: To begin with, this project is only supported on linux working machines. Secondly, the shell it provides can only run `execvp` supported commands or any executable file name reachable via a provided path as first argument.

# Detailed description of the project:
### Used commands and libraries:
The project is built over a customized, from scratch string library that groups all teh needed functions to manipulate string type variable. In this fucntion a string is refered to as a `MyString` object and has three atributts: string_propre which is its `char* `value, a size which is the length of the string and a capacity which translates the whole allocated space for that string. <br><p> In addition to some POSIX/UNIX commands such as `execvp`, `fork` and `read`. And of course the standard `stdlib` library for memory allocation managment.
### Conduction of the project: 
 This project is based on a **repl** algorithm. Which means that it has four main stages: read , evaluate, print and loop. 
<br><p> The **repl** layout of the project is the following:
1. **Read:** The reading part concerns the users's input. In other words, the reading process happens when the program scans the user's inputs  through the keyboard. For reading, the code relies on the system call `read` using the standard input.
2. **Evaluate:**Initially, the unix command and its argument are passed on a single string. The evaluation covers all the treatment done on that user's input string. First of all, the input is parsed using the `parse_string` function that returns a parsed string which is then going to be tokenized using the `parsed_to_tokenized_string` function. The tokenizer is responsible for affecting and separating the unix command from its argument.
3.**Print:** Printing is about returning the output value to the user in the console. 
4.**Loop:** Looping through these steps is necessary since it is what a consol does: takes a command, execute it and returns the output. Thus the treatment is infinitely repeated until the user enters `exit` which is the keyword responsible for exiting my `mini_shell`.

# Preview of the mini shell
![image](demonstration/demonstration1.png)

# Project using instructions:
- Before using this project, one must make sure he has a unix based operating system and `gcc` installed.
- The first step is to clone this repository into your local machine and let's begin:
1. Navigating the project: enter the `src` folder.<br>
`cd src`
2. To compile the program:
<br>`make compile`
3. To compile and run the program:
<br>`make all`
4. To debug the code using gdb:
<br>`make debug`