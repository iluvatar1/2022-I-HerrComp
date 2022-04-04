#include <iostream>
#include <cstdlib>

void getmem(int n);

int main(int argc, char **argv)
{
  // declare variables
  const int N = 10000;
  double * array;
  for (int ii = 0 ; ii < 20; ++ii) {
    getmem(array, N);
  }
  // free memory
  // delete [] array;

  return EXIT_SUCCESS;
}
void getmem(double *ptr, int n)
{
  ptr = new double [n];
  data[0] = data[1]*2;
}
