#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv []){
    int id = fork();
    
    if(id == 0){
        //child process returns value zero
        printf("Jello World from child process with id = %d\n", id);
        printf("child process returns zero value\n");
    } else {
        //parent process returns a non-zero value
        printf("Jello World from parent process with id = %d\n", id);
        printf("parent process returns a non-zero value\n");
    }
    
    return 0;
}