// sum_{n=0}^{N} (-1)^n/(2n+1) \simeq pi/4 // funcion1
// 1 - 1/3 + 1/5 - 1/7 + 1/9 + ...
// 1 + 1/5 + 1/9 + ... - (1/3 + 1/7 + 1/11 + ...) = sum 1/(4*n + 1) - sum 1/(4*n+3) // funcion2
// sum 2/((4*n+1)(4*n+3)) // funcion3

#include <iostream> // header para imprimir a pantalla
#include <cmath> // funciones y constantes matematicas, como fabs (valor absoluto) y M_PI (numero pi)

// declaracion de las funciones (no cambiar)
// n es el numero de terminos de la suma.
// tener en cuenta como cambian los limites cuando se usan f2 y f3
float f1(int n);
float f2(int n);
float f3(int n);

int main(int argc, char **argv)
{
  // configurar std::cout para que imprima en notacion cientifica y con 7 cifras decimales (precision de float)
  
  for(int ii = 1; ii <= NMAX ++ii) {
    // Aproximacion de numero pi con cada forma de la suma
    float pi1 = 4*f1(ii);
    float pi2 = 4*f2(ii);
    float pi3 = 4*f3(ii);
    // calcular las diferencias porcentuales
    float delta1 = std::fabs(pi1 - M_PI)/M_PI;
    float delta2 = std::fabs(pi2 - M_PI)/M_PI;
    float delta3 = std::fabs(pi3 - M_PI)/M_PI;
    // imprimir
    std::cout << ii << "\t" << delta1 << "\t" << delta2 << "\t" << delta3 << "\n";
  }
  
  return 0;
}

// ----------- ACA DEBE ESCRIBIR LA IMPLEMENTACION DE LAS FUNCIONES -----------
// TODO implementacion de las funciones
float f1(int n)
{
  // escribir aca la implementacion de la forma original de la suma hasta n terminos
}

float f2(int n)
{
  // escribir aca la implementacion de la segunda forma de la suma hasta n terminos totales
}

float f3(int n)
{
  // escribir aca la implementacion de la tercera forma de la suma hasta n terminos totales
}


