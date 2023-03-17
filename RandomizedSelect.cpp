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

void Display(int *a, int p, int r)
{
	for(int i=p;i<r;++i) {
		std::cout << a[i] << "\t";
	}
	std::cout << std::endl;
}

int Partition(int* A, int p, int r)
{
    int pivot = A[r - 1];
    int ll = p - 1;

    for (int j = p; j < r-1  ; j++)
    {
        if (A[j] <= pivot)
        {
            ll++;
            Swap(A, ll, j);
        }
    }

    Swap(A, ll + 1, r - 1);

    return(ll + 1);
}

int RandomizedPartition(int* A,int p,int r)
{

    int randi = (rand() %  (r-p) + p);
    Swap(A, randi, r - 1);
    return Partition(A, p, r);
}

int RandomizedSelect(int* A, int p, int r, int i)
{
    int q;
    int k;


    if (p == r - 1) //added -1 
    {
        return A[p];
    }
    q = RandomizedPartition(A, p, r);
    
    k = q - p + 1;

    if (i + 1 == k) //added + 1
    {
        return A[q]; 
    }
    else if (i < k)
    {
        return RandomizedSelect(A, p, q - 1, i);
    }
    else
    {
        return RandomizedSelect(A, q + 1, r, i - k);
    }    
}

int main() 
{
    // random seed
	srand((unsigned int)time(NULL));
	
    //create a new array A
	int A[100] = {0};
    // int A[6] = {7, 10, 4, 3, 20, 1};
    int randomNumber;
    int rank;
	size_t len = sizeof(A)/sizeof(A[0]);
	

	// Fill array A[n, n-1, ..., 1]
    for (int i = 0; i <= len; i++)
    {
        A[i] = len - i;
    }
    Display(A, 0, len);
    //select a random number between 1 and 100. 
    //iterate through A[i] and swap with A[randomnumber]
    //add an external for loop that will increase randomness in the permutation
	for (size_t m = 0; m < 10; m++)
	{
		for (int i = 0; i < len; i++)
			{
				randomNumber = (rand() % 10 + 1) - 1;
				Swap(A, i, randomNumber);
			}
	}

    //Sort
    Display(A, 0, len);
    rank = RandomizedSelect(A, 0, len, 99);
    printf("Returned k = %D", rank);

}