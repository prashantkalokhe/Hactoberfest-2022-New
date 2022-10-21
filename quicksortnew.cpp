
#include<iostream>
using namespace std;
void quick_sort(float a[20],int l,int u);
int partition(float a[20],int l,int u);
int main()
{
	float a[20];
	int n,i;
	cout<<"Enter the No. of students:"<<endl;
	cin>>n;
	cout<<"Enter marks:"<<endl;

	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Marks of students"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	quick_sort(a,0,n-1);
	cout<<"Sorted List"<<endl;
	cout<<"BEST 5 marks"<<endl;
	for(int i=n-1;i>=n-5;i--)
	{
		cout<<a[i]<<endl;
	}
}
void quick_sort(float a[20],int l,int u)
{
	int j;
	if(l<u)
	{
		j=partition(a,l,u);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}

}
int partition(float a[20],int l,int u)
{
    int i,j;
    float v,temp;
    v=a[l];
    i=l;
    j=u+1;
    do
    {
	   do
	    {	i++;
	    }while(a[i]<=v && i<=u);

	    do
	    {	j--;
	    }while(a[j]>v);
        if(i<j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
  }while(i<j);

  a[l]=a[j];
  a[j]=v;
  return(j);
}
/*OUTPUT
 * Enter the No. of students:
3
Enter marks:
58
10
98
Marks of students
Sorted List
58
10
98
Sorted List
BEST 5 marks
98
58
10

 *
 */
