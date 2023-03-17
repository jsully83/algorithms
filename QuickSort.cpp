#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>



void Swap(int* A, int index1, int index2)
{
    int temp = A[index1];
    A[index1] = A[index2];
    A[index2] = temp;
}

void display(int *a, int size) 
{
	for(int i=0;i<size;++i) {
		std::cout << a[i] << "\t";
	}
	std::cout << std::endl;
}

int Partition(int* A, int p, int r)
{
    // printf("partition\n");
    int pivot = A[r -1];
    // printf("A[r] = %d r = %d\n", A[r], r);
    int i = p - 1;

    for (int j = p; j < r-1  ; j++)
    {
        // printf("j = %d A[j] = %d i = %d\n", j, A[j], i);
        // printf("partition for\n");
        if (A[j] <= pivot)
        {
            i++;
            //printf("j = %d pivot = %d r = %d i = %d\n", j, pivot, r, i);
            
            Swap(A, i, j);
        }
        
    }

    int b = A[i + 1];
    A[i + 1] = pivot;
    A[r - 1] = b;

    return(i + 1);
}

int RandomizedPartition(int* A,int p,int r)
{

    int i = (rand() %  (r-p) + p);
    // printf("i = %d p = %d r = %d\n" ,i, p, r);
    Swap(A, i, r - 1);
    // display(A, r);
    return Partition(A, p, r);
}

void QuickSort(int* A, int p, int r)
{

    if (p < r)
    {
        int q = RandomizedPartition(A, p, r);
        // int q = Partition(A, p, r);
        QuickSort(A, p, q);
        // display(A, r);
        QuickSort(A, q + 1, r);
        // display(A, r+1);
    }

}


int main()
{
    srand((unsigned int)time(NULL));
    
    int a[100] = {};
	int len = sizeof(a)/sizeof(a[0]);
    double cpu_time_used;

    for (int i = 1; i <= len; i++)
    {
        // a[i] = len - i;
        a[i - 1] = i;
    //    int j = rand() % 100 + 1;
    //    printf("j = %d\n", j);
    }
    
    for (int i = 0; i < 5; i++)
    {
        	// display(a, len);
        clock_t start = clock();
        QuickSort(a, 0, len);
        clock_t end = clock();
        display(a, len);

        cpu_time_used  = ((double) (end - start))  / CLOCKS_PER_SEC;
        printf("Round %d Execution time took = %f5\n", i + 1, cpu_time_used);
    }
}

