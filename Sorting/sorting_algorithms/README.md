# DSSC - Algorithmic Design - Sorting Algorithms
This repository contains some code to simplify the implementation and testing of sorting algorithms. The code in this repository natively support insertion sort, quick sort (with and without the select algorithm to identify the pivot), bubble sort, selection sort, and heap sort, but other algorithms can easily be added by editing the main function in the file [main.c](src/main.c).

In order to test the differences in term of execution-time between the sorting algorithms, you need to implement all of them. The insertion sort algorithm must be implemented in the file [insertion_sort.c](src/insertion_sort.c) according to the API defined in [insertion_sort.h](src/insertion_sort.h); the quick sort algorithm in the file [quick_sort.c](src/quick_sort.c) and, so forward, for all the algorithms.


A Makefile can be produced by using [cmake](https://cmake.org/) as follows:
```bash
cmake -G "Unix Makefiles" CMakeLists.txt
```

Afterwards you can compile the code by executing `make`. This produces an executable named `test_sorting` which can be executed in POSIX systems by using the command:
```bash
./test_sorting
Size	Insertion Sort	          	        
    	(Random Case)	(Best Case)	(Worst Case)
2^2		0.000001		0.000000	0.000001
2^3		0.000002		0.000000	0.000003
2^4		0.000006		0.000000	0.000011
2^5		0.000026		0.000000	0.000058
2^6		0.000117		0.000000	0.000246
2^7		0.000506		0.000001	0.000800
2^8		0.001792		0.000003	0.002947
2^9		0.005582		0.000003	0.011522
2^10	0.022768		0.000005	0.045672
2^11	0.090376		0.000015	0.178571
2^12	0.363516		0.000026	0.712619
2^13	1.425219		0.000044	2.850707


Size	Quick Sort	           		Quick Sort + Select
    	(Random Case)	(Worst Case)	(Random Case)	(Worst Case)
2^2		0.000001		0.000001		0.000000		0.000000
2^3		0.000002		0.000002		0.000002		0.000002
2^4		0.000004		0.000007		0.000011		0.000014
2^5		0.000011		0.000017		0.000033		0.000037
2^6		0.000023		0.000047		0.000099		0.000104
2^7		0.000053		0.000127		0.000272		0.000288
2^8		0.000125		0.000358		0.000686		0.000725
2^9		0.000470		0.001096		0.001650		0.001794
2^10	0.000620		0.002806		0.003656		0.004680
2^11	0.001349		0.007792		0.007754		0.009819
2^12	0.002693		0.022005		0.015447		0.022336
2^13	0.005668		0.061430		0.031117		0.050238


Size	Insertion Sort	Quick Sort		Bubble Sort	Selection Sort	Heap Sort
    	(Random Case)	(Random Case)			
2^2		0.000000		0.000001		0.000000	0.000000	0.000001
2^3		0.000001		0.000002		0.000001	0.000002	0.000003
2^4		0.000006		0.000005		0.000007	0.000003	0.000008
2^5		0.000023		0.000010		0.000023	0.000005	0.000015
2^6		0.000089		0.000023		0.000098	0.000014	0.000032
2^7		0.000350		0.000056		0.000397	0.000041	0.000074
2^8		0.001401		0.000128		0.001706	0.000137	0.000169
2^9		0.005577		0.000278		0.007351	0.000489	0.000382
2^10	0.022346		0.000595		0.033005	0.001845	0.000858
2^11	0.088890		0.001347		0.147866	0.007105	0.001889
2^12	0.354780		0.002710		0.640717	0.027877	0.004154
2^13	1.423707		0.005686		2.692697	0.111241	0.009063


Size	Quick Sort		Quick Sort +	Heap Sort
    	          	  		Select
    	(Random Case)		(Random Case)	
2^14	0.012147		0.060542		0.019509
2^15	0.026362		0.116975		0.041897
2^16	0.058330		0.230238		0.089473
2^17	0.144066		0.459159		0.190889
2^18	0.406347		0.886102		0.405276
2^19	1.235783		1.746197		0.876056
2^20	4.262251		3.477124		1.819107
```

The first column in the output report the size of the tested array. The remaining columns in the output report the execution-time in seconds of the implementations of sorting algorithms. Whenever the resulting arrays are not sorted (e.g., due to a bug) the word "KO" follows the execution-time.
In order to better compare quick sort and heap sort on the random cases, a futher set of tests on larger arrays are also performed.
