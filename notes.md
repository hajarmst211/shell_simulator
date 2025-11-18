# The star of the show: execvp
### How does it work?
- We use execvp to execute esternal commands. They get executed in another process without the main process terminating 
- The difference between fork() and execvp() is that fork creates an exact copy of the parent process(file descriptors, stack/heap, data, code...) and executes the rest of the code too. While execvp() makes the current process stop and executes the code of another proces, all memory, code, stack and heap are replaced.
- NEvertheless, it is typically used after fork() (remimder: returns 0 if the child was succefully created) so that the child process runs a different program. 

##### Arguments:
- It takes two arguments. `int execvp(const char *file, char *const argv[])`
1. file: The name or path of the program you want to execute. Can be simply the program name ("ls", "htop"...) or a path to an executable file "./myprogram" "/usr/bin"
2. argv: array of strings of the arguments to pass to the program
    - CONDITION: argv must be null terminated to prevent infinite looping; The last element must be always NULL. 
##### Return value:
- If execvp() is successful, it never returns; if it fails, it returns -1

