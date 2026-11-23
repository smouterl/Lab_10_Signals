/**
 * File: recv_signal.c
 * Modified by: Logan Smouter
 * 
 * Brief summary of program: Receives an integer with SIGUSR1.
 */

#define _POSIX_C_SOURCE 200809L
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @brief Prints the integer sent with SIGUSR1.
 */
void handle_signal(int signal_number, siginfo_t *info, void *context) {
    (void) signal_number;
    (void) context;
    printf("Received number: %d\n", info->si_value.sival_int);
}

int main(void) {
    struct sigaction action = {0};

    action.sa_sigaction = handle_signal;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);

    if (sigaction(SIGUSR1, &action, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Receiver PID: %ld\n", (long) getpid());

    while (1) {
        pause();
    }
}
