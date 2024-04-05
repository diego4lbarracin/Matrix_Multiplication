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
    struct datosMM *datos = arg;
  /*Algoritmo simple de multiplicacion de matrices*/
  double *pA, *pB, sumaTemp;
  for (int i = 0; i < datos->N; i++)
  {
      for (int j = 0; j < datos->N; j++)
      {
        pA = datos->mA + (i*datos->N);
        pB = datos->mB +j;
        for (int k = 0; k < datos->N; k++, pA++, pB+=datos->N)
        {
          sumaTemp += *pA * *pB;
        }
        datos->mC[(j+i)*datos->N] = sumaTemp;
      }
  }
  imprimirMatriz(datos->N, datos->mC);
  return NULL;
}