#include <iostream>
using namespace std;
class sort
{
	float a[100],b[100];
	int n,i,j;
public:
	void enter();
	void display();
	void selection();
	void bubblesort();
	void dispbubble();
};
void sort::enter()
{
	cout<<"Enter the number of students whose percentage is to be stored: ";
	cin>>n;
	cout<<endl;
	cout<<"Enter the percentage of students:\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		cout<<endl;
	}
}
void sort::display()
{
	cout<<"\nThe list of scores you entered are as follows:\n";
	for(i=0;i<n;i++)
	{
		cout<<b[i]<<"\n\n";
	}
}
void sort::selection()
{
	int pos;
	float min,temp;
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(min>a[j])
			{
				min=a[j];
				pos=j;
			}
		}
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
	}
	cout<<"\nThe list of scores in ascending order using Selection Sort is as follows:\n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\n\n";
		a[i]=b[i];
	}
}
void sort::bubblesort()
{
	float temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void sort::dispbubble()
{
	cout<<"\nThe list of scores in ascending order using Bubble sort is as follows:\n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\n\n";
		a[i]=b[i];
	}
}


int main()
{
	sort obj;
	int ch,i;
	do
	{

		cout<<endl;
		cout<<"Choose the operation to be performed:"
			  "\n1.Enter the percentage of students."
			  "\n2.Display the scores in the format the user entered them."
			  "\n3.Display the scores in ascending order using Bubble sort."
			  "\n4.Display the scores in ascending order using Selection Sort."
			  "\n5.Exit.\n";

		cout<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:obj.enter();
		break;
		case 2:obj.display();
		break;
		case 3:obj.bubblesort();
		obj.dispbubble();
		break;
		case 4:obj.selection();
		break;
		case 5:break;
		default: cout<<"Enter a valid choice.";
		break;
		}
	}while(ch!=5);
	return 0;
}


/* OUTPUT

Choose the operation to be performed:
1.Enter the percentage of students.
2.Display the scores in the format the user entered them.
3.Display the scores in ascending order using Bubble sort.
4.Display the scores in ascending order using Selection Sort.
5.Exit.

1
Enter the number of students whose percentage is to be stored: 3

Enter the percentage of students:
80

90

75


Choose the operation to be performed:
1.Enter the percentage of students.
2.Display the scores in the format the user entered them.
3.Display the scores in ascending order using Bubble sort.
4.Display the scores in ascending order using Selection Sort.
5.Exit.

2

The list of scores you entered are as follows:
80

90

75


Choose the operation to be performed:
1.Enter the percentage of students.
2.Display the scores in the format the user entered them.
3.Display the scores in ascending order using Bubble sort.
4.Display the scores in ascending order using Selection Sort.
5.Exit.

3

The list of scores in ascending order using Bubblesort is as follows:
75

80

90


Choose the operation to be performed:
1.Enter the percentage of students.
2.Display the scores in the format the user entered them.
3.Display the scores in ascending order using Bubble sort.
4.Display the scores in ascending order using Selection Sort.
5.Exit.

4

The list of scores in ascending order using Selection Sort is as follows:
75

80

90


Choose the operation to be performed:
1.Enter the percentage of students.
2.Display the scores in the format the user entered them.
3.Display the scores in ascending order using Bubble sort.
4.Display the scores in ascending order using Selection Sort.
5.Exit.
5
 */
