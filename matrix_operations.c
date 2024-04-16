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
    /*Asignación de valores a las matrices.*/
    mA[i] = i*1.1;
    mB[i] = i*2.2;
    mC[i] = i;
  }
}
void imprimirMatriz(int n, double* m){
  //Impresion de matriz.
  if(n<9){
      for (int i = 0; i < n*n; i++) {
        if(i%n == 0){printf("\n");} /*Nueva linea cada n elementos.*/
        printf("%.2f ", m[i]);
      }
      printf("\n***************************************\n");
  }else{
      printf("\n***************************************\n");
  }

}

void* multiplicacionMatriz(void* arg){
  /*Algoritmo simple de multiplicacion de matrices*/
  struct datosMM *valorInterno = arg; //Estructura para desencapsular los datos obtenidos como argumento.
  /*Declaracion de apuntadores y variables necesarias para la implementacion del algoritmo.*/
  double *pA, *pB, sumaTemp;
  int inicio=0, fin=0;
  /*Sentecia de control de flujo que permite asignar la posicion en la que se iterara
  en la matriz segun el hilo de ejecucion en el que nos encontremos en el vector
  declarado en mm_v03.c pthread_t hilos[H]*/
  if( valorInterno->idHilo == 0 ){
    /*Si el valoresMM->idHilo = 0, entonces se asigna la segunda mitad de la matriz.*/
    inicio = valorInterno->N / (valorInterno->idHilo+2);
    fin = valorInterno->N / (valorInterno->idHilo+1); 
  }else{
     /*Si el valoresMM->idHilo = 0, entonces se asigna la primera mitad de la matriz.*/
    inicio = 0;
    fin = valorInterno->N / (valorInterno->idHilo+1);
  }
  /*Ciclo para iterar sobre cada una de filas de la matriz A.*/
  for (int i = inicio; i < fin; i++)
  {
    /*Ciclo para iterar sobre cada elemento en la fila que se este
    evaluando (i) de la matriz A.*/
      for (int j = 0; j < valorInterno->N; j++)
      {
        /*Actualizacion a 0.0 para evitar errores de la variable sumaTemp 
        al asignar el valor en una nueva posicion en mC.*/
        sumaTemp= 0.0;
        /*Actualizacion de las direcciones de memoria 
        con los registros de la informacion a operar.*/
        pA = valorInterno->mA + (i*valorInterno->N);
        pB = valorInterno->mB +j;
        /*Ciclo para iterar sobre cada uno de los elementos en las columnas de la matriz B.*/
        for (int k = 0; k < valorInterno->N; k++, pA++, pB+=valorInterno->N)
        {
          /*Variable que suma los resultados de los productos.*/
          sumaTemp += *pA * *pB;
        }
        /*Asignacion de la suma de los productos en la respectiva posicion de la 
        matriz que almacenara el producto de la matriz A por la matriz B.*/
        valorInterno->mC[ (i*valorInterno->N) + j ] = sumaTemp;
      }
  }

  return NULL;
}