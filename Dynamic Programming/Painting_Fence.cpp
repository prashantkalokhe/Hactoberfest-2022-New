// // https://www.youtube.com/watch?v=ju8vrEAsa3Q&t=469s
// Painting the Fence
// Medium Accuracy: 48.89% Submissions: 29209 Points: 4
// Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive fences have the same colors. Since the answer can be large return it modulo 10^9 + 7.

// Example 1:

// Input:
// N=3,  K=2
// Output: 6
// Explanation:
// We have following possible combinations:

// Example 2:

// Input:
// N=2,  K=4
// Output: 16

// Your Task:
// Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countWays() that takes n and k as parameters and returns the number of ways in which the fence can be painted.(modulo 109 + 7)

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long countWays(int n, int k)
    {

        // code here
        if (n == 1)
        {
            return k;
        }
        long long same = k * 1;
        long long diff = k * (k - 1);
        long long total = same + diff;
        for (int i = 3; i <= n; i++)
        {
            same = (diff) % 1000000007;
            diff = (total * (k - 1)) % 1000000007;
            total = (same + diff) % 1000000007;
        }
        return total;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;
    }
    return 0;
} // } Driver Code Ends