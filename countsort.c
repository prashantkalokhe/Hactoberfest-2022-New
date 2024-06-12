#include <stdio.h>
#include <limits.h>
#include<stdlib.h>
int maximum(int A[], int n)
{
    int max = INT_MIN;
    int i = 0;
    while(i<n)
    {
        if(A[i]>max)
        {
        max = A[i];
        }
        i++;
    }
    return max;
}

void count_sort(int *A, int n) // time-complexity--> O(m+n) // for big size array O(n) max is almost negligible compared to size of array // where m is the number of elements in the array and n is the range of the elements. Counting sort is most efficient if the range of input values is not greater than the number of values to be sorted.  //space complexity--> O(max+1) 

{
    // find the maximum element in the array
    int max = maximum(A, n);
    int*count = (int*)calloc(sizeof(int),max+1); // automatically initialize to 0

    // incrementing the corresponding index by 1
    for(int i = 0; i<n; i++)
    {
        count[A[i]]++;
    }

    int j = 0; // traverse count array
    int i = 0; // traverse original array
    while(j<max+1)
    {
        if(count[j]>0)
        {
            A[i] = j;
            count[j]--;
            i++;
        }
        else
            j++;
    }

}
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {33, 45, 22, 5, 42, 1, 3, 7, 50, 2, 2, 45, 231, 89};
//index --> 0 1 2 3 4 5 6
//element-- 3 1 9 7 1 2 4 // max = 9

// index --> 0 1 2 3 4 5 6 7 8 9 // size = 10
// count --> 0 2 1 1 1 0 0 1 0 1 // count of element

// index --> 0 1 2 3 4 5 6
// element-- 1 1 2 3 4 7 9 (Sorted) // same array
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    count_sort(arr,size);
    printArray(arr, size);
}