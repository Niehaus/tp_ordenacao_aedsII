#include "MergeSort.h"
#include <math.h>
#include <stdlib.h>

void mergeP(Pequeno *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1].chave < V[p2].chave)
                    temp[i]=V[p1++].chave;
                else
                    temp[i]=V[p2++].chave;

                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1)
                    temp[i]=V[p1++].chave;
                else
                    temp[i]=V[p2++].chave;
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)
            V[k].chave=temp[j];
    }
    free(temp);
}

void mergeSortP(Pequeno *V, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSortP(V,inicio,meio);
        mergeSortP(V,meio+1,fim);
        mergeP(V,inicio,meio,fim);
    }
}

void mergeG(Grande *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1].chave < V[p2].chave)
                    temp[i]=V[p1++].chave;
                else
                    temp[i]=V[p2++].chave;

                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1)
                    temp[i]=V[p1++].chave;
                else
                    temp[i]=V[p2++].chave;
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)
            V[k].chave=temp[j];
    }
    free(temp);
}

void mergeSortG(Grande *V, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSortG(V,inicio,meio);
        mergeSortG(V,meio+1,fim);
        mergeG(V,inicio,meio,fim);
    }
}

