/*
PROBLEM STATEMENT : 
Write a function template selection Sort. Write a program that inputs, sorts and outputs an
integer array and a float array.
*/
#include<iostream>
using namespace std;
template<class T>
void bubble_sort(T a[10]){
int i,j;
for(i=1;i<10;i++){
 for(j=0;j<10-i;j++){
  if(a[j]>a[j+1]){
    T temp;
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
    }
  }
 }
}

template<class T>
void selection_sort(T a[10]){
int i,j,min;
T temp;
for(i=0;i<9;i++){
  min=i;
 for(j=i+1;j<10;j++){
   if(a[j]<a[min])
    min=j;
   }
temp=a[i];
a[i]=a[min];
a[min]=temp;
 }
}

int main(){
int a[10];
float b[10];
int ch;
do{
cout<<"\n1.BUBBLE SORT\n2.SELECTION SORT\n3.EXIT\nEnter Your Choice : ";
cin>>ch;
switch(ch){
case 1 : cout<<"\nEnter 10 integer type digits : ";
         for(int i=0;i<10;i++)
	    cin>>a[i];
         bubble_sort<int>(a);
         cout<<"\n**********Sorted Order Integers**********"<<endl;
         for(int i=0;i<10;i++)
         cout<<a[i]<<"\t";
         
         cout<<"\nEnter 10 float type digits : ";
         for(int i=0;i<10;i++)
	    cin>>b[i];
         bubble_sort<float>(b);
         cout<<"\n**********Sorted Order Float Values**********"<<endl;
         for(int j=0;j<10;j++)
         cout<<b[j]<<"\t";
         break;
case 2 : cout<<"\nEnter 10 integer type digits : ";
         for(int i=0;i<10;i++)
	    cin>>a[i];
         selection_sort<int>(a);
         cout<<"\n**********Sorted Order Integers**********"<<endl;
         for(int i=0;i<10;i++)
         cout<<a[i]<<"\t";
        
         cout<<"\nEnter 10 float type digits : ";
         for(int i=0;i<10;i++)
	    cin>>b[i];
         selection_sort<float>(b);
         cout<<"\n**********Sorted Order Float Values**********"<<endl;
         for(int j=0;j<10;j++)
         cout<<b[j]<<"\t";
         break;
case 3 : cout<<"\n***********EXIT***********";
   }
  }while(ch!=3);
return 0;
}  
/*
OUTPUT : 
1.BUBBLE SORT
2.SELECTION SORT
3.EXIT
Enter Your Choice : 1

Enter 10 integer type digits : 45
34
76
56
98
78
66
09
11
23

**********Sorted Order Integers**********
9	11	23	34	45	56	66	76	78	98	
Enter 10 float type digits : 9.0
9
8.7
7.7
7.5
6.8
3.5
1.34
44.5
32.5

**********Sorted Order Float Values**********
1.34	3.5	6.8	7.5	7.7	8.7	9	9	32.5	44.5	
1.BUBBLE SORT
2.SELECTION SORT
3.EXIT
Enter Your Choice : 2

Enter 10 integer type digits : 0
9
67
87
45
32
56
12
34
555

**********Sorted Order Integers**********
0	9	12	32	34	45	56	67	87	555	
Enter 10 float type digits : 1.3
6.78
45.76
34.6
22.45
999.7
48.0
21.0
67.7
45.7

**********Sorted Order Float Values**********
1.3	6.78	21	22.45	34.6	45.7	45.76	48	67.7	999.7	
1.BUBBLE SORT
2.SELECTION SORT
3.EXIT
*/
          
