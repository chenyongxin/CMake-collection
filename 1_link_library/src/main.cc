#include <stdio.h>
#include <stdlib.h>

#ifdef USE_MYMATH
  #include "mymath.h"
#else
  #include <math.h>
#endif


int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }

    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);

#ifdef USE_MYMATH
    printf("Now we use our own math library. \n");
    double result = power(base, exponent);
#else
    printf("Now we use the standard library. \n");
    double result = pow(base, exponent);
#endif
    
    printf("%g ^ %d is %g\n", base, exponent, result);
    return 0;
}