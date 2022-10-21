#include <iostream>
using namespace std;

void printDivisors(int num)
{
	for (int i = 1; i <= num; i++)
		if (num % i == 0)
			cout <<" " << i;
}

int main()
{
	cout <<"The divisors of 100 are: \n";
	printDivisors(100);
	return 0;
}

