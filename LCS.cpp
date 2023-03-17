#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
using namespace std;

int max(int a, int b) {return (a > b) ? a:b;}


int lcs(char* x, char*  y, int i, int j)
{     
    if (i == 0 || j == 0) return 0;
    
    if (x[i] == y[j]) return 1 + lcs(x, y, i-1, j-1);
    else return max(lcs(x, y, i, j-1), lcs(x, y, i-1, j));
}


int main()
{

    char A[] = "ACCGGTCGA";
    char B[] = "GTCGTTCGG";

    int i = strlen(A);
    int j = strlen(B);
    int length;
 

    length = lcs(A, B, i, j);
    
    printf("LCS  = %d", length);


return 0;
}

