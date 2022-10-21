#include <iostream>
using namespace std;
int main ()
{
	int num[6]={4,7,5,9,2,3};
	int small=num[0];
	for (int i=1;i<6;i++)
	{
		if (small>num[i])
		{
			small=num[i];
		}
	}
	cout<<"smallest number is"<<small;
}