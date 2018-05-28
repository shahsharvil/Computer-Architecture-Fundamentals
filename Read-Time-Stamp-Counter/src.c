#include <stdio.h>
#include <unistd.h>		// sleep()
#include <stdint.h>		// uint32_t, uint64_t

uint64_t read_tsc(void);


/*************************************************************************
Function:    main(void)

Description: TSC read inside a for-loop that calls the read_tsc() function
			 every second, and prints the value to the console.
*************************************************************************/
int main(void)
{	
	uint64_t ts = 0;

	for(int i = 1; i < 11; i++)
	{	
		ts = read_tsc();
		printf("Count: %d \t Ticks: %lu\n", i, ts);
		sleep(1);
	}

	return 0;
}


/*************************************************************************
Function:    read_tsc(void)

Called by:   main()

Description: Reads and returns the current TSC value

Ret type:    unsigned 64 bit integer
*************************************************************************/
uint64_t read_tsc(void)
{
	uint32_t low, high;
	__asm__ volatile("rdtsc" : "=a" (low), "=d" (high));
	return (( (uint64_t)high) | ((uint64_t)high) << 32);
}
