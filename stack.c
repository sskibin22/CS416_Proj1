/*
* Scott Skibin (ss3793)
* Kevin Schwarz (kjs309)
* ilab2
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/* Part 1 - Step 1 and 2: Do your tricks here
 * Your goal must be to change the stack frame of caller (main function)
 * such that you get to the line after "r2 = *( (int *) 0 )"
 */
void signal_handle(int signalno) {
    
    printf("handling segmentation fault!\n");
    int *ptr;
    ptr = &signalno;
    printf("Value of signalno: %d\n", signalno);
    printf("Address of signalno: %p\n", ptr);
    
    /* Step 2: Handle segfault and change the stack*/
    int *pc; 
    pc = ptr-0x4B771C; //signalno ptr - (offset between signalnoptr and saved return address)
    printf("PC: %p\n", pc);
    printf("Address of PC: %p\n", &pc);
    *pc = *pc+135; 
    printf("Updated PC: %p\n", pc);
}

int main(int argc, char *argv[]) {
    /* Step 1: Register signal handler first*/
    signal(SIGSEGV, signal_handle);

    int r2 = 0;

    r2 = *( (int *) 0 ); // This will generate segmentation fault

    r2 = r2 + 1 * 30;
    printf("result after handling seg fault %d!\n", r2);

    return 0;
}
