# Matrix_Multiplication
In this repository you will find a special implementation of the matrix multiplication algorithm taking advantage of the multithreading benefits in terms of performance using the C programming language.for my Operating Systems class at University.

## How to Execute this Project
To execute this project, you need to have installed a compiler for the C programming language. Once installed and setted everything up, you need to execute this command to compile the files.

- gcc .\matrix_operations.c .\mm_v03.c "nameOfExeFile"

After have done that, you will obtain an executable file that requires two arguments, the number of rows and columns the matrices will have and the number of threads that will be used to divide the process of multiplying two matrices.  

- ./nameOfExeFile 4 2

There are two conditions that must be followed, otherwise the programm will not work properly, these conditions are:
- The number of rows and columns of the matrix must be even, in other words, 2n.
- The number of threads must be equal to 2.
