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
    This illustration is about the OS faking infinite number of resources using virtualization

    To simulate this:

    run:
    ./virtualization_cpu "Hello World" & ./virtualization_cpu "Hello World" & ./virtualization_cpu "Hello World" &

    output:
    OS printing 3 "Hello World" strings every second at the same time -> mimicing like there are 3 cores even if there are'nt
    */

    if (argc != 2) {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];
    while (1) {
        Spin(1);
        printf("%s\n", str);
    }
    return 0;
}

