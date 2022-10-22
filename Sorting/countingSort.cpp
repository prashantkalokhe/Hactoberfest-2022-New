#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int size, int range){
    int hasher[range];
    for (int i = 0; i < range; i++)
        hasher[i] = 0;

    for (int i = 0; i < size; i++)
        ++hasher[arr[i]];

    for (int i = 1; i < range; i++)
        hasher[i] += hasher[i - 1];

    int output[size];

    for (int i = size - 1; i >= 0; i--)
        output[--hasher[arr[i]]] = arr[i];

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

int main()
{
    printf("Enter The Range : ");
    int range;
    scanf("%d",&range);

    printf("Enter The Size of input Array : ");
    int size;
    scanf("%d",&size);

    int arr[size];
    printf("Enter the Elements : ");
    for (int i = 0; i < size; i++)
        scanf("%d",&arr[i]);

    countingSort(arr,size,range+1);

    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    

    return 0;
}