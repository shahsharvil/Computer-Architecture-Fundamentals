#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int t = 0, num = 0x99887766;

    // num_byte_addr is an array of unsigned char *, that will be used 
    // to store the addresses of individual bytes in num
    unsigned char *num_byte_addr[sizeof(num)];
 	
    unsigned char *start = (unsigned char *)&num;

    printf("num: 0x%.2x\n\n", num);
    
    // print address and value for each byte of num
    for(t = 0; t < sizeof(num); t++)
    {	
    	num_byte_addr[t] = start;
        printf("Address: %p \t Value: 0x%.2x\n", start, *start);
        start++;
    }

    // make decision about processor endianness
    if(num_byte_addr[0] < num_byte_addr[1] && *num_byte_addr[0] == 0x66)
    {
        printf("\nA Little Endian processor\n");
    }
    else
    {
        printf("\nA Big Endian processor\n");
    }
    
    return 0;
}
