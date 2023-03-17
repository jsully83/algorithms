#include <iostream>
#include <stdio.h>
#include <time.h>

void print_vector(int *arr, int begin, int n)
{
    int i;
    std::cout << "Vector: ";
    for (i = begin; i <= n; i++)
    {
        std::cout << " " << arr[i];
    }
    std::cout << "\n" <<std::endl;
}


void merge(int *A, int begin, int mid, int end)
{
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    int L[n1];
    int R[n1];

    for (int i = 0; i < n1; i++)
        L[i] = A[begin + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + j + 1];    
        int i = 0;
        int j = 0;
        int k = begin;
        while (i < n1 && j <n2)
        {
            if (L[i] <= R[j])
            {
                A[k] = L[i];
                i++;
            }else
            {
                A[k] = R[j];
                j++;
            }
            k++;
        }    
        while (i < n1) 
        { 
            A[k] = L[i]; 
            i++; 
            k++;
        } 
        while (j < n2) 
        { 
            A[k] = R[j]; 
            j++; 
            k++;
        }            
}

void merge_sort(int* A, int begin, int end)
{
    // std::cout << "Merge Sorting: ";
    // print_vector(A, begin, end);
    if(begin != end)
    {
        int mid = (begin + end) / 2;
        merge_sort(A, begin, mid);
        merge_sort(A, mid + 1, end);
        merge(A, begin, mid, end);
    }
}



int main()
{
    int A[200] = {0};
    int val = 200;


    for (int i = 0; i < val; i++)
    {
        for (int p = 0; p < val; p++)
        {
            A[p] = val - p;
        }
        
        
        print_vector(A, 0, i);
        clock_t start = clock();
        merge_sort(A, 0, i);
        clock_t end = clock();
        printf ("Merge Sort Sorted the i = %d ", i);
        print_vector(A, 0, i);
        double cpu_time_used = ((double) (end - start))  / CLOCKS_PER_SEC;
        printf("Sorting took %f seconds to execute \n", cpu_time_used);
    }

    return 0;
}