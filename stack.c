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
    //int *ptr2;
    //ptr2 = ptr;
    // for(int i = 0; i <20; i++){
    //     if(*ptr2 == 0xf7fcfdb0){
    //         printf("value of i%d\n", i);
    //     } 
    //     ptr2--;
    // }
    printf("Value of signalno: %d\n", signalno);
    printf("Address of signalno: %p\n", ptr);
    int *pc; 
    pc = ptr-0x5B1CDC;
    printf("PC: %p\n", pc);
    //*pc[0] += 0x1;
    //printf("Updated PC: %p\n", pc);
    /* Step 2: Handle segfault and change the stack*/
}

int main(int argc, char *argv[]) {
    
    int r2 = 0;

    /* Step 1: Register signal handler first*/
    signal(SIGSEGV, signal_handle);

    r2 = *( (int *) 0 ); // This will generate segmentation fault

    r2 = r2 + 1 * 30;
    printf("result after handling seg fault %d!\n", r2);

    return 0;
}
