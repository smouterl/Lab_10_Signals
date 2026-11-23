/**
 * File: send_signal.c
 * Modified by: Logan Smouter
 * 
 * Brief summary of program: Sends a random integer with SIGUSR1.
 */

#define _POSIX_C_SOURCE 200809L
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <receiver PID>\n", argv[0]);
        return 1;
    }

    int receiver_pid = atoi(argv[1]);
    if (receiver_pid <= 0) {
        fprintf(stderr, "Enter a positive receiver PID.\n");
        return 1;
    }

    srand((unsigned int) time(NULL));
    union sigval value;
    value.sival_int = rand();
    printf("Sending number: %d\n", value.sival_int);

    if (sigqueue(receiver_pid, SIGUSR1, value) == -1) {
        perror("sigqueue");
        return 1;
    }

    return 0;
}
