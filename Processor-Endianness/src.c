#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int t = 0;
    int num = 0x99874568;
    // big end is the byte that contains 0x99
    // big end refers to the position in the word, not the value of the byte

    //big endian byte order: MSB placed at the byte with lowest address

    unsigned char *start = (unsigned char *)&num;

    for(t = 0; t < sizeof(num); t++)
    {
        printf("Address: %p Value: %.2x\n", start, *start);
        start++;
    }

    return 0;
}
