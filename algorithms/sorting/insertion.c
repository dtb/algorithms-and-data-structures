#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DEFAULT_N 10

/*
  For each element in data, move the elements that are greater than the element forward until 
  the element is in the right spot, or we get to the beginning.

   68000 ints: real	0m6.820s
               user	0m6.805s
               sys	0m0.005s

*/
void insertion_sort(int *data, int nElem)
{
	int i;
	int nComps = 0;
	for(i = 1; i < nElem; i++)
	{
		int value = *(data + i);
		int j = i - 1;
		
		while(j >= 0 && value < *(data + j))
		{
			*(data + j + 1) = *(data + j);
			j--;
			nComps++;
		}
		
		*(data + j + 1) = value;
	}
	printf("Did %d cmps for %d values (%d worst case)\n", nComps, nElem, nElem * nElem);
}

void display(int *data, int n)
{
	int i;
	for(i = 0; i < n -1; i++)
		printf("%d, ", *(data + i));
		
	printf("%d\n", *(data + i));
}


int main(int argc, char** argv)
{
	int N = DEFAULT_N;
	if(argc == 2)
		N = atoi(*(argv + 1));
		
	int * data = (int*) malloc(sizeof(int) * N);
	int i;
	srand(time(NULL));
	for(i = 0; i < N; i++)
	{
		*(data + i) = 3*N*(double)rand()/RAND_MAX;
	}
	
	display(data, 25);
	
	insertion_sort(data, N);
	
	display(data, 25);
	
	printf("\n");
	return 0;
}