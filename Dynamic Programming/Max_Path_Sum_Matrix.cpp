// /
// Maximum path sum in matrix
// MediumAccuracy: 50.83%Submissions: 34009Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

// Matrix [r+1] [c]
// Matrix [r+1] [c-1]
// Matrix [r+1] [c+1]
// Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

// Example 1:

// Input: N = 2
// Matrix = {{348, 391},
//           {618, 193}}
// Output: 1009
// Explaination: The best path is 391 -> 618.
// It gives the sum = 1009.

// Example 2:

// Input: N = 2
// Matrix = {{2, 2},
//           {2, 2}}
// Output: 4
// Explaination: No matter which path is
// chosen, the output is 4.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function maximumPath() which takes the size N and the Matrix as input parameters and returns the highest maximum path sum.

// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(N*N)

// Constraints:
// 1 ≤ N ≤ 500
// 1 ≤ Matrix[i][j] ≤ 1000\
// / { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int func(int i, int j, vector<vector<int>> &Matrix, vector<vector<int>> &dp, int N)
    {
        if (j < 0 || j >= N)
            return 0;
        if (i == N - 1)
        {
            return Matrix[i][j];
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int a = Matrix[i][j] + func(i + 1, j - 1, Matrix, dp, N);
        int b = Matrix[i][j] + func(i + 1, j, Matrix, dp, N);
        int c = Matrix[i][j] + func(i + 1, j + 1, Matrix, dp, N);
        return dp[i][j] = max({a, b, c});
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int sum = 0;
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int ans = INT_MIN;
        for (int i = 0; i < N; i++)
        {
            int posans = func(0, i, Matrix, dp, N);
            ans = max(ans, posans);
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
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
} // } Driver Code Ends