#include <iostream>
using namespace std;
int main ()
{
	int num[6]={4,7,5,9,2,3};
	int large=num[0];
	for (int i=1;i<6;i++)
	{
		if (large<num[i])
		{
			large=num[i];
		}
	}
	cout<<"largest number is"<<large;
}