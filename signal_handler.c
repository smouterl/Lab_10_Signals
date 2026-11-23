/**
 * @file signal_handler.c
 * @brief Handles SIGINT and continues running after the handler returns.
 */

/**
 * Modified by: Logan Smouter
 * 
 * Brief summary of modifications: Removed the exit from the signal handler.
 */


#include <signal.h>
#include <unistd.h>
#include <stdio.h>

/**
 * @brief Prints a message when SIGINT is received and returns.
 */
void handle_signal(int signal_number) {
    (void) signal_number; 
    printf("Received a signal\n");
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Continue running after the signal handler returns
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}
