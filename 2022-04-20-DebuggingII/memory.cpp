#include <iostream>
#include <cstdlib>

void getmem(double *ptr, int n);

int main(int argc, char **argv)
{
  // declare variables
  const int N = 10000;
  double * array;// = nullptr; // nullptr?
  for (int ii = 0 ; ii < 20; ++ii) {
    getmem(array, N);
  }
  // free memory
  delete [] array; // release memory

  return EXIT_SUCCESS;
}

void getmem(double *ptr, int n)
{
  ptr = new double [n]; // pido memoria
  ptr[0] = ptr[1]*2;
  delete [] ptr;
  ptr = nullptr;
  // no hay delete????
}
