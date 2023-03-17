#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>

using namespace std;


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
    // printf("MedianPart p  = %d, r = %d  q = %d \n",p, r, q);
    // Display(A, p, r + 1);
    for (int i = p; i <= r ; i++)
    {
        if (A[i] == q) { Swap(A, i, r); break; }
    }
    // Display(A, p, r + 1);
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
    // printf("p = %d, r = %d\n", p, r);
    

    int pivot = q;
    int ll = p - 1;
    // printf("pivot = %d, p = %d, ll = %d\n",pivot, p, ll);
    for (int j = p; j < r  ; j++)
    {
        if (A[j] <= pivot)
        {

            ll++;
            // printf("Aj = %d, pivot = %d, ll = %d\n",A[j], pivot, ll);
            // Display(A, p, r + 1);
            Swap(A, ll, j);
            // Display(A, 0, r + 1);
        }
    }
    // Display(A, 0, r + 1);
    Swap(A, ll + 1, r);
    // Display(A, 0, r + 1);
    return(ll + 1);
}

int SortAndFindMedian(int* subarr, int n)
{
    InsertionSort(subarr, n);
    int length = sizeof(subarr)/sizeof(subarr[0]) % 2;
    cout << length;
    if (length != 0) //even
    {
        return subarr[(n/2) - 1]; 
    }
    else
    return subarr[n/2];
}

// group elements into n/5 groups of 5 elements each.
int Select(int* A, int left, int right, int val)
{
    int n = right - left + 1;  //number of elements in the array
    int numGroups = int(ceil(5));
    int median[numGroups]; //temporary array for storing medians of n/5 groups + 1 for remainder elements
    // int temp[5];
    for (int i = 0; i < numGroups; i++)
    {   
        
        median[i] = SortAndFindMedian(A+left+i*5, 5);
        
    }


    return 0;
}


int main() 
{

    // random seed
	srand((unsigned int)time(NULL));
	
    // //create a new array A
	// int A[100] = {0};
    // int randomNumber;
	// size_t len = sizeof(A)/sizeof(A[0]);
	
    

	// // Fill array A[n, n-1, ..., 1]
    // for (int i = 0; i <= len; i++)
    // {
    //     A[i] = len - i;
    // }
    // Display(A, 0, len);

    // // select a random number between 1 and 100. 
    // // iterate through A[i] and swap with A[randomnumber]
    // // add an external for loop that will increase randomness in the permutation
	// for (size_t m = 0; m < 10; m++)
	// {
	// 	for (int i = 0; i < len; i++)
	// 		{
	// 			randomNumber = (rand() % 10 + 1) - 1;
	// 			Swap(A, i, randomNumber);
	// 		}
	// }
    
    
    // Display(A, 0, len);
    int A[] = {12, 3, 5, 7, 4, 19, 26, 6, 15, 30};
    size_t len = sizeof(A)/sizeof(A[0]);
    // int len = 10;
    Display(A, 0, len);
    int k = 7;
    int m = Select(A, 0, len-1, k);
    printf("m = %d", m);


    return 0;
}
// If k is smaller than number of elements in array
    // if (v > 0 && v <= r - p + 1)
    // {
    //     int n = r-p+1; // Number of elements in arr[l..r]

    //     // Divide arr[] in groups of size 5, calculate median
    //     // of every group and store it in median[] array.
    //     int i,b, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
    //     for (i=0; i<n/5; i++)
    //         median[i] = SortAndFindMedian(A+p+i*5, 5);
    //         printf("1\n");
    //         Display(median, 0, n);
    //     if (i*5 < n) //For last group with less than 5 elements
    //     {
    //         median[i] = SortAndFindMedian(A+p+i*5, n%5);
    //         printf("2\n");
    //         Display(median, 0, n);
    //         // Display(median,0,2);
    //         i++;
    //     }   
    //     printf("3\n");
    //     Display(median, 0, n);
    //     // Find median of all medians using recursive call.
    //     // If median[] has only one element, then no need
    //     // of recursive call
    //     printf("first A[0] %d A[1] %d i %d\n ", median[0],  median[1], i);
    //     Display(median, 0, n);
    //     int medOfMed = (i == 2)? median[i-2]:
    //                              Select(median, 0, i-1, i/2);
    //     printf("second");
    //     Display(median, 0, n);
    //     // Partition the array around a random element and
    //     // get position of pivot element in sorted array
        
    //     printf("medOfMed = %d i = %d\n", medOfMed, i);
    //     Display(A, 0, n);
    //     int q = MedianPartition(A, p, r, medOfMed);
    //     printf("pos - p = %d == %d k - 1 i = %d\n", q - p, b - 1, i);
        
    //     b = q - p + 1;

    //     printf("Partition returned q = %d k = q - p + 1 = %d\n",q, b);
    //     if (i + 1 == b) //added + 1
    //     {
    //         printf("i = k %d = %d return A[%d] = %d\n",i + 1, b, q, A[q]);
    //         return A[q]; 
    //     }
    //     else if (i < b)
    //     {
    //         printf("i < k, Recurse lower array %d < %d\n", i, b);
    //         Display(A, p, q + 1);
    //         return Select(A, p, q - 1, i);
    //     }
    //     else
    //     {
    //         printf("i > k, Recurse upper array %d > %d\n", i, b);
    //         Display(A, q + 1, r);
    //         return Select(A, q + 1, r, i - b);
    //     }    