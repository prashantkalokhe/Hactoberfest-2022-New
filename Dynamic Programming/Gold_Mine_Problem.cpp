// Gold Mine Problem
// Easy Accuracy: 51.7% Submissions: 38380 Points: 2
// Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

// to the cell diagonally up towards the right
// to the right
// to the cell diagonally down towards the right
// Find out maximum amount of gold which he can collect.

// Example 1:

// Input: n = 3, m = 3
// M = {{1, 3, 3},
//      {2, 1, 4},
//      {0, 6, 4}};
// Output: 12
// Explaination:
// The path is {(1,0) -> (2,1) -> (2,2)}.

// Example 2:

// Input: n = 4, m = 4
// M = {{1, 3, 1, 5},
//      {2, 2, 4, 1},
//      {5, 0, 2, 3},
//      {0, 6, 1, 2}};
// Output: 16
// Explaination:
// The path is {(2,0) -> (3,1) -> (2,2)
// -> (2,3)} or {(2,0) -> (1,1) -> (1,2)
// -> (0,3)}.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function maxGold() which takes the values n, m and the mine M as input parameters and returns the maximum amount of gold that can be collected.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 50
// 1 ≤ M[i][j] ≤ 100
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxv(int x, int y, int z)
    {
        return max(max(x, y), z);
    }
    int help(int n, int m, vector<vector<int>> &v, int x, int y, vector<vector<int>> &dp)
    {
        if (x < 0 || x == n || y == m)
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];
        int ud = help(n, m, v, x - 1, y + 1, dp);
        int right = help(n, m, v, x, y + 1, dp);
        int ld = help(n, m, v, x + 1, y + 1, dp);
        return dp[x][y] = v[x][y] + maxv(ud, right, ld);
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {

        int maxg = INT_MIN;
        vector<vector<int>> v(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i < n; i++)
        {
            int cg = help(n, m, M, i, 0, v);
            maxg = max(maxg, cg);
        }
        return maxg;
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
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
} // } Driver Code Ends