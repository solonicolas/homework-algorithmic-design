# DSSC - Algorithmic Design - Strassen's Algorithm
This repository contains some code to simplify the implementation and the testing of the Strassen's algorithm for `rectangular` matrix multiplication.

A Makefile can be produced by using [cmake](https://cmake.org/) as follows:
```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```
Afterwards you can compile the code by executing `make`. This produces an executable named `strassen_test` which can be executed in POSIX systems by using the command:
```bash
./strassen_test 
n			            Strassen Alg.	Naive Alg.	Same result
1024,1024*1024,1024	    0.734892	    4.727572	1
1000,1000*1000,1000	    1.004899	    2.924647	1
1100,2200*2200,1100	    10.291401	    11.567308	1
2000,1000*1000,1000	    2.971720	    7.338923	1
1000,2200*2200,1000	    1.965332	    12.616384	1
2200,1000*1000,2200	    6.412353	    8.736087	1
2000,1000*1000,1900	    3.129678	    5.758504	1
```

The first column in the output reports the sizes of the tested matrixes. 

The second and the third columns in the output report the execution-time in seconds of the implementations of the naive algorithm and of the Strassen's algorith, respectively.

Finally, the last column, which is excusively meant to validate the implementations, contains the value 1 if and only if the results are the same.