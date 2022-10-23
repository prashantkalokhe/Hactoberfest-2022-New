// Egg Dropping Puzzle
// MediumAccuracy: 54.38%Submissions: 50940Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// You are given N identical eggs and you have access to a K-floored building from 1 to K.

// There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below.

// An egg that survives a fall can be used again.
// A broken egg must be discarded.
// The effect of a fall is the same for all eggs.
// If the egg doesn't break at a certain floor, it will not break at any floor below.
// If the eggs breaks at a certain floor, it will break at any floor above.
// Return the minimum number of moves that you need to determine with certainty what the value of f is.

// For more description on this problem see wiki page

// Example 1:

// Input:
// N = 1, K = 2
// Output: 2
// Explanation:
// 1. Drop the egg from floor 1. If it
//    breaks, we know that f = 0.
// 2. Otherwise, drop the egg from floor 2.
//    If it breaks, we know that f = 1.
// 3. If it does not break, then we know f = 2.
// 4. Hence, we need at minimum 2 moves to
//    determine with certainty what the value of f is.
// Example 2:

// Input:
// N = 2, K = 10
// Output: 4
// Your Task:
// Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order to find the critical floor.

// Expected Time Complexity : O(N*(K^2))
// Expected Auxiliary Space: O(N*K)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int solve(int n, int f, vector<vector<int>> &dp)
    {
        if (n == 1)
        {
            return f;
        }
        if (f == 0 || f == 1)
        {
            return 1;
        }
        if (dp[n][f] != -1)
        {
            return dp[n][f];
        }
        int mn = INT_MAX;
        for (int k = 1; k < f; k++)
        { // break hoga or nai hoga worst case so max and min of that ans
            int tempans = 1 + max(solve(n - 1, k - 1, dp), solve(n, f - k, dp));
            mn = min(mn, tempans);
        }
        return dp[n][f] = mn;
    }
    int eggDrop(int n, int f)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(f + 1, -1));
        return solve(n, f, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends