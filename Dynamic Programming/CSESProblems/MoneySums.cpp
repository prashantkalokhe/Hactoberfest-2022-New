#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 100;
const int MAX_SUM = 1e5;
bool dp[MAXN + 1][MAX_SUM + 1];

int main()
{

	int n;
	cin >> n;

	vector<ll> a(n + 1, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	memset(dp, false, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= MAX_SUM; j++)
		{
			dp[i][j] = dp[i - 1][j];
			ll prev = j - a[i - 1];
			if ((prev >= 0) && (dp[i - 1][prev]))
				dp[i][j] = 1;
		}
	}
	vector<ll> ans;

	for (int i = 1; i <= MAX_SUM; i++)
	{
		if (dp[n][i])
			ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (auto v : ans)
	{
		cout << v << " ";
	}

	cout << endl;

	return 0;
}
