/*
  Fecha: 04/04/04
  Autor: Diego Albarracin
  Materia: Sistemas Operativos
  Tema: Concurrencia
  Objetivo: Metodologia para la implementacion de la 
  multiplicacion de matrices haciendo uso de paralelismo 
  por medio de la biblioteca Pthreads. Se hace uso del
  algoritmo clásico de multiplicación de matrices, en este
  caso, matrices cuadradas.
  ----mm_v01.c
    -Reserva de memoria.
    -Creación de punteros para matrices del tipo double.
    -Asignación de memoria.
    -Ingreso de argumentos de entrada.
  ----mm_v02.c
    -Inicializacion de matrices.
    -Impresion de matrices.
    -Funcion para inicializar las matrices.
    -Funcion para imprimir las matrices.
    -Multiplicacion de matrices.
  ----mm_v03.c
    -Delaracion de vectores de hilos.
  ---Implemetacion de Paralelismo (Clase 4/11/2024)
      -Resolucion de la multiplicacion de hilos.
      -Se crea el vector de hilos.
      -Se tiene pendiente la exclusion de los hilos.
      -Se convierten las matrices a varibles de alcance global.
      -Encapsular los datos para enviarlos como argumento a la funcion que ejecutara
      el hilo.
      -Posteriormente, se desencapsulan los datos una vez han sido recibidos por el metodo
      multiplicacionMatriz.
*/

// Librerias usadas en el programa.
#include <stdio.h>
#include <pthread.h>
#include "matrix_operations.h"

// Reserva de memoria.
// Definicion de la palabra RESERVA para denotar el tamano del espacio de memoria.
#define RESERVA (1024*128*64*8)
// Creación de un vector cuyo tamano sera igual a RESERVA
static double MEM_CHUNK[RESERVA];


int main(int argc, char *argv[]){
  //Verficacion de que la cantidad de argumentos ingresada sea correcta.
  if( argc < 3){
      fprintf(stderr, "No se ingresaron suficientes argumentos.\n");
      return 1;
  } else if(atoi(argv[1]) <= 0 && atoi(argv[2]) <= 0){
      fprintf(stderr, "Los argumentos ingresados son menores o iguales a 0\n");
      return 1;
  }
  //Captura de los valores ingresados como argumento.
  int N = atoi(argv[1]);
  int H = atoi(argv[2]);


  // Creacion de variables apuntadoras para hacer referencias a diferentes espacios de memoria
  // dentro de MEM_CHUNK[RESERVA] 
  double *mA, *mB, *mC;

  //Definicion de los espacios de memoria a los que van a hacer referencia
  //los punteros.
  mA = MEM_CHUNK;
  mB= mA + ( N*N );
  mC= mB + ( N*N );
  //Inicializacion de matrices.
  inicializarMatrices(N, mA, mB, mC);

  //Impresion de cada una de las matrices.
  printf("Matriz A\n");
  imprimirMatriz(N, mA);
  printf("Matriz B\n");
  imprimirMatriz(N, mB);

 /*Creación de tantos hilos de ejecución como se hayan recibido como argumento*/
  pthread_t hilos[H];

  printf("Matriz Producto mA * mB\n");

  for(int h=0; h<H; h++){
      /*Instancia de un puntero de tipo datosMM.
      Se asigna su tamano en memoria por medio del metodo malloc*/
      struct datosMM* valoresMM  = (struct datosMM *) malloc(sizeof(struct datosMM));
      valoresMM->N = N;
      valoresMM->H = H;
      valoresMM->mA = mA;
      valoresMM->mB = mB;
      valoresMM->mC = mC; 
      /*Asignando como id el valor de h*/
      valoresMM->idHilo = h;
      /*Funcion par la creacion de hilos de ejecucion.*/
      pthread_create(&hilos[h], NULL, multiplicacionMatriz, valoresMM);
  }

  /*Puesta en espera para terminacion de cada  uno de los hilos*/
  for (int h = 0; h < H; h++)
  {
      pthread_join(hilos[h], NULL);
  }


  printf("\nFin del programa\n");
  // return 0;
  pthread_exit( NULL );
  // free(valoresMM);

}

