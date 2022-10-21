#include <bits/stdc++.h>
using namespace std;

long fibonacci(long n)
{
	if ((n == 1) || (n == 2))
	{
		return (n - 1);
	}
	else
	{
		return (fibonacci(n - 1) + fibonacci(n - 2));
	}
}

int main()
{
	long n;
	cout << "Enter the size of series you want: ";
	cin >> n;
	for (long i = 1; i <= n; i++)
	{
		cout << fibonacci(i) << " ";
	}
	return 0;
}
