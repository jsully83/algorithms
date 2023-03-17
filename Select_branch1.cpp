#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>


void Display(int *a, int p, int r)
{
	for(int i=p;i<r;++i) 
    {
		std::cout << a[i] << "\t";
	}
	std::cout << std::endl;
}

void Swap(int* A, int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int Partition(int* A, int p, int r, int q);

int MedianPartition(int* A,int p,int r, int q)
{

    for (int i = p; i <= r ; i++)
    {
        if (A[i] == q) { Swap(A, i, r); break; }
    }
    return Partition(A, p, r, A[r]);
}

void InsertionSort(int v[], int n){
    int value;
    int i, j;
    for (i = 1; i < n; i++)
    {
        value = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > value)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = value;
        // Display(v, 0, n);
    }   
}

int Partition(int* A, int p, int r, int q)
{
    

    int pivot = q;
    int ll = p - 1;
    for (int j = p; j < r  ; j++)
    {
        if (A[j] <= pivot)
        {

            ll++;
            Swap(A, ll, j);
        }
    }
    Swap(A, ll + 1, r);
    return(ll + 1);
}

int SortAndFindMedian(int* subarr, int n)
{
    InsertionSort(subarr, n);
    int length = sizeof(subarr)/sizeof(subarr[0]) % 2;
    if (length != 0) //even
    {
        return subarr[(n/2) - 1]; 
    }
    else
    return subarr[n/2];
}

int Select(int A[], int p, int r, int k)
{
    if (k > 0 && k <= r - p + 1)
    {
        int n = r-p+1; 
        int i, median[(n+4)/5]; 
        for (i=0; i<n/5; i++)
            median[i] = SortAndFindMedian(A+p+i*5, 5);
        if (i*5 < n) 
        {
            median[i] = SortAndFindMedian(A+p+i*5, n%5);
            i++;
        }   
        int medOfMed = (i == 2)? median[i-2]:
                                 Select(median, 0, i-1, i/2);
        
        int pos = MedianPartition(A, p, r, medOfMed);
        if (pos-p == k-1)
            return A[pos];
        if (pos-p > k-1)  
            return Select(A, p, pos-1, k);
 
        return Select(A, pos+1, r, k-pos+p-1);
    }
    return INT_MAX;
}


int main() 
{

    // random seed
	srand((unsigned int)time(NULL));
	
    //create a new array A
	int A[100] = {0};
    int randomNumber;
	size_t len = sizeof(A)/sizeof(A[0]);
	
	// Fill array A[n, n-1, ..., 1]
    for (int i = 0; i <= len; i++)
    {
        A[i] = len - i;
    }
    Display(A, 0, len);

    // select a random number between 1 and 100. 
    // iterate through A[i] and swap with A[randomnumber]
    // add an external for loop that will increase randomness in the permutation
	for (size_t m = 0; m < 10; m++)
	{
		for (int i = 0; i < len; i++)
			{
				randomNumber = (rand() % 10 + 1) - 1;
				Swap(A, i, randomNumber);
			}
	}
    
    Display(A, 0, len);
    int k = 99;
    int m = Select(A, 0, len-1, k);
    printf("m = %d", m);


    return 0;
}
