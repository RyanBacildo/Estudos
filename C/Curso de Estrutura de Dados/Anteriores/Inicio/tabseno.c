#include <stdio.h>

long int fatorial(int n) {
  long int fat = 1;
  for (int i = 1; i <= n; i++) {
    fat = fat * i;
  }
  return fat;
}

long double potencia(double b, int e) {
  long double pot = b;

  for (int i = 2; i <= e; i++) {
    pot = pot * b;
  }
  return pot;
}

float rad(double graus) { return (3.14 * graus) / 180.0; }

long double seno(long double angulo) {
  double A = rad(angulo);
  int sinal = -1;
  int num_fra = 3;
  int expoente = 3;
  long double val_seno = A;
  long double fracao;

  for (int i = 1; i <= num_fra; i++) {
    fracao = potencia(A, expoente) / fatorial(expoente);
    val_seno = val_seno + fracao;
    expoente = expoente + 2;
    sinal = sinal * -1;
  }
  return val_seno;
}

int main() {
  long double angulo;
  puts("Digite o valor do ângulo:");
  scanf("%lf", &angulo);
  printf("%lf\n", seno(angulo));
  return 0;
}