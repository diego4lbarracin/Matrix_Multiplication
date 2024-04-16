#ifndef __MATRIX_OPERATIONS_H__
#define __MATRIX_OPERATIONS_H__
#include <stdlib.h>


struct datosMM{
  int N; /*Dimension de la matriz*/
  int H; /*Cantidad de hilos de ejecucion*/
  int idHilo; /*Identidad de los hilos*/
  double* mA;
  double* mB;
  double* mC;
};

void inicializarMatrices(int n, double* mA, double* mB, double* mC);

void imprimirMatriz(int n, double* m);

void* multiplicacionMatriz(void* arg);

#endif
