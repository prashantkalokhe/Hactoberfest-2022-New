// Edit Distance
// Medium Accuracy: 49.98% Submissions: 66776 Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.
// Given two strings s and t. Return the minimum number of operations required to convert s to t.
// The possible operations are permitted:

// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.

// Example 1:

// Input:
// s = "geek", t = "gesek"
// Output: 1
// Explanation: One operation is required
// inserting 's' between two 'e's of str1.
// Example 2:

// Input :
// s = "gfg", t = "gfg"
// Output:
// 0
// Explanation: Both strings are same.

// Your Task:
// You don't need to read or print anything. Your task is to complete the function editDistance() which takes strings s and t as input parameters and returns the minimum number of operation to convert the string s to string t.

// Expected Time Complexity: O(|s|*|t|)
// Expected Space Complexity: O(|s|*|t|)

// Constraints:
// 1 ≤ Length of both strings ≤ 100
// Both the strings are in lowercase.
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int LCS(string &s, string &t, int m, int n, vector<vector<int>> &dp)
    {

        if (m == 0 && n == 0)
        {
            return 0;
        }
        //   eg: s=geeks t=geeksforgeeks
        if (m == 0 && n != 0)
        {
            return n;
        }
        //   eg: s=geeksforgeeks t=geeks
        if (m != 0 && n == 0)
        {
            return m;
        }
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        else
        {
            if (s[m - 1] == t[n - 1])
            {
                return dp[m][n] = LCS(s, t, m - 1, n - 1, dp);
            }
            else
            {
                return dp[m][n] = 1 + min(LCS(s, t, m - 1, n, dp), min(LCS(s, t, m, n - 1, dp), LCS(s, t, m - 1, n - 1, dp)));
            }
        }
    }
    int editDistance(string s, string t)
    {
        // Code here

        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int lcs = LCS(s, t, m, n, dp);

        return lcs;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends