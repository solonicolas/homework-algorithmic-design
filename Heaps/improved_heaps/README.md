# An improved binary heap library (and testing tools)
This project is a template for an improved array-implementation of binary 
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
n       On Heaps        On Arrays
0d      0.000055        0.000012
1820d   0.028009        0.373506
3640d   0.052145        1.660037
5461d   0.076623        3.801769
7281d   0.100853        7.049152
9102d   0.125323        10.295607
10922d  0.145485        14.025240
12743d  0.167028        19.100032
14563d  0.187585        26.145751
16384d  0.210796        31.600931
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
