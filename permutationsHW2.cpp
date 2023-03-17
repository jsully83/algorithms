#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

void display(int *a, int size) {
	for(int i=0;i<size;++i) {
		std::cout << *(a+i) << "\t";
	}
	std::cout << std::endl;
}


void swap (int *a, int index1, int index2)
{
	int temp = a[index1];
	a[index1] = a[index2];
	a[index2] = temp;
}
int main() {

  	//this prints all the possible arrangements of an array
  	//just use 'next_permutation' function in the array
	srand((unsigned int)time(NULL));

	int length = 100;
	int a[100] = {0};
    for (int i = 0; i < length; i++)
    {
        a[i] = length - i;
    }
	
	for (int i = 0; i < length; i++)
	{
		swap(a, i, rand() % 100 + 1);
	}
	


    display(a, length);
    
    // do {
	// 	std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
	//  } while(std::next_permutation(a, a+3));



}