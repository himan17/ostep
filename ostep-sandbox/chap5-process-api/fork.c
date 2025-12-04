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