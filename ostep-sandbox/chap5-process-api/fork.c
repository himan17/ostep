#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    printf("This is the first program, (pid: %d)\n", getpid());
    
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0){
        printf("Child: (pid: %d)\n", getpid());
    } else {
        printf("Parent of the child: (pid: %d)\n", getpid());
    }
    
    return 0;
}

// Here in this program the output is:
// This is the first program, (pid: 1234)
// Child: (pid: 1235)
// Parent of the child: (pid: 1234)


/*
Note: The output order of the parent and child is non-deterministic.
The OS scheduler determines which process runs first, so the parent
might print before the child or vice versa.

But the thing to note here is:

Child process is created in the same memory space and it is identical to the parent process, it's lifecycle starts beyond the fork() line

So, that was the reason why this single code prints both parent and child
*/