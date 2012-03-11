#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DEFAULT_N 10

/*
	
	Split the data into two parts, where everything in the first
	part is less than everything in the second. Then keep doing 
	the same for each part, until your parts shrink to nothing.

   68000 real	0m0.024s
         user	0m0.018s
         sys	0m0.003s


*/
void _quick_sort(int *data, int left, int right);
int partition(int *data, int left, int right);

void swap(int *data, int a, int b) {
	int tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}

void sort(int *data, int nElem)
{
	_quick_sort(data, 0, nElem - 1);
}

void _quick_sort(int *data, int left, int right)
{
	if(left < right)
	{
		int partIndex = partition(data, left, right);
		_quick_sort(data, left, partIndex - 1);
		_quick_sort(data, partIndex + 1, right);
	}
}

int partition(int *data, int left, int right)
{
	int pivot = data[left];
	
	swap(data, right, left);

	int leftmost = left;
	int i = left;
	for(i; i < right; i++)
	{
		if(data[i] <= pivot)
		{
			swap(data, leftmost, i);
			leftmost++;
		}
	}
	
	swap(data, leftmost, right);
	
	return leftmost;
}

void display(int *data, int n)
{
	int i;
	for(i = 0; i < n -1; i++)
		printf("%d, ", data[i]);
		
	printf("%d\n", data[i]);
}


int main(int argc, char** argv)
{
	int N = DEFAULT_N;
	if(argc == 2)
		N = atoi(argv[1]);
		
	int * data = (int*) malloc(sizeof(int) * N);
	int i;
	srand(time(NULL));
	for(i = 0; i < N; i++)
	{
		data[i] = 3*N*(double)rand()/RAND_MAX;
	}
	
	display(data, N);
	
	sort(data, N);
	printf("\n");
	
	display(data, N);
	
	printf("\n");
	return 0;
}
