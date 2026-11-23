/**
 * File: signal_alarm.c
 * Modified by: Logan Smouter
 * 
 * Brief summary of program: Receives an alarm signal after five seconds.
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t alarm_received = 0;


void handle_alarm(int signal_number) {
    (void) signal_number;
    printf("Received SIGALRM\n");
    alarm_received = 1;
}

int main(void) {
    // Register the handler and schedule an alarm for five seconds from now.
    signal(SIGALRM, handle_alarm);
    alarm(5);

    // Wait for the alarm before exiting.
    while (!alarm_received) {
        sleep(1);
    }

    return 0;
}
