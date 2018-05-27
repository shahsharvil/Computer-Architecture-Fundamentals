The ```Read Time Stamp Counter``` sub-directory contains the following files: 

  1. src.c     (contains the source code for the application)
  2. Makefile  (to make and run the application)
  3. README

#### What is the *Time Stamp Counter(TSC)*?





#### Why should you not use *TSC* in your application?


#### Understanding the underlying assembly code
- When called, the *```read_tsc(void)```* function reads and returns the current 64 bit Time Stamp Counter value.
```
uint64_t read_tsc(void)
{
	uint32_t a, d;
	__asm__ volatile("rdtsc" : "=a" (a), "=d" (d));
	return (( (uint64_t)a) | ((uint64_t)d) << 32);
}
```

- The first line of code declares 2 variables *a* and *d* of type *uint32_t*. We will use *a* to store the low-order 32 bits of TSC value and *b* for the high-order 32 bits. 
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
