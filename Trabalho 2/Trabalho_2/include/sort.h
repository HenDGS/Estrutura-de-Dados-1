#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listaencadeada.h"

void selectionSort(Lista *lista);
void insertionSort(Lista *lista);
void quickSort(Lista *lista, unsigned long int inicioVetor, unsigned long int fimVetor);
void mergeS(Dados *dados, unsigned long int comeco, unsigned long int meio, unsigned long int fim);
void mergeSort(Lista *lista, unsigned long int comeco, unsigned long int fim);
void bubbleSort(Lista *lista, unsigned long int tamanho);
void shellSort(Lista *lista, unsigned long int tamanho);
void buscaBinaria(Lista *lista, unsigned long int tamanho);
#endif // SORT_H_INCLUDED
