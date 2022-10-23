// Count Palindromic Subsequences
// MediumAccuracy: 49.32%Submissions: 76922Points: 4
// Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.
// Note: You have to return the answer module 109+7;

// Example 1:

// Input:
// Str = "abcd"
// Output:
// 4
// Explanation:
// palindromic subsequence are : "a" ,"b", "c" ,"d"

// Example 2:

// Input:
// Str = "aab"
// Output:
// 4
// Explanation:
// palindromic subsequence are :"a", "a", "b", "aa"

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countPs() which takes a string str as input parameter and returns the number of palindromic subsequence.

// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(N*N).
//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete below method */
    long long int dp[1001][1001];
    long long int solve(int i, int j, string str)
    {
        long long int mod = 1e9 + 7;
        if (i > j)
        {
            return 0;
        }
        if (i == j)
        {
            return 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (str[i] == str[j])
        {
            return dp[i][j] = (1 + solve(i + 1, j, str) + solve(i, j - 1, str)) % mod;
        }
        else // minus as in abc  we split recursion on ab bc  so of b will be counted 2 times
        {
            return dp[i][j] = (solve(i + 1, j, str) + solve(i, j - 1, str) - solve(i + 1, j - 1, str) + mod) % mod;
        }
    }
    long long int countPS(string str)
    {
        // Your code here
        long long int n = str.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1, str);
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
}
// } Driver Code Ends