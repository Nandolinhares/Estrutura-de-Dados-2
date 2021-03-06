/*	This program tests the heap functions used in the 
	text. It uses random numbers to build a heap. 
	It then presents a menu that allows the user to 
	insert to, delete from, and print the heap. The maximum
	heap size is 1023.
	   Written by: 
	   Date: 
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "09-heap.h"
const int maxSize = 15;

//	Prototype Definitions 
int  compare    (void* arguPtr, void* heapPtr);
char getAction  (void);
void printHeap (HEAP* heap, int idx, int recuo);

#define strMax 40

typedef struct
{
	short sequence;
	int year;
	int mileage;
	char name[strMax];
} TABELA;




// A = Número total de milhas
// B = Número de anos no programa de passageiro frequente
// C = Número de ordem que representa a posição de chegada do cliente quando reservou o voo.
//	prioridade = A/1000 + B - C

int main (void)
{
//	Local Definitions 
	HEAP* heap;
	FILE* fpData;
	TABELA* pTabela;
	int*  dataPtr;

	short sequence;

	bool result;
	char action;
	int white_walker;
	

	char s[] = "45";

int num = atoi(s);
printf("%d\n",num );


	fpData = fopen("tabela.dat", "r");
	if (!fpData){
	    printf("\aErro na abertura do arquivo\n");
	    exit (110);
	}

	while (fscanf(fpData, " %hd", &sequence) == 1){

		pTabela = (TABELA*) malloc(sizeof(TABELA));

		if (!(pTabela)){
			printf("\aSem memória para fazer construir a lista\n");
			exit (100);
		}

		pTabela->sequence = sequence;
		printf("-------------------------\n");
		printf("Sequence: %hd \n",pTabela->sequence);
		printf("Teste\n");

		// Skip tabs and quote 
		
		while ((fgetc(fpData)) != '\t');
		while ((fgetc(fpData)) != '0');

		//fscanf(fpData, " %40[^\"], %*c", pTabela->picture);
		fscanf(fpData, " %40[^\"], %*d", pTabela->year);
		printf("Year: %d \n",pTabela->year);

		while ((fgetc(fpData)) != '\t');
		while ((fgetc(fpData)) != '0');

		//fscanf(fpData, " %40[^\"], %*c", pTabela->director);
		fscanf(fpData, " %40[^\"], %*d", pTabela->mileage);
		printf("Mileage: %d \n",pTabela->mileage);
		printf("------------------------------\n");
		//scanf("%c",&c);  

		while ((fgetc(fpData)) != '\t');
		while ((fgetc(fpData)) != '"');

		fscanf(fpData, " %40[^\"], %*c", pTabela->name);
		printf("Name: %s \n",pTabela->name);
		printf("------------------------------\n");


		// Insert into list 
		/*addResult = addNode (list, pTabela);
		if (addResult != 0){
			if (addResult == -1){
				printf("Memory overflow adding movie\a\n");
				exit (120);
			}
		}
		//else{
			//printf("Duplicate year %hd not added\n\a", pPic->year);
		//}*/
		while (fgetc(fpData) == '\n');

	} // while 




	/*
//	Statements 
	printf("Criação do Heap\n");
	heap = heapCreate (maxSize, compare);
	if (!heap)
	   printf("Can't create heap in main\n"), exit (100);
	
	// Fill half the heap with random numbers 
	for (white_walker = 0; white_walker <= maxSize / 2 - 1; white_walker++)
	    {
	     dataPtr  = (int*)malloc(sizeof (int));
	     if (!dataPtr)
	        printf("Overflow in main\n"), exit (101);
	     
	     *dataPtr = rand() % 999 + 1;
	     heapInsert (heap, dataPtr);
	    } // for 
	printf("\nEnd of heap creation\n\n");
	
	printHeap (heap, 0, 0);
	

	
	printf("End of Heap Test\n");*/
	return 0;
}	// main 




int compare (void* arg1, void* arg2)
{
//	Local Declarations 
	int arguOne;
	int arguTwo;
	
//	Statements 
	arguOne = *(int*)arg1;
	arguTwo = *(int*)arg2;

	if (arguOne < arguTwo)
	    return -1;
	else if (arguOne == arguTwo)
	    return  0;
	else
	    return +1;
}	// compare 

/*	================== getAction ================== 
	Get and return a valid action from keyboard.
	   Pre  nothing 
	   Post valid action read and returned 
*/
char getAction (void)
{
//	Local Definitions 
	char action;

	int  OK = 0;

//	Statements 
	do
	   {
	    printf("\nPlease enter action <P, I, D, U, Q>: ");
	    scanf (" %c", &action);
	    action = toupper(action);
	    switch (action)
	       {
	        case 'P':
	        case 'I':
	        case 'D':
	       	case 'U':
	        case 'Q': OK = 1;
	                  break;
	        default:  
	          printf("< %c > action invalid: ",action);
	          printf("Please re-enter\a\a\n" ); 
	          break;
	       } // switch 
	   } while (!OK);
	return action;
}	// getAction 

void printHeap (HEAP* heap, int idx, int recuo)
{ int i;
  for (i=0; i<heap->size; i++){
      printf("%d\n",*(int*)(heap->heapAry[i]));
  }
   /*if (idx<heap->size)
  {  printHeap (heap, idx*2+1, recuo+4);
     printf("%d\n",*((int*)(heap->heapAry[idx])));
     printHeap (heap, idx*2+2, recuo+4);
  } */
  return;
}

/*	Results: (After heap automatically generated)

Begin Heap Test
array size is 15
End of heap creation

          34
     633
         124
 855
          83
     764
         533

Please enter action <P, I, D, U, Q>: u
Number of elements in heap:   7
Head is NOT full
Head is NOT emtpy

Please enter action <P, I, D, U, Q>: */
