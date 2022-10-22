//merge sort algorithm
#include<iostream>
using namespace std;
int merge1(int *arr, int l, int h)
{
    int mid = (l+h)/2;
    int len1 = mid - l + 1;
    int len2 = h - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int mainindex = l;
    for(int i=0;i<len1;i++)
    {
        first[i] = arr[mainindex];
        mainindex++;
    }
    mainindex = mid + 1;
    for(int i=0;i<len2;i++)
    {
        second[i] = arr[mainindex];
        mainindex++;
    }
    int i=0,j=0;
    mainindex = l;
    while(i<len1 && j<len2)
    {
        if(first[i]<second[j])
        {
            arr[mainindex++] = first[i++];
        }
        else
        {
            arr[mainindex++] = second[j++];
        }
    }
    while(i<len1)
    {
        arr[mainindex++] = first[i++];
    }
    while(j<len2)
    {
        arr[mainindex++] = second[j++];
    }
}
int mergesort(int *arr, int l, int h)
{
    if(l>=h)
    {
        return NULL;
    }
    int mid = (l+h)/2;
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, h);
    merge1(arr,l,h);

}

int main()
{
    int arr[8] = {4,5,2,1,3,4,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr, 0, n-1);
    cout<<"Sorted Array=";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
