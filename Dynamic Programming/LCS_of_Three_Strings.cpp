// LCS of three strings
// Medium Accuracy: 54.38% Submissions: 19657 Points: 4
// Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

// Example 1:

// Input:
// A = "geeks", B = "geeksfor",
// C = "geeksforgeeks"
// Output: 5
// Explanation: "geeks"is the longest common
// subsequence with length 5.
// â€‹Example 2:

// Input:
// A = "abcd", B = "efgh", C = "ijkl"
// Output: 0
// Explanation: There's no common subsequence
// in all the strings.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common subsequence in all the 3 strings.

// Expected Time Complexity: O(n1*n2*n3).
// Expected Auxiliary Space: O(n1*n2*n3).
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int LCSof3(string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        string A, B, C;
        cin >> A >> B >> C;
        cout << LCSof3(A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int dp[21][21][21];
int solve(string s1, string s2, string s3, int n1, int n2, int n3)
{
    if (n1 == 0 || n2 == 0 || n3 == 0)
    {
        return 0;
    }
    if (dp[n1][n2][n3] != -1)
    {
        return dp[n1][n2][n3];
    }
    if ((s1[n1 - 1] == s2[n2 - 1]) && (s2[n2 - 1] == s3[n3 - 1]))
    {
        return dp[n1][n2][n3] = 1 + solve(s1, s2, s3, n1 - 1, n2 - 1, n3 - 1);
    }
    else
    {
        int a = solve(s1, s2, s3, n1 - 1, n2, n3);
        int b = solve(s1, s2, s3, n1, n2 - 1, n3);
        int c = solve(s1, s2, s3, n1, n2, n3 - 1);
        return dp[n1][n2][n3] = max(a, max(b, c));
    }
}
int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    memset(dp, -1, sizeof(dp));
    return solve(A, B, C, n1, n2, n3);
}