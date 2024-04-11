/*Definición de la lógica de las funciones que se encuentran
en matrix_operations.h*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matrix_operations.h"



//Firma de funciones.
void inicializarMatrices(int n, double* mA, double* mB, double* mC){
  //Inicializacion de matrices.
  for (int i = 0; i < n*n; i++) {
    mA[i] = i*1.1;
    mB[i] = i*2.2;
    mC[i] = i;
  }
}
void imprimirMatriz(int n, double* m){
  //Impresion de matriz.
  if(n<9){
      for (int i = 0; i < n*n; i++) {
        if(i%n == 0){printf("\n");}
        printf("%f ", m[i]);
      }
      printf("\n***************************************\n");
  }else{
      printf("\n***************************************\n");
  }

}

void* multiplicacionMatriz(void* arg){
  struct datosMM *valorInterno = arg;
  /*Algoritmo simple de multiplicacion de matrices*/
  double *pA, *pB, sumaTemp;
  for (int i = 0; i < valorInterno->N; i++)
  {
      for (int j = 0; j < valorInterno->N; j++)
      {
        pA = valorInterno->mA + (i*valorInterno->N);
        pB = valorInterno->mB +j;
        for (int k = 0; k < valorInterno->N; k++, pA++, pB+=valorInterno->N)
        {
          sumaTemp += *pA * *pB;
        }
        valorInterno->mC[(j+i)*valorInterno->N] = sumaTemp;
      }
  }
  imprimirMatriz(valorInterno->N, valorInterno->mC);
  return NULL;
}