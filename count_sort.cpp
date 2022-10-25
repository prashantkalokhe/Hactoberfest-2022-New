#include<iostream>
using namespace std;

void CountingSort(int input_array[],int s, int r)
{
	int output_array[s];
	int count_arr[r];
	
	//initializing all elements to 0 in count array
	for(int i=0;i<r;i++)
		count_arr[i]=0;
		
	//take a count of all elements in input array
	for(int i=0;i<s;i++)
		++count_arr[input_array[i]];
	
	for(int i=1;i<r;i++)
		count_arr[i]=count_arr[i]+count_arr[i-1];
	
	for(int i=0;i<s;i++)
		output_array[--count_arr[input_array[i]]] = input_array[i];
	
	for(int i=0;i<s;i++)
		input_array[i]=output_array[i];
}

int main()
{
	int size=0;
	int range = 10;
	cout<<"Enter Size of array: "<<endl;
	cin>>size;
	int myarray[size];
	cout<<"Enter "<<size<<" integers in any order in range of 0-9: "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>myarray[i];
	}
	cout<<"Before Sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<myarray[i]<<" ";
	}
	cout<<endl;
	CountingSort(myarray,size,range);  
	cout<<"After Sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<myarray[i]<<" ";
	}
	return 0;
}
