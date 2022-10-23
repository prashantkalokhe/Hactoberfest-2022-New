// nCr
// Medium Accuracy: 32.71% Submissions: 83906 Points: 4
// Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

// Example 1:

// Input: n = 3, r = 2
// Output: 3
// Explaination: 3C2 = 3.

// Example 2:

// Input: n = 2, r = 4
// Output: 0
// Explaination: r is greater than n.

// Your Task:
// You do not need to take input or print anything. Your task is to complete the function nCr() which takes n and r as input parameters and returns nCr modulo 109+7..

// Expected Time Complexity: O(n*r)
// Expected Auxiliary Space: O(r)

// Constraints:
// 1 ≤ n ≤ 1000
// 1 ≤ r ≤ 800
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int n, int r, vector<vector<long long>> &dp)
    {
        int mod = 1000000007;
        if (r > n)
        {
            return 0;
        }
        if (n == r || r == 0)
        {
            return 1;
        }
        if (dp[n][r] != -1)
        {
            return dp[n][r];
        }

        dp[n][r] = (solve(n - 1, r, dp) + solve(n - 1, r - 1, dp)) % mod; // u take item or u dont
        return dp[n][r];
    }
    int nCr(int n, int r)
    {
        // code here
        // ncr means u have choice to take r items out of n items therefore dp
        vector<vector<long long>> dp(n + 1, vector<long long>(r + 1, -1));

        return solve(n, r, dp);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
} // } Driver Code Ends