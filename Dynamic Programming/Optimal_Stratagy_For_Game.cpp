// Optimal Strategy For A Game
// MediumAccuracy: 52.29%Submissions: 24155Points: 4
// You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

// In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

// You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally.

// Example 1:

// Input:
// N = 4
// A[] = {5,3,7,10}
// Output: 15
// Explanation: The user collects maximum
// value as 15(10 + 5)
// Example 2:

// Input:
// N = 4
// A[] = {8,15,3,7}
// Output: 22
// Explanation: The user collects maximum
// value as 22(7 + 15)
// Your Task:
// Complete the function maximumAmount() which takes an array arr[] (represent values of N coins) and N as number of coins as a parameter and returns the maximum possible amount of money you can win if you go first.

// Expected Time Complexity : O(N*N)
// Expected Auxiliary Space: O(N*N)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find the maximum possible amount of money we can win.
class Solution
{
public:
    // B aise khelega ki next turn me A ko minimum mile
    long long solve(int arr[], int n, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        // MAX-MIN ALGO  (inside max we are finding min)
        // when b will pay optimally.
        // if A chooses first,next time A will get to choose minimum of i+2,j or i+1,j-1 as B had choosed the one which will get more score as both are playing optimally. similarly if a chooses last i.e a[j]
        return dp[i][j] = max(arr[i] + min(solve(arr, n, i + 2, j, dp), solve(arr, n, i + 1, j - 1, dp)), arr[j] + min(solve(arr, n, i + 1, j - 1, dp), solve(arr, n, i, j - 2, dp)));
    }
    long long maximumAmount(int arr[], int n)
    {
        // Your code here
        int i = 0, j = n - 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(arr, n, i, j, dp);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximumAmount(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends