// Longest Common Subsequence
// Medium Accuracy: 49.98% Submissions: 83830 Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.
// Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

// Example 1:

// Input:
// A = 6, B = 6
// str1 = ABCDGH
// str2 = AEDFHR
// Output: 3
// Explanation: LCS for input Sequences
// “ABCDGH” and “AEDFHR” is “ADH” of
// length 3.
// Example 2:

// Input:
// A = 3, B = 2
// str1 = ABC
// str2 = AC
// Output: 2
// Explanation: LCS of "ABC" and "AC" is
// "AC" of length 2.
// Your Task:
// Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

// Expected Time Complexity : O(|str1|*|str2|)
// Expected Auxiliary Space: O(|str1|*|str2|)

// Constraints:
// 1<=size(str1),size(str2)<=103
// { Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int solve(int x, int y, string s1, string s2, vector<vector<int>> &dp)
    {
        if (x == 0 || y == 0)
        {
            return 0;
        }
        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }
        else
        {
            if (s1[x - 1] == s2[y - 1])
            {
                return dp[x][y] = 1 + solve(x - 1, y - 1, s1, s2, dp);
            }
            else
            {
                return dp[x][y] = max(solve(x, y - 1, s1, s2, dp), solve(x - 1, y, s1, s2, dp));
            }
        }
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        return solve(x, y, s1, s2, dp);
    }
};

// { Driver Code Starts.
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends