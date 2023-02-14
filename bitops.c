/*
* Scott Skibin (ss3793)
* Kevin Schwarz (kjs309)
* ilab2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_TOP_BITS 4 //top bits to extract
#define BITMAP_SIZE 4 //size of the bitmap array
#define SET_BIT_INDEX 17 //bit index to set 
#define GET_BIT_INDEX 17 //bit index to read

static unsigned int myaddress = 4026544704;   // Binary  would be 11110000000000000011001001000000

/* 
 * Function 1: EXTRACTING OUTER (TOP-ORDER) BITS
 */
static unsigned int get_top_bits(unsigned int value,  int num_bits)
{
    unsigned int bit_size = 8*sizeof(value);
	unsigned int shift = bit_size - num_bits;
    unsigned int top_bits = value >> shift;
    return top_bits;
}

/* 
 * Function 2: SETTING A BIT AT AN INDEX 
 * Function to set a bit at "index" bitmap
 */
static void set_bit_at_index(char *bitmap, int index)
{
    int n = BITMAP_SIZE * 8;
    if(index > n-1 || index < 0){
        printf("ERROR: index out of scope of bitmap.\n");
    }
    else{
        int byte = index / 8;
        int i = 7 - (index - (byte*8));
        bitmap[byte] |= (1 << i);
    }
    return;
}


/* 
 * Function 3: GETTING A BIT AT AN INDEX 
 * Function to get a bit at "index"
 */
static int get_bit_at_index(char *bitmap, int index)
{
    int n = BITMAP_SIZE * 8;
    if(index > n-1 || index < 0){
        printf("ERROR: index out of scope of bitmap.\n");
        return -1;
    }
    else{
        int byte = index / 8;
        int i = 7 - (index - (byte*8));
        return (bitmap[byte] & (1 << i)) != 0; 
    }
}


int main () {

    /* 
     * Function 1: Finding value of top order (outer) bits Now let’s say we
     * need to extract just the top (outer) 4 bits (1111), which is decimal 15  
    */
    unsigned int outer_bits_value = get_top_bits (myaddress , NUM_TOP_BITS);
    printf("Function 1: Outer bits value %u \n", outer_bits_value); 
    printf("\n");

    /* 
     * Function 2 and 3: Checking if a bit is set or not
     */
    char *bitmap = (char *)malloc(BITMAP_SIZE);  //We can store 32 bits (4*8-bit per character)
    memset(bitmap,0, BITMAP_SIZE); //clear everything
    
    /* 
     * Let's try to set the bit 
     */
    set_bit_at_index(bitmap, SET_BIT_INDEX);
    
    /* 
     * Let's try to read bit)
     */
    printf("Function 3: The value at %dth location %d\n", 
            GET_BIT_INDEX, get_bit_at_index(bitmap, GET_BIT_INDEX));
    
    free(bitmap);
            
    return 0;
}
