/**
 * File: signal_sigaction.c
 * Modified by: Logan Smouter
 * 
 * Brief summary of program: Prints the PID of the process sending SIGUSR1.
 * Send a signal with: kill -SIGUSR1 <PID>
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @brief Prints the PID of the process that sent SIGUSR1.
 */
void handle_signal(int signal_number, siginfo_t *info, void *context) {
    (void) signal_number;
    (void) context;
    printf("Received SIGUSR1 from process %ld\n", (long) info->si_pid);
}

int main(void) {
    struct sigaction action = {0};

    // Request the signal information passed to the handler.
    action.sa_sigaction = handle_signal;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);

    if (sigaction(SIGUSR1, &action, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Wait for signals indefinitely.
    while (1) {
        pause();
    }
}
