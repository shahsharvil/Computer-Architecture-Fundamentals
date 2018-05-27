The ```Read Time Stamp Counter``` sub-directory contains the following files: 

  1. src.c     (contains the source code for the application)
  2. Makefile  (to make and run the application)
  3. README

#### What is the *Time Stamp Counter(TSC)*?





#### Why should you not use *TSC* in your application?


#### Understanding the underlying assembly code
- When called, the ```read_tsc(void)``` function reads and returns the current 64 bit Time Stamp Counter value.
```
uint64_t read_tsc(void)
{
	uint32_t low, high;					// line 1
	__asm__ volatile("rdtsc" : "=a" (low), "=d" (high));	// line 2
	return (( (uint64_t)a) | ((uint64_t)d) << 32);		// line 3
}
```

- The first line of the function declares two variables ```low``` and ```high``` of type ```uint32_t```. We will use ```low``` to store the low-order 32 bits of TSC value and ```high``` for the high-order 32 bits.

- Line 2 then executes the ```rdtsc``` assembly language instruction. This instruction in turn reads a 64 bit MSR (Machine State Register, that stores the TSC), and loads the low-order 32 bits of this MSR into the EAX register, and the high-order 32 bits into the EDX register. 

- The ```"=a" (low), "=d" (high)```part directs GCC to assign ```low``` to the EAX register and ```high``` to the EDX register. In other words, after the ```rdtsc``` instruction executes, our ```low``` and ```high``` variables will contain their respective 32 bit values.

- Finally, line 3 aggregates the 32 bit ```low``` and ```high``` numbers into a single 64 bit unsigned integer.
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
