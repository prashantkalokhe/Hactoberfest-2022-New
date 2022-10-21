#include <iostream>
using namespace std;

int floorSqrt(int x)
{
	if (x == 0 || x == 1)
		return x;
	int st = 1, nd = x / 2, ans;
	while (st <= nd)
	{
		int mid = (st + nd) / 2;
		int sqr = mid * mid;
		if (sqr == x)
			return mid;
		if (sqr <= x)
		{
			st = mid + 1;
			ans = mid;
		}
		else
			nd = mid - 1;
	}
	return ans;
}

int main()
{
	int x = 11;
	cout << floorSqrt(x) << endl;
	return 0;
}