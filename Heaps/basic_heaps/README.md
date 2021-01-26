# A simple binary heap library (and testing tools)
This project is a template for a simple array-implementation of binary 
heaps in the C-programming language.

This template contains all the code needed to test your implementation of 
binary heaps in both correctness and efficiency terms. 
Your are exclusively required to code the type `binheap_type` 
in the file [binheap.h](include/binheap.h) and all the functions 
dealing it in the file [binheap.c](src/binheap.c). The meaning of the 
function parameters and the semantics of the functions themselves are detailed 
in [binheap.h](include/binheap.h).
Once this has been done, a set of tests can be produced as described below.

You can generate the Makefile by using [cmake](https://cmake.org/) as follows:
```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```
Afterwards you can compile the code by executing `make`. This produces a set 
of programs, named `test_delete_min`, `test_insert`, etc., which can be 
executed in POSIX systems siply by writing `./` and the name of the program 
in the terminal. 
For instance, in order to execute `test_delete_min`, use the following command:
```bash
./test_delete_min
Setting up test sets...done

Build the data structure and keep removing the minimum
n	    On Heaps	On Arrays
0	    0.000042	0.000011
1820	0.164049	0.306677
3640	0.331057	1.233898
5461	0.521760	2.739120
7281	0.755442	4.950361
9102	0.886381	7.785841
10922	1.181291	12.156297
12743	1.461549	15.628335
14563	1.724333	22.234650
16384	1.857339	27.068139
```

## Installing the library

In order to install the library, you can set the install directory `<BINHEAP_INSTALL_DIR>` by executing:
```bash
cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=<BINHEAP_INSTALL_DIR> CMakeLists.txt
```
If you don't do it, the library and its headers will be installed in `/usr/local/`.
After that simply write:
```bash
make install
```
