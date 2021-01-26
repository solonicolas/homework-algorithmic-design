# DSSC - Algorithmic Design - Strassen's Algorithm
This repository contains some code to simplify the implementation and the testing of the Strassen's algorithm for matrix multiplication.

A Makefile can be produced by using [cmake](https://cmake.org/) as follows:
```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```
Afterwards you can compile the code by executing `make`. This produces an executable named `strassen_test` which can be executed in POSIX systems by using the command:
```bash
./strassen_test 
n	    Naive Alg.	Strassen Alg.	Strassen Alg. Imp	Same result
1	    0.000000	0.000001	    0.000003		    1
2	    0.000003	0.000001	    0.000002		    1
4	    0.000005	0.000002	    0.000003		    1
8	    0.000010	0.000006	    0.000007		    1
16	    0.000022	0.000017	    0.000017		    1
32	    0.000087	0.000066	    0.000088		    1
64	    0.000544	0.000414	    0.000327		    1
128	    0.003445	0.002159	    0.001693		    1
256	    0.027273	0.019962	    0.013034		    1
512	    0.225204	0.105758	    0.085014		    1
1024	4.056037	0.710444	    0.555193		    1
2048	73.662586	5.308931	    3.966877		    1
4096	610.764128	37.202009	    28.545225		    1
```

The first column in the output reports the number of the rows and columns in the tested matrixes. 

The second, the third and the fourth columns in the output report the execution-time in seconds of the implementations of the naive algorithm, of the Strassen's algorithm and of the improved Strassen's algorithm, respectively.

Finally, the last column, which is excusively meant to validate the implementations, contains the value 1 if and only if the results are the same.