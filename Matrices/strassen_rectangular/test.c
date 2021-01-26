#include <time.h>

double test(void (*f)(float **,
	                  float const *const *const, size_t, size_t,
	                  float const *const *const, size_t, size_t), 
	        float **C, float** A, size_t r1, size_t c1, float **B, size_t r2, size_t c2)
{
  struct timespec requestStart, requestEnd;
  double accum;
  size_t rep = 1;

  clock_gettime(CLOCK_REALTIME, &requestStart);
  for (size_t i = 0; i < rep; ++i) {
    f(C, (float const *const *const)A, r1, c1,
        (float const *const *const)B, r2, c2);
  }

  clock_gettime(CLOCK_REALTIME, &requestEnd);

  accum = (requestEnd.tv_sec - requestStart.tv_sec) +
          (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;
  
  return accum / rep;
}

