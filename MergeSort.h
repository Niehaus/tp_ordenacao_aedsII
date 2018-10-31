#ifndef MERGESORT_H
#define MERGESORT_H

#include "registro.h"

void mergeP(Pequeno *V, int inicio, int meio, int fim);

void mergeSortP(Pequeno *V, int inicio, int fim);

void mergeG(Grande *V, int inicio, int meio, int fim);

void mergeSortG(Grande *V, int inicio, int fim);

#endif
