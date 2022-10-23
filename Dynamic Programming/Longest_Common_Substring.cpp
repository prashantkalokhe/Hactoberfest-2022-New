// Longest Common Substring
// Medium Accuracy: 52.09% Submissions: 60219 Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.
// Given two strings. The task is to find the length of the longest common substring.

// Example 1:

// Input: S1 = "ABCDGH", S2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring
// is "CDGH" which has length 4.
// Example 2:

// Input: S1 = "ABC", S2 "ACB"
// Output: 1
// Explanation: The longest common substrings
// are "A", "B", "C" all having length 1.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.

// Expected Time Complexity: O(n*m).
// Expected Auxiliary Space: O(n*m).

// Constraints:
// 1<=n, m<=1000
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // int solve(string S1,string S2,int n,int m){
    //     if(n==0||m==0){
    //         return 0;
    //     }
    //     else{
    //         if(S1[n-1]==S2[m-1]){
    //             return 1+solve(S1,S2,n-1,m-1);
    //         }
    //         else{
    //             return 0;
    //         }
    //     }
    // }
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        if (ans < 0)
        {
            return 0;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends