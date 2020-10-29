

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
// Swap utility 
void swap(long int* a, long int* b) 
{ 
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 
  
void selectionSort(long int arr[], long int n) 
{ 
    long int i, j, midx; 
  
    for (i = 0; i < n - 1; i++) { 
  
        // Find the minimum element in unsorted array 
        midx = i; 
  
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[midx]) 
                midx = j; 
  
        // Swap the found minimum element 
        // with the first element 
        swap(&arr[midx], &arr[i]); 
    } 
} 
int main() 
{ 
    long int n = 10000; 
    int it = 0;
    double  tim3[10];

    while (it++ < 10) { 
        long int  c[n]; 
  
        // generating n random numbers 
        // storing them in arrays a, b, c 
        for (int i = 0; i < n; i++) { 
            long int no = rand() % n + 1;  
            c[i] = no; 
        } 
        // using clock_t to store time 
    clock_t start,end;
	  double cpu_time_used;
	  start=clock();
  	selectionSort(c,n);
	  end=clock();
	
	  tim3[it]= ((double)(end-start));
     printf("%li, %li\n", 
               n,  
               (long int)tim3[it]); 
  
        // increases the size of array by 10000 
        n += 10000; 
    } 
  
    return 0; 
} 
