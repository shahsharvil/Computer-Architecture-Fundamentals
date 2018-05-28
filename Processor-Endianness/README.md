#### Processor-Endianness
The ```Processor-Endianness``` sub-directory contains the following files: 

  1. src.c
  2. Makefile
  3. README

#### Endianness of a processor
- When storing multiple bytes, a Big Endian machine stores the byte at the *Big* end first. This byte has the lowest address in memmory.
- The following bytes are then stored in non-increasing order of significance. The *Little* end hence gets stored at the lowest memory address.
-  It should be noted here that *Big* and *Little* ends refer to the position of byte in the word, and not the byte itself.
- For example, suppose we store a short integer variable ```short int num = 0x9988```. In a Big Endian machine, the MSByte ```0x99``` gets stored first at the lowest address, and consequently the LSByte ```0x88``` is stored at a higher address. The storing/reading order is reversed for a Little Endian machine. 

#### Directions to run the application
 1. Download the ```Processor-Endianness``` sub-directory to your computer. Open a new terminal window, and execute the following command.
```
$ svn export https://github.com/shahsharvil/Computer-Architecture-Fundamentals/trunk/Processor-Endianness
```  
2. Make and run the application.
```
$ cd Processor-Endianness
$ make
$ ./main
```
