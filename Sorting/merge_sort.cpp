#include <bits/stdc++.h>
using namespace std;
void print(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}
void merge(int arr[], int s, int m, int e)
{
  int a = m - s + 1;
  int b = e - m;
  int *arr1 = new int[a];
  int *arr2 = new int[b];
  for (int i = 0; i < a; i++)
  {
    arr1[i] = arr[s + i];
  }
  for (int j = 0; j < b; j++)
  {
    arr2[j] = arr[m + 1 + j];
  }
  int i = 0, j = 0, k = s;
  while (i < a && j < b)
  {
    if (arr1[i] <= arr2[j])
    {
      arr[k] = arr1[i];
      i++;
    }
    else
    {
      arr[k] = arr2[j];
      j++;
    }
    k++;
  }

  while (i < a)
  {
    arr[k] = arr1[i];
    i++;
    k++;
  }
  while (i < b)
  {
   arr[k] = arr2[j];
      j++;
      k++;
  }
}

void mergesort(int arr[], int s, int e)
{
  if (s >= e)
  {
    return;
  }
  int m = s + (e - s) / 2;
  mergesort(arr, s, m);
  mergesort(arr, m + 1, e);
  merge(arr, s, m, e);
}
int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  mergesort(arr, 0, 5);
  print(arr,6);
  return 0;
}
