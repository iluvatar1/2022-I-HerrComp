#include <cstdio> // printf
#include <omp.h>

int main(void)
{
  double x = 9.0;

  int nth = omp_get_num_threads();
  int thid = omp_get_thread_num();
  std::printf("Hello world from thid: %d, out of %d .\n",
              thid, nth);

//#pragma omp parallel num_threads(4)
#pragma omp parallel private(nth, thid)
  {// se generan los threads
    nth = omp_get_num_threads(); // al declarar aca, son privados
    thid = omp_get_thread_num();
    std::printf("Hello world from thid: %d, out of %d .\n",
                thid, nth);
  } // mueren los threads

  std::printf("Hello world from thid: %d, out of %d .\n",
              thid, nth);


  return 0;
}
