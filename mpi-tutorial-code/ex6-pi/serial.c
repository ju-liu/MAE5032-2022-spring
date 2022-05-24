#include <stdio.h>

int main(int argc, char **argv)
{
  long nsteps = 1000000000;
  double sum  = 0.0;
  
  for(long ii=0; ii<nsteps; ++ii)
    sum += (1.0 - 2.0 *(ii%2)) / (2.0 * ii + 1.0);

  printf("pi is %.12g \n", sum * 4.0);

  return 0;
}

// EOF
