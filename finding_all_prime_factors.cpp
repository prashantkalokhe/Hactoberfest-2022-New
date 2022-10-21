#include <bits/stdc++.h>
using namespace std;

void primeFactors(long n)
{
	vector<long> v;
	for (long i = 2; i * i <= (n); i++)
	{
		while (n % i == 0)
		{
			v.push_back(i);
			n /= i;
		}
	}
	if (n > 1)
	{
		v.push_back(n);
	}
	for (long prime : v)
	{
		cout << prime << " ";
	}
}

int main()
{
	long n;
	cin >> n;
	primeFactors(n);
	return 0;
}
