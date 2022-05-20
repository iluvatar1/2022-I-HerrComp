#include <omp.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

void fill(std::vector<double> & array);

int main(int argc, char *argv[])
{
  const int N = std::atoi(argv[1]);
  std::vector<double> data(N);
  std::cout << data.size() << "\n";

  // llenar el arreglo
  fill(data);
  std::cout << data[N/2] << "\n";

  // calcular la suma y el promedio
  //double total = suma(data);
  //std::cout << total/data.size() << "\n";

  return 0;
}

void fill(std::vector<double> & array)
{
  int N = array.size();
#pragma omp parallel
  {
    int thid = omp_get_thread_num();
    int nth = omp_get_num_threads();
    int Nlocal = N/nth;
    int iimin = thid*Nlocal;
    int iimax = iimin + Nlocal;
    for(int ii = iimin; ii < iimax; ii++) {
      array[ii] = 2*ii*std::sin(std::sqrt(ii/56.7)) +
        std::cos(std::pow(ii*ii, 0.3));
    }
  }
}
