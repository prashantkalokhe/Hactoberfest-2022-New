#include <bits/stdc++.h>
using namespace std;

void heap(vector<int> &A, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && A[l] > A[largest])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        int t = A[i];
        A[i] = A[largest];
        A[largest] = t;
        heap(A, n, largest);
    }
}
void sort(vector<int> &A, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(A, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        int t = A[0];
        A[0] = A[i];
        A[i] = t;
        heap(A, i, 0);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int> A(n);
    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin>>A[i];
    sort(A, n);
    cout<<"Sorted array: ";
    for (int i = 0; i < n; i++)
       cout<<A[i]<<" ";
        
    return 0;    
}

