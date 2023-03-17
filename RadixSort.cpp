#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <vector>


void Swap(int* A, int index1, int index2)
{
    int temp = A[index1];
    A[index1] = A[index2];
    A[index2] = temp;
}

void display(int *a, size_t size)
{
	for(int i=0;i<size;++i) {
		std::cout << a[i] << "\t";
	}
	std::cout << std::endl;
}

void DisplayVector(std::vector<int> arr)
{

    for (std::vector<int>::const_iterator i = arr.begin(); i != arr.end(); ++i)
        std::cout << *i << ' ';
}


// void CountingSort(int* A,int* B, int k, int all_numb, int allB)
// {
   
//     int C[21] = {0};
    

//     for (int i = 0; i <= k; i++) { C[i] = 0; }

//     for (int j = 0; j < 11; j++)
//     {
//         C[A[j]] = C[A[j]] + 1;        
//     }

//     for (int l = 1; l < k; l++)
//     {
//         C[l] = C[l] + C[l - 1];
//     }

//     for (int m = 11 - 1; m > -1 ; m--)
//     {
//         B[C[A[m]] - 1] = A[m];
//         allB[C[A[m]] - 1] = all_numb[m];
//         C[A[m]] = C[A[m]] - 1;
//         display(B, 11);
        
//     }
// }



void extractDigits(int x, std::vector<int> *arr)
{
    if(x >= 10)
       extractDigits(x / 10, arr);

    arr->push_back(x % 10);
}


// void RadixSort(A, d)
// {
//     int A[];
//     int B1[];
//     int B2[];

//     for (int i = 0; i < d; i++)
//     {
//         countingSort(a_digit[], B1, )
//     }
// }




int main()
{
    // int A[9] = {2, 5, 3, 0, 2, 3, 0, 3, 6};
    // int A[11] = {20, 18, 5, 7, 16, 10, 9, 3, 12, 14, 0 };
    int B[11] = {0};
    
    int A[] = {329, 457, 657, 839, 436, 720, 353};
    int g = sizeof(A)/sizeof(A[0]);
    std::vector<int> digits;

    for (int i = 0; i < g; i++)
    {
        extractDigits(A[i], &digits);
        
    }
    DisplayVector(digits);
    
    int firsts[7];
    int seconds[7];
    int thirds[7];

    int j = 0;
    for (int i = 0; i < 7; i++)
    {
        firsts[j] = digits[i + 2*i];
        seconds[j] = digits[i+1];
        thirds[j] = digits[i];
        j++;

    }
    display(firsts,7);
    


    // display(A,11);
    // CountingSort(A, B, 21);
    // printf("done\n");
    // display(B, 11);



}