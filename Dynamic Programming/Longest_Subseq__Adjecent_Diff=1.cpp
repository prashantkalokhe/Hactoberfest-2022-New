// Longest subsequence-1
// Easy Accuracy: 49.96% Submissions: 22517 Points: 2
// Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.

// Example 1:

// Input: N = 7
// A[] = {10, 9, 4, 5, 4, 8, 6}
// Output: 3
// Explaination: The three possible subsequences
// {10, 9, 8} , {4, 5, 4} and {4, 5, 6}.

// Example 2:

// Input: N = 5
// A[] = {1, 2, 3, 4, 5}
// Output: 5
// Explaination: All the elements can be
// included in the subsequence.

// Your Task:
// You do not need to read input. Your task is to complete the function longestSubseq() which takes N and A[] as input parameters and returns the length of the longest such subsequence.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N)
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int N, int A[], int i, vector<vector<int>> &dp)
    {
        if (N < 0)
        {
            return 0;
        }
        if (dp[N][i + 1] != -1)
        {
            return dp[N][i + 1];
        }
        else
        {
            if (i == -1)
            {
                return dp[N][i + 1] = max(1 + solve(N - 1, A, N, dp), solve(N - 1, A, i, dp));
            }
            else if (abs(A[i] - A[N]) == 1)
            {
                return dp[N][i + 1] = max(1 + solve(N - 1, A, N, dp), solve(N - 1, A, i, dp));
            }
            else
            {
                return dp[N][i + 1] = solve(N - 1, A, i, dp);
            }
        }
    }
    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        return solve(N - 1, A, -1, dp);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.longestSubsequence(N, A) << endl;
    }
    return 0;
} // } Driver Code Ends