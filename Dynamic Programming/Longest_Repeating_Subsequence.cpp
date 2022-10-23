// Longest Repeating Subsequence
// Easy Accuracy: 50.4% Submissions: 50609 Points: 2
// Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

// The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

// Example 1:

// Input:
// str = "axxzxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x z x y
// 0 1 2 3 4 5

// The longest subsequence is "xx".
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str

// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 4  <-- index of str

// We are able to use character 'x'
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A
// and index 0 in subsequence B.
// Example 2:

// Input:
// str = "axxxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x x y
// 0 1 2 3 4

// The longest subsequence is "xx".
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str

// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 3  <-- index of str

// We are able to use character 'x'
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A
// and index 0 in subsequence B.

// Your Task:
// You don't need to read or print anything. Your task is to complete the LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.

// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n2)
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // 	int solve(string str,string str2,int m,int n,vector<vector<int>> &dp){
    // 	    if(m==0||n==0){
    // 	        return 0;
    // 	    }
    // 	    if(dp[m][n]!=-1){
    // 	        return dp[m][n];
    // 	    }
    // 	    else{
    // 	        if(str[m-1]==str2[n-1]&&m!=n){
    // 	            return dp[m][n]=1+solve(str,str2,m-1,n-1,dp);
    // 	        }
    // 	        else{
    // 	            return dp[m][n]=max(solve(str,str2,m-1,n,dp),solve(str,str2,m,n-1,dp));
    // 	        }
    // 	    }
    // 	}
    int LongestRepeatingSubsequence(string str)
    {
        // Code here

        string str2 = str;
        int n = str.length();
        int m;
        m = n;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        //  return solve(str,str2,m,n,dp);
        // int dp[m+1][n+1];
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (str[i - 1] == str2[j - 1] && i != j)
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends