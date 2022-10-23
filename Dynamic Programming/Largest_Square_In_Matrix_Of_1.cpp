// Largest square formed in a matrix
// MediumAccuracy: 49.17%Submissions: 25963Points: 4
// Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

// Example 1:

// Input: n = 2, m = 2
// mat = {{1, 1},
//        {1, 1}}
// Output: 2
// Explaination: The maximum size of the square
// sub-matrix is 2. The matrix itself is the
// maximum sized sub-matrix in this case.
// Example 2:

// Input: n = 2, m = 2
// mat = {{0, 0},
//        {0, 0}}
// Output: 0
// Explaination: There is no 1 in the matrix.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function maxSquare() which takes n, m and mat as input parameters and returns the size of the maximum square sub-matrix of given matrix.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 50
// 0 ≤ mat[i][j] ≤ 1
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int c, r;
    int dp[55][55];

    int sol(int i, int j, vector<vector<int>> &mat)
    {
        if (i < 0 || j < 0 || i >= r || j >= c || mat[i][j] == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min(sol(i - 1, j, mat), min(sol(i, j - 1, mat), sol(i - 1, j - 1, mat))) + 1;
    }
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        r = n;
        c = m;
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                ans = max(ans, sol(i, j, mat));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends