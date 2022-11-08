#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e6 + 2;

ll dp[N + 1][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dp, 0, sizeof(dp));
	dp[1][0] = dp[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{

		ll o1 = 0, o2 = 0, o3 = 0, o4 = 0;
		o2 = dp[i - 1][0];
		o3 = (2 * dp[i - 1][0]) % MOD;
		o1 = dp[i - 1][0] + dp[i - 1][1];
		o4 = dp[i - 1][1];
		dp[i][0] = ((o1 + o2) % MOD + o3) % MOD;

		dp[i][1] = (o1 + o4) % MOD;
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		ll ans = (dp[n][0] + dp[n][1]) % MOD;

		cout << ans << '\n';
	}
	return 0;
}