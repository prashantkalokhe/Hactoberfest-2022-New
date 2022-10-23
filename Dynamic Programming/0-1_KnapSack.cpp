// 0 - 1 Knapsack Problem
// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

// Example 1:

// Input:
// N = 3
// W = 4
// values[] = {1,2,3}
// weight[] = {4,5,1}
// Output: 3
// Example 2:

// Input:
// N = 3
// W = 3
// values[] = {1,2,3}
// weight[] = {4,5,6}
// Output: 0
// Your Task:
// Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[], and the number of items n as a parameter and returns the maximum possible value you can get.

// Expected Time Complexity: O(N*W).
// Expected Auxiliary Space: O(N*W)
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // //Function to return max value that can be put in knapsack of capacity W.
    //   RECURSIVE CODE
    int knapSackrec(int W, int wt[], int val[], int n, vector<vector<int>> &t)
    {
        if (n == 0 || W == 0)
        {
            return 0;
        }
        if (t[n][W] != -1)
        {
            return t[n][W];
        }

        if (wt[n - 1] <= W)
        {
            return t[n][W] = max(val[n - 1] + knapSackrec(W - wt[n - 1], wt, val, n - 1, t), knapSackrec(W, wt, val, n - 1, t));
        }
        else if (wt[n - 1] > W)
        {
            return t[n][W] = knapSackrec(W, wt, val, n - 1, t);
        }
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        //   // Your code here
        vector<vector<int>> t(n + 1, vector<int>(W + 1, -1));

        return knapSackrec(W, wt, val, n, t);

        // TOPDOWN APPROACH
        // int t[n+1][W+1];
        // for(int i=0;i<n+1;i++){
        //   for(int j=0;j<W+1;j++){
        //       if(i==0||j==0){
        //           t[i][j]=0;
        //         }
        //     }
        // }
        // for(int i=1;i<n+1;i++){
        //   for(int j=1;j<W+1;j++){
        //         if(wt[i-1]<=j){
        //             t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
        //         }
        //         else{
        //             t[i][j]=t[i-1][j];
        //         }
        //     }
        // }
        // return t[n][W];
    }
};

// { Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
} // } Driver Code Ends