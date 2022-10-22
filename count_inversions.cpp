//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    
    long long int inversion&merge(long long int arr[],long long int lb,long long int mid,long long int ub )
    {
        long long  n1=(mid-lb+1);
        long long  n2=(ub-mid);
        long long  a[n1],b[n2];
        for(long long i=0;i<n1;i++)
        a[i]=arr[lb+i];
        for(long long i=0;i<n2;i++)
        b[i]=arr[mid+i+1];
        long long int res=0;
        long long  i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(a[i]<=b[j])
            {
                i++;
            }
            else
            {
                res+=n1-i+1;
                j++;
            }
        }
        return res;
    } 
    long long int inversion(long long  arr[],long long N,long long int lb,long long int ub)
    {
        long long int count=0;
        if(lb<ub)
        {
            long long  mid=(lb+ub)>>1;
            count+=inversion(arr,N,lb,mid);
            count+=inversion(arr,N,mid+1,ub);
            count+=inversion&merge(arr,lb,mid,ub);
        }
        return count;
    }
   
    long long int inversionCount(long long arr[], long long N)
    
    {
        // Your Code Hereb[]
        return inversion(arr,N,0,N-1);
    }
    

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
