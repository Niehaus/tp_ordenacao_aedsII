#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "tempo.h"
#include "OrdenaQuase.h"
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>



		int main(int argc, char *argv[]){
			FILE *saida = fopen("saida.txt","w");
			int i,TAM,q,p,vn[6]={20,500,1000,50000,200000,1000000},k,meanH;		
			Tempo t; 

			//variáveis responsáveis pela contagem de tempo de usuário e sistema.
			double tempoU,tempoS;
			struct rusage resources;
			struct timeval inicioU, inicioS, fimU, fimS;
			
			
			
			/*Variavel TAM se iguala ao vetor vn para modificar o número de chaves
			a serem geradas e ordenadas, no caso, 6 diferentes*/
			for (p = 0; p < 10; p++){
				for(q = 0; q < 2; q++){
				
				TAM=vn[q];
				fprintf(saida,"\nROUND: %d metodo: %d\n",p,TAM);				
				
				Pequeno *vPHeapT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGHeapT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPHeap = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGHeap = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPHeapD = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGHeapD = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPHeapDT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGHeapDT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPQuick = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGQuick = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPQuickT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGQuickT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPQuickD = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGQuickD = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPQuickDT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGQuickDT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPSelect = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGSelect = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPSelectT= (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGSelectT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPSelectD = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGSelectD = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPSelectDT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGSelectDT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPInsert = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGInsert = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPInsertT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGInsertT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPInsertD = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGInsertD = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPInsertDT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGInsertDT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPShell = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGShell = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPShellD = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGShellD = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPShellT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGShellT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPShellDT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGShellDT = (Grande *) malloc(sizeof(Grande) * TAM);

			//Gerador de chaves.
			for (i = 0; i < TAM; i++) {
				vPHeap[i].chave = rand() % TAM;
				vGHeap[i].chave = rand() % TAM;
				vPHeapD[i].chave = vPHeap[i].chave;
				vPQuick[i].chave = vPHeap[i].chave;
				vPQuickD[i].chave = vPHeap[i].chave;
				vPSelect[i].chave = vPHeap[i].chave;
				vPSelectD[i].chave = vPHeap[i].chave;
				vPInsert[i].chave = vPHeap[i].chave;
				vPInsertD[i].chave = vPHeap[i].chave;
				vPShell[i].chave = vPHeap[i].chave;
				vPShellD[i].chave = vPHeap[i].chave;
				//Itens Grandes
				vGHeapD[i].chave = vGHeap[i].chave;
				vGQuick[i].chave = vGHeap[i].chave;
				vGQuickD[i].chave = vGHeap[i].chave;
				vGSelect[i].chave = vGHeap[i].chave;
				vGSelectD[i].chave = vGHeap[i].chave;
				vGInsert[i].chave = vGHeap[i].chave;
				vGInsertD[i].chave = vGHeap[i].chave;
				vGShell[i].chave = vGHeap[i].chave;
				vGShellD[i].chave = vGHeap[i].chave;
			}
				//Chaves quase totalmente ordenadas.
			for ( k = 0; k < TAM; k++) {
				vPQuickT[k].chave=k;
				vGQuickT[k].chave=k;
					
			}
				
				ordenaQuaseP(vPQuickT,TAM,5);
				ordenaQuaseG(vGQuickT,TAM,5);
				
			for(k = 0; k < TAM; k++){
				vPHeapT[k].chave = vPQuickT[k].chave;
				vPShellT[k].chave = vPQuickT[k].chave;
				vPSelectT[k].chave = vPQuickT[k].chave;
				vPInsertT[k].chave = vPQuickT[k].chave;
				vPHeapDT[k].chave = vPQuickT[k].chave;
				vPQuickDT[k].chave = vPQuickT[k].chave;
				vPShellDT[k].chave = vPQuickT[k].chave;
				vPSelectDT[k].chave = vPQuickT[k].chave;
				vPInsertDT[k].chave = vPQuickT[k].chave;
				//Chaves Grandes
				vGQuickT[k].chave = vGHeapT[k].chave;
				vGShellT[k].chave = vGQuickT[k].chave;
				vGSelectT[k].chave = vGQuickT[k].chave;
				vGInsertT[k].chave = vGQuickT[k].chave;
				vGHeapDT[k].chave = vGHeapT[k].chave;
				vGQuickDT[k].chave = vGHeapT[k].chave;
				vGShellDT[k].chave = vGQuickT[k].chave;
				vGSelectDT[k].chave = vGQuickT[k].chave;
				vGInsertDT[k].chave = vGQuickT[k].chave;
			}			
			//Fim chaves QTO
			//Chama o HEAP
			iniciaTempo(&t);
			heapsortP(vPHeap,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário HEAP Pequeno %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema HEAP Pequeno %d: %.9f\n",TAM,tempoS);
				
			//Contagem tempo chave grande crescente HEAP;
			iniciaTempo(&t);
			heapsortG(vGHeap,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário HEAP Grande %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema HEAP Grande %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");
		 	//Decrescente
		 	//Contagem de tempo Chave pequena Decrescente.

			iniciaTempo(&t);
		 	heapsortPD(vPHeapD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário HEAP Pequeno Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema HEAP Pequeno Decrescente %d: %.9f\n",TAM,tempoS);
			//Contagem de tempo Chave pequena Decrescente HEAP.
			//Inicia a contagem de tempo do usuario e sistema.

			iniciaTempo(&t);
			heapsortGD(vGHeapD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);


			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário HEAP Grande Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema HEAP Grande Decrescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//QUASE TOTALMENTE ORDENADO HEAP
			//Contagem de tempo Chave pequena crescente.
		 	//Inicia a contagem de tempo do usuario e sistema.

			iniciaTempo(&t);
			heapsortP(vPHeapT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário HEAP Pequeno QTO %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema HEAP Pequeno QTO %d: %.9f\n",TAM,tempoS);

			iniciaTempo(&t);
			heapsortG(vGHeapT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário HEAP Grande QTO %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema HEAP Grande QTO %d: %.9f\n",TAM,tempoS);
		 	fprintf(saida,"\n");

		 	//Decrescente
			//Contagem de tempo Chave pequena Decrescente QTO.

			iniciaTempo(&t);
			heapsortPD(vPHeapDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário HEAP Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema HEAP Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoS);

			//Contagem de tempo Chave Grande Decrescente.
		 	//Inicia a contagem de tempo do usuario e sistema.

			iniciaTempo(&t);
			heapsortGD(vGHeapDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário HEAP Grande Decrescente QTO %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema HEAP Grande Decrescente QTO %d: %.9f\n",TAM,tempoS);
		 	fprintf(saida,"\n");
			//FIM HEAP

			//Chama Quick
			//Contagem chave pequena crescente
			//Inicia a contagem de tempo do usuario e sistema.

			iniciaTempo(&t);
			quicksortP(vPQuick, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Pequeno %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Pequeno %d: %.9f\n",TAM,tempoS);

			iniciaTempo(&t);
			quicksortG(vGQuick, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Grande %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Grande %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente QUICK
			//Contagem chave pequena crescente
			//Inicia a contagem de tempo do usuario e sistema.

			iniciaTempo(&t);
			quicksortPD(vPQuickD, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Pequeno Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Pequeno Decrescente %d: %.9f\n",TAM,tempoS);

			iniciaTempo(&t);
			quicksortGD(vGQuickD, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);

			//Contagem chave grande Decrescente
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Grande Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Grande Decrescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			iniciaTempo(&t);
			quicksortP(vPQuickT, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Pequeno QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Pequeno QTO %d: %.9f\n",TAM,tempoS);


			iniciaTempo(&t);
			quicksortG(vGQuickT, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Grande QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Grande QTO %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente QUICK QTO
			//Contagem chave pequena crescente
			//Inicia a contagem de tempo do usuario e sistema.

			iniciaTempo(&t);
			quicksortPD(vPQuickDT, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoS);

			iniciaTempo(&t);
			quicksortGD(vGQuickDT, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Grande Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Grande Decrescente QTO %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");
			//FIM QUICK QTO

		 	//chama selectionsort
			//Inicia contagem de tempo chave pequena
			//Inicia a contagem de tempo do usuario e sistema.

			iniciaTempo(&t);
			selectionsortP(vPSelect,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Pequeno %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Pequeno %d: %.9f\n",TAM,tempoS);

			//Inicia contagem de tempo chave grande SELECT

			iniciaTempo(&t);
			selectionsortG(vGSelect,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Grande %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Grande %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente SELECT
			//Inicia contagem de tempo chave pequena Decrescente
			//Inicia a contagem de tempo do usuario e sistema.

			iniciaTempo(&t);
			selectionsortPD(vPSelectD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Pequeno Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Pequeno Decrescente %d: %.9f\n",TAM,tempoS);

			//Inicia contagem de tempo chave grande Decrescente

			iniciaTempo(&t);
			selectionsortGD(vGSelectD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário SELECT Grande Decrescente %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema SELECT Grande Decrescente %d: %.9f\n",TAM,tempoS);
		 	fprintf(saida,"\n");

			//QUASE TOTALMENTE ORDENADO SELECT QTO
			//Contagem chave pequena crescente
			//chama selectionsort
			//Inicia contagem de tempo chave pequena
			//Inicia a contagem de tempo do usuario e sistema.

			iniciaTempo(&t);
			selectionsortP(vPSelectT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Pequeno QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Pequeno QTO %d: %.9f\n",TAM,tempoS);

			iniciaTempo(&t);
			selectionsortG(vGSelectT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Grande QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Grande QTO %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			iniciaTempo(&t);
			selectionsortPD(vPSelectDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoS);

			iniciaTempo(&t);
			selectionsortGD(vGSelectDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário SELECT Grande Decrescente QTO %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema SELECT Grande Decrescente QTO %d: %.9f\n",TAM,tempoS);
		 	fprintf(saida,"\n");

			//FIM SELECT

			//chama shellsort
			//Inicia contagem de tempo chave pequena
			iniciaTempo(&t);
			shellSortP(vPShell,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Pequeno %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Pequeno %d: %.9f\n",TAM,tempoS);

			//Inicia contagem de tempo chave grande
			//Inicia a contagem de tempo do usuario e sistema.
			iniciaTempo(&t);
 		 	shellSortG(vGShell,TAM);
 		 	finalizaTempo(&t, &tempoU, &tempoS);

		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário SHELL Grande %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema SHELL Grande %d: %.9f\n",TAM,tempoS);
		 	fprintf(saida,"\n");

		 	//Decrescente SHELL
		 	//Inicia contagem de tempo chave pequena
			iniciaTempo(&t);
			shellSortPD(vPShellD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Pequeno Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Pequeno Decrescente %d: %.9f\n",TAM,tempoS);

			iniciaTempo(&t);
			shellSortGD(vGShellD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

	 		//imprime os tempos de usuário e sistema.
	 		fprintf(saida,"Tempo de usuário SHELL Grande Decrescente %d: %.9f\n",TAM,tempoU);
	 		fprintf(saida,"Tempo de sistema SHELL Grande Decrescente %d: %.9f\n",TAM,tempoS);
	 		fprintf(saida,"\n");

			//Quase totalmente ordenado SHELL
			iniciaTempo(&t);
			shellSortP(vPShellT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Pequeno QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Pequeno QTO %d: %.9f\n",TAM,tempoS);

			iniciaTempo(&t);
			shellSortG(vGShellT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Grande QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Grande QTO %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente SHELL
			//Contagem chave pequena Decrescente QTO

			iniciaTempo(&t);
			shellSortPD(vPShellDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoS);

			iniciaTempo(&t);
			shellSortGD(vGShellDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Grande Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Grande Decrescente QTO %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");
			//FIM SHELL QTO

		 	//chama insertionsort
		 	//Inicia contagem de tempo chave pequena
			//Inicia a contagem de tempo do usuario e sistema.

			iniciaTempo(&t);
			insertionSortP(vPInsert,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Pequeno %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Pequeno %d: %.9f\n",TAM,tempoS);

			//Inicia contagem de tempo chave grande
			iniciaTempo(&t);
			insertionSortG(vGInsert,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

	 		//imprime os tempos de usuário e sistema.
	 		fprintf(saida,"Tempo de usuário INSERT Grande %d: %.9f\n",TAM,tempoU);
	 		fprintf(saida,"Tempo de sistema INSERT Grande %d: %.9f\n",TAM,tempoS);
	 		fprintf(saida,"\n");

			//Decrescente
	 		//Inicia contagem de tempo chave pequena Decrescente
			iniciaTempo(&t);
			insertionSortPD(vPInsertD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Pequeno Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Pequeno Decrescente %d: %.9f\n",TAM,tempoS);

			//Inicia contagem de tempo chave pequena
			iniciaTempo(&t);
			insertionSortGD(vGInsertD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Grande Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Grande Decrescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

				//INSERT QTO
		//chama insertionsort QTO
		//Inicia contagem de tempo chave pequena
		//Inicia a contagem de tempo do usuario e sistema.

		iniciaTempo(&t);
		insertionSortP(vPInsertT,TAM);
		finalizaTempo(&t, &tempoU, &tempoS);

		//imprime os tempos de usuário e sistema.
		fprintf(saida,"Tempo de usuário INSERT Pequeno QTO %d: %.9f\n",TAM,tempoU);
		fprintf(saida,"Tempo de sistema INSERT Pequeno QTO %d: %.9f\n",TAM,tempoS);

		//Inicia contagem de tempo chave grande
		iniciaTempo(&t);
		insertionSortG(vGInsertT,TAM);
		finalizaTempo(&t, &tempoU, &tempoS);

		//imprime os tempos de usuário e sistema.
		fprintf(saida,"Tempo de usuário INSERT Grande QTO %d: %.9f\n",TAM,tempoU);
		fprintf(saida,"Tempo de sistema INSERT Grande QTO %d: %.9f\n",TAM,tempoS);
		fprintf(saida,"\n");

		//Decrescente
		//Inicia contagem de tempo chave pequena Decrescente
		iniciaTempo(&t);
		insertionSortPD(vPInsertDT,TAM);
		finalizaTempo(&t, &tempoU, &tempoS);

		//imprime os tempos de usuário e sistema.
		fprintf(saida,"Tempo de usuário INSERT Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoU);
		fprintf(saida,"Tempo de sistema INSERT Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoS);

		//Inicia contagem de tempo chave pequena
		iniciaTempo(&t);
		insertionSortGD(vGInsertDT,TAM);
		finalizaTempo(&t, &tempoU, &tempoS);

		//imprime os tempos de usuário e sistema.
		fprintf(saida,"Tempo de usuário INSERT Grande Decrescente QTO %d: %.9f\n",TAM,tempoU);
		fprintf(saida,"Tempo de sistema INSERT Grande Decrescente QTO %d: %.9f\n",TAM,tempoS);
		fprintf(saida,"\n");

		//FIM INSERT QTO

	 		free(vPSelect);
			free(vGSelect);

			free(vPSelectD);
			free(vGSelectD);

			free(vPSelectDT);
			free(vGSelectDT);

			free(vPInsert);
			free(vGInsert);

			free(vPInsertD);
			free(vGInsertD);

			free(vPInsertDT);
			free(vGInsertDT);

			free(vPShell);
			free(vGShell);

			free(vPShellD);
			free(vGShellD);

			free(vPShellDT);
			free(vGShellDT);

			free(vPHeap);
			free(vGHeap);

			free(vPHeapD);
			free(vGHeapD);

			free(vPHeapDT);
			free(vGHeapDT);

			free(vPQuick);
			free(vGQuick);

			free(vPQuickD);
			free(vGQuickD);

			free(vPQuickDT);
			free(vGQuickDT);
			
		}
	}		
			fclose(saida);
	return 0;
}

