#include <omp.h>
#include <iostream>
#include <cmath>

void fill(double * array, int size);
double average(double * array, int size);

int main(int argc, char *argv[]) {
  const int N = std::atoi(argv[1]);
  double *a = new double[N];

  fill(a, N);
  std::cout << a[1] << "\n";

  //std::cout << average(a, N) << "\n";

  double suma = 0.0;
#pragma omp parallel for reduction(+:suma)
  for(int i = 0; i < N; i++) {
    suma += a[i];
  }
  std::cout <<  suma/N << "\n";

  delete [] a;
  return 0;
}

void fill(double * array, int size)
{
#pragma omp parallel for
  for(int i = 0; i < size; i++) {
    array[i] = 2*i*std::sin(std::sqrt(i/56.7)) +
      std::cos(std::pow(1.0*i*i, 0.3));
  }
}
double average(double * array, int size)
{
  double suma = 0.0;
#pragma omp parallel for reduction(+:suma)
  for(int i = 0; i < size; i++) {
    suma += array[i];
  }
  return suma/size;
}
