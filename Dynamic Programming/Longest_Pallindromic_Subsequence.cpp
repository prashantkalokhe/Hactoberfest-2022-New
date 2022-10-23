// Longest Palindromic Subsequence
// MediumAccuracy: 64.44%Submissions: 14059Points: 4
// Given a String, find the longest palindromic subsequence.

// Example 1:

// Input:
// S = "bbabcbcab"
// Output: 7
// Explanation: Subsequence "babcbab" is the
// longest subsequence which is also a palindrome.
// Example 2:

// Input:
// S = "abcd"
// Output: 1
// Explanation: "a", "b", "c" and "d" are
// palindromic and all have a length 1.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestPalinSubseq() which takes the string S as input and returns an integer denoting the length of the longest palindromic subsequence of S.

// Expected Time Complexity: O(|S|*|S|).
// Expected Auxiliary Space: O(|S|*|S|).

// Constraints:
// 1 ≤ |S| ≤ 1000
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int n, int m, string A, string B, vector<vector<int>> &dp)
    {
        if (n == 0 || m == 0)
        {
            return 0;
        }
        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }
        if (A[n - 1] == B[m - 1])
        {
            return dp[n][m] = 1 + solve(n - 1, m - 1, A, B, dp);
        }
        else
        {
            return dp[n][m] = max(solve(n - 1, m, A, B, dp), solve(n, m - 1, A, B, dp));
        }
    }
    int longestPalinSubseq(string A)
    {
        // code here

        int n = A.length();
        int m = n;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        string B = A;
        reverse(B.begin(), B.end());
        return solve(n, m, A, B, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends