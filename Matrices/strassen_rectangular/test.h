#ifndef __TEST__


double test(void (*f)(float **,
	                  float const *const *const, size_t, size_t,
	                  float const *const *const, size_t, size_t), 
	        float **C, float** A, size_t r1, size_t c1, float **B, size_t r2, size_t c2);

#endif // __TEST__
