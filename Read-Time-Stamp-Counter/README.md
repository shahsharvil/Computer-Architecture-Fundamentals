#### README
The ```Read-Time-Stamp-Counter``` sub-directory contains the following files: 

  1. src.c
  2. Makefile
  3. README

#### The *Time Stamp Counter (TSC)*
TSC is a special 64 bit register, whose value is incremented every clock cycle. This value can be read using the ```rdtsc``` instruction, which loads the time stamp count into *eax* and *edx* registers.

Since the TSC stores the number of cycles elapsed since reset, its value is always an increasing number until it reaches a maxima. At this point, its value is set again.
#### Why should you not use *```rdtsc```* in your application?
- ```rdtsc``` should not be used for measuring time. The clock frequency can dramatically change in events of Power Saving or CPU Boosting, resulting in surprising ```rdtsc``` behavior. (Inorder to read time, the *syscall* [clock_gettime](https://linux.die.net/man/3/clock_gettime) should be used.)
- In case of [out-of-order-execution](https://en.wikipedia.org/wiki/Out-of-order_execution), the ```rdtsc``` instruction may execute later than expected. Although this problem can be solved using the ```rdtscp``` instruction, its not a good idea in general to rely on these instructions.
- For different cores of a multi-core CPU, the ```rdtsc``` instruction might return different values of TSC, even at the same physical time instant.

#### Understanding the underlying assembly code
- When called, the ```read_tsc(void)``` function reads and returns the current 64 bit Time Stamp Counter value.
```
uint64_t read_tsc(void)
{
	uint32_t low, high;					// line 1
	__asm__ volatile("rdtsc" : "=a" (low), "=d" (high));	// line 2
	return (( (uint64_t)low) | ((uint64_t)high) << 32);	// line 3
}
```

- Line 1 of the function declares two variables ```low``` and ```high``` of type ```uint32_t```. We will use ```low``` to store the low-order 32 bits of TSC, and ```high``` for the high-order 32 bits.

- Line 2 then executes the ```rdtsc``` assembly language instruction. This instruction in turn reads a 64 bit MSR (Machine State Register) that stores the counter value, and loads its low-order 32 bits into the *eax* register, and the high-order 32 bits into the *edx* register. 

- The ```"=a" (low), "=d" (high)``` part directs GCC to assign ```low``` to *eax* register and ```high``` to *edx* register. In other words, after the ```rdtsc``` instruction executes, our ```low``` and ```high``` variables will contain their respective 32 bit values.

- Line 3 finally aggregates the 32 bit ```low``` and ```high``` unsigned integers into a single unsigned 64 bit TSC value.
#### Directions to run the application
 1. Download the ```Read-Time-Stamp-Counter``` sub-directory to your computer. Open a new terminal window, and execute the following command.
```
$ svn export https://github.com/shahsharvil/Computer-Architecture-Fundamentals/trunk/Read-Time-Stamp-Counter
```  
2. Make and run the application.
```
$ cd Read-Time-Stamp-Counter
$ make
$ ./main
```
