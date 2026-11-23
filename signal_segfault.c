/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Logan Smouter
 * 
 * Brief summary of modifications: Added a handler for SIGSEGV.
 */


#include <stdio.h>
#include <signal.h>

/**
 * @brief Reports a segmentation fault and returns.
 */
void handle_segfault(int signal_number) {
    (void) signal_number;
    printf("Received a segmentation fault\n");
}

int main (int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    // Register a handler for segmentation faults
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}
