#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void Spin(int seconds) {
    struct timeval start, now;
    gettimeofday(&start, NULL);
    do {
        gettimeofday(&now, NULL);
        double elapsed = (now.tv_sec - start.tv_sec) + 
                         (now.tv_usec - start.tv_usec) / 1000000.0;
        if (elapsed >= seconds)
            return;
        // maybe do a small busy-loop / nothing
    } while (1);
}

int main(int argc, char *argv[])
{
    /*
    This illustration is about OS creating virtual memory for each process

    To simulate this:

    run:
    ./virtualization_memory & ./virtualization_memory & ./virtualization_memory &

    output:
    OS creating virtual memory for each process -> each process address is same but OS is using differnet physical memory

    Modern OS has ASLR (Address Space Layout Randomization) to prevent stack buffer overflow attacks(an attack where attacker knows exactly what address a program is using for buffer(input) and injects malicious code that overflows the buffer and return address RET is changed to start of the buffer), it randomizes the address space layout of each process -> the address is no longer fixed, it is randomized each time the program is run

    To test this program, you need to turn off ASLR
    */
    int *p = malloc(sizeof(int));

    printf("PID: %d, Address: %08x\n", getpid(), (unsigned)p);

    *p = 0;

    while(1){
        Spin(1);
        *p = *p + 1;

        printf("PID: %d, Value: %d\n", getpid(), *p);
    }
    return 0;
}

