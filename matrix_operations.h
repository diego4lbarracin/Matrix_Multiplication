#ifndef __MATRIX_OPERATIONS_H__
#define __MATRIX_OPERATIONS_H__
#include <stdlib.h>
/*Estructura datosMM usada para encapsular la informacion necesaria para ejecutar la 
multipliacion de matrices por medio de hilos de ejecucion.*/
struct datosMM{
  int N; /*Dimension de la matriz*/
  int H; /*Cantidad de hilos de ejecucion*/
  int idHilo; /*Identidad de los hilos*/
  double* mA; /*Puntero a la matriz mA*/
  double* mB; /*Puntero a la matriz mB*/
  double* mC; /*Puntero a la matriz mC*/
};
/*Funcion para inicializar las matrices.*/
void inicializarMatrices(int n, double* mA, double* mB, double* mC);
/*Funcion para imprimir la matriz deseada.*/
void imprimirMatriz(int n, double* m);
/*Funcion para realizar la multiplicacion de matrices por medio de hilo. Recibe un 
argumento, en lugar de muchos parametros. En este caso, recibira como parametro
los datos de las matrices encapsulados en la struct datosMM.*/
void* multiplicacionMatriz(void* arg);

#endif
