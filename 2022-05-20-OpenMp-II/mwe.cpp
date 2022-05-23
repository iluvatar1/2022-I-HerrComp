#include <omp.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

void fill(double * array, int size);
double suma(const double * array, int size);

int main(int argc, char *argv[])
{
  const int N = std::atoi(argv[1]);
  double * data = new double [N];

  fill(data, N);
  std::cout << data[0] << "\n";

  double total = suma(data, N);
  std::cout << total/N << "\n";

  delete [] data;

  return 0;
}

void fill(double * array, int size)
{
#pragma omp parallel for
  for(int ii = 0; ii < size; ii++) {
      array[ii] = 2*ii*std::sin(std::sqrt(ii/56.7)) +
        std::cos(std::pow(1.2*ii, 0.3));
  }
}

double suma(const double * array, int size)
{
  double val = 0.0;
#pragma omp parallel for reduction(+:val)
  for(int ii = 0; ii < size; ii++) {
    val += array[ii];
  }
  return val;
}
