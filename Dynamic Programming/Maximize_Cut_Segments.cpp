// Maximize The Cut Segments
// Medium Accuracy: 38.76% Submissions: 91014 Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.
// Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum.

// Example 1:

// Input:
// N = 4
// x = 2, y = 1, z = 1
// Output: 4
// Explanation:Total length is 4, and the cut
// lengths are 2, 1 and 1.  We can make
// maximum 4 segments each of length 1.
// Example 2:

// Input:
// N = 5
// x = 5, y = 3, z = 2
// Output: 2
// Explanation: Here total length is 5, and
// the cut lengths are 5, 3 and 2. We can
// make two segments of lengths 3 and 2.
// Your Task:
// You only need to complete the function maximizeTheCuts() that takes n, x, y, z as parameters and returns max number cuts.

// Expected Time Complexity : O(N)
// Expected Auxiliary Space: O(N)

// Constraints
// 1 <= N, x, y, z <= 104
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the maximum number of cuts.
    int solve(int n, int x, int y, int z, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n < x && n < y && n < z)
        {
            return INT_MIN;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = 1 + max(solve(n - x, x, y, z, dp), max(solve(n - y, x, y, z, dp), solve(n - z, x, y, z, dp)));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here
        vector<int> dp(n + 1, -1);
        int ans = solve(n, x, y, z, dp);
        if (ans < 0)
        {
            return 0;
        }
        else
            return ans;
    }
};

// { Driver Code Starts.
int main()
{

    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking length of line segment
        int n;
        cin >> n;

        // taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        // calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
} // } Driver Code Ends