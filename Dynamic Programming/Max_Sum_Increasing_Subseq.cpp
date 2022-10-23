// Maximum sum increasing subsequence
// MediumAccuracy: 49.92%Submissions: 46124Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.

// Example 1:

// Input: N = 5, arr[] = {1, 101, 2, 3, 100}
// Output: 106
// Explanation:The maximum sum of a
// increasing sequence is obtained from
// {1, 2, 3, 100}
// Example 2:

// Input: N = 3, arr[] = {1, 2, 3}
// Output: 6
// Explanation:The maximum sum of a
// increasing sequence is obtained from
// {1, 2, 3}

// Your Task:
// You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N)
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int solve(int n, int lastidx, int a[], vector<vector<int>> &dp)
    {

        if (n < 0)
        {
            return 0;
        }
        if (dp[n][lastidx + 1] != -1)
        {
            return dp[n][lastidx + 1];
        }

        else
        {
            if (lastidx == -1)
            { // choice lena hai ki nai as iske pehle koi nai liya(lastidx=-1)
                return dp[n][lastidx + 1] = max(a[n] + solve(n - 1, n, a, dp), solve(n - 1, lastidx, a, dp));
            }
            else if (a[lastidx] > a[n])
            { // choice lena hai ki nai (already seq me lastidx liya hua hai so check element is less than lastidx ele)
                return dp[n][lastidx + 1] = max(a[n] + solve(n - 1, n, a, dp), solve(n - 1, lastidx, a, dp));
            }
            else
            { // nai lena matlab lastidx ab -1
                return dp[n][lastidx + 1] = solve(n - 1, lastidx, a, dp);
            }
        }
    }

    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n - 1, -1, arr, dp);
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends