#include<iostream>
#include<conio.h>
using namespace std;

int binary(int a[],int n,int item)
{
    int beg,end,mid;
    beg = 0;
    end = n-1;

    while(beg <= end)
    {
        mid = (beg+end)/2;
        if(a[mid]==item)
        {
            cout << item << " found in position "<<mid+1<<endl;
            return 0;
        }
        else if(item < a[mid])
        {
            end = mid-1;
        }
        else
        {
            beg = mid+1;
        }
    }
    cout << item << " not found in array!!"<<endl;
}

int main()
{
    int a[100];
    int i,n,item;

    cout << "Enter size of array: ";
    cin>>n;

    cout << "(Note: enter value in increasing order)\nEnter values of array:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout << "Enter value for search: ";
    cin>>item;

    binary(a,n,item);

    return 0;
}
