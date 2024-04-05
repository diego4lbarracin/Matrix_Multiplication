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
    -Reserva de memoria.
    -Creación de punteros para matrices del tipo double.
    -Asignación de memoria.
    -Ingreso de argumentos de entrada.
*/

// Librerias usadas en el programa.
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

// Reserva de memoria.
// Definicion de la palabra RESERVA para denotar el tamano del espacio de memoria.
#define RESERVA (1024*128*64*8)
// Creación de un vector cuyo tamano sera igual a RESERVA
static double MEM_CHUNK[RESERVA];

int main(int argc, char *argv[]){
  //Verficacion de que la cantidad de argumentos ingresada sea correcta.
  if( argc < 3){
    printf("No se ingresaron suficientes elementos\n");
    return 1;
  }else if(atoi(argv[1]) <= 0 && atoi(argv[2]) <= 0){
    printf("Los elementos son menores o iguales a 0\n");
    return 1;
  }
  //Captura de los valores ingresados como argumento.
  int N = atoi(argv[1]);
  int H = atoi(argv[2]);
  
  //printf("The size of the vector is: %d y %d\n", N, H);
  
  // Creacion de variables apuntadoras para hacer referencias a diferentes espacios de memoria
  // dentro de MEM_CHUNK[RESERVA]
  double *mA, *mB, *mC;
  //Definicion de los espacios de memoria a los que van a hacer referencia
  //los punteros.
  mA = MEM_CHUNK;
  mB= mA + ( N*N );
  mC= mB + ( N*N );

  
  printf("Fin del programa\n");
  return 0;
}