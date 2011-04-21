#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DEFAULT_N 10

/*
	Recurse, dividing the array in half each time, until there are only 2 elements.
	Sort these two elements, then do the same process with the other half. Then,
	combine these two sorted sub-arrays, taking the smallest item from each.
	

   68000 real	0m0.167s
         user	0m0.059s
         sys	0m0.014s


*/
void _merge_sort(int *data, int left, int right);
void _merge(int *data, int left, int half, int right);

int *buff;
void sort(int *data, int nElem)
{
	buff = (int*)malloc(sizeof(int) * nElem);
	if(buff == NULL)
	{
		printf("whoa.");
		return;
	}
	return _merge_sort(data, 0, nElem - 1);
}

void _merge_sort(int *data, int left, int right)
{
	if(left < right)
	{
		int half = (left + right)/2;
		_merge_sort(data, left, half);
		_merge_sort(data, half + 1, right);
		_merge(data, left, half, right);
	}
}

void _merge(int *data, int left, int half, int right)
{
	int i;
	for(i = left; i <= right; i++)
	{
		*(buff+i) = *(data + i);
	}
	
	int* leftP = buff + left;
	int* rightP = buff + half + 1;
	for(i = left; i <= right; i++)
	{
		// if we're out of elements on the right, take from the left
		if(rightP > (buff + right))
		{
			*(data + i) = *leftP;
			leftP++;
		}
		// if we're out of elements on the left, take from the right
		else if(leftP > (buff + half))
		{
			*(data + i) = *rightP;
			rightP++;
		}
		// otherwise, grab the smallest
		else
		{
			if(*leftP < *rightP)
			{
				*(data + i) = *leftP;
				leftP++;
			}
			else
			{
				*(data + i) = *rightP;
				rightP++;
			}
		}
	}
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
	
	display(data, N);
	
	sort(data, N);
	
	display(data, N);
	
	printf("\n");
	return 0;
}