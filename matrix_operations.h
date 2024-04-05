#ifndef __MATRIX_OPERATIONS_H__
#define __MATRIX_OPERATIONS_H__

struct datosMM{
  int N; 
  double* mA;
  double* mB;
  double* mC;
};

void inicializarMatrices(int n, double* mA, double* mB, double* mC);

void imprimirMatriz(int n, double* m);

void* multiplicacionMatriz(void* arg);

#endif
