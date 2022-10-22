#include <stdio.h>
using namespace std;
void recursiveInsertionSort(int arr[], int n){
   if (n <= 1)
      return;
   recursiveInsertionSort( arr, n-1 );
   int nth = arr[n-1];
   int j = n-2;
   while (j >= 0 && arr[j] > nth){
      arr[j+1] = arr[j];
      j--;
   }
   arr[j+1] = nth;
}
int main(){
  int n;
  cout<<"Enter number of elements: ";
  cin>>n;
   int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
   int n = sizeof(array)/sizeof(array[0]);
cout<<"\nUnsorted Array:";
  for (int i=0; i < n; i++)
   cout<<array[i]<<endl;
  recursiveInsertionSort(array, n);
  cout<<"\nSorted Array:\t";
   for (int i=0; i < n; i++)
      cout<<arr[i]<<endl;
   return 0;
}
