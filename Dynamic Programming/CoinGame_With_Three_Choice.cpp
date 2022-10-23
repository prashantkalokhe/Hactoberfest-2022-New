// Geek and its Game of Coins
// EasyAccuracy: 43.51%Submissions: 5434Points: 2
// Given three numbers N, X, and Y. Geek and his friend playing a coin game. At the beginning, there are N coins. In each move, a player can pick X, Y, or 1 coin. Geek always starts the game. The player who picks the last coin wins the game. The task is to check whether Geek will win the game or not if both are playing optimally.

// Example 1:

// Input: N = 5, X = 3, Y = 4
// Output: 1
// Explanation: There are 5 coins, every
// player can pick 1 or 3 or 4 coins on
// his/her turn. Geek can win by picking
// 3 coins in first chance. Now 2 coins
// will be left so his frined will pick
// one coin and now Geek can win by
// picking the last coin.
// Example 2:
// Input: N = 2, X = 3, Y = 4
// Output: 0
// Explanation: Geek picks 1 and then
// his friend picks 1

// Your Task:
// You don't need to read input or print anything. Complete the function findWinner() which takes N, X, and Y as input parameters and returns 1 if Geek can win otherwise 0.

// Expected Time Complexity: O(|N|)
// Expected Auxiliary Space: O(|N|)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int dp[1000001];
    // here dp[i] = true means A win for n = i
    int helper(int N, int X, int Y)
    {
        if (N == 0)
            return (0);
        if (N == 1)
            return (1);

        if (dp[N] != -1)
            return (dp[N]);

        int res1 = N - X >= 0 ? helper(N - X, X, Y) : 1;
        if (res1 == 0)
            return (dp[N] = 1);
        int res2 = N - Y >= 0 ? helper(N - Y, X, Y) : 1;
        if (res2 == 0)
            return (dp[N] = 1);
        int res3 = N - 1 >= 0 ? helper(N - 1, X, Y) : 1;
        if (res3 == 0)
            return (dp[N] = 1);
        return (dp[N] = 0);
    }

    int findWinner(int N, int X, int Y)
    {
        memset(dp, -1, sizeof(dp));
        return helper(N, X, Y);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        Solution ob;
        cout << ob.findWinner(n, x, y);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

// BOTTOMUP

// Input :  n = 5, x = 3, y = 4
// Output : A
// There are 5 coins, every player can pick 1 or
// 3 or 4 coins on his/her turn.
// A can win by picking 3 coins in first chance.
// Now 2 coins will be left so B will pick one
// coin and now A can win by picking the last coin.

// Input : 2 3 4
// Output : B
// Recommended Practice
// Geek and its Game of Coins
// Try It!
// Let us take few example values of n for x = 3, y = 4.
// n = 0 A can not pick any coin so he losses
// n = 1 A can pick 1 coin and win the game
// n = 2 A can pick only 1 coin. Now B will pick 1 coin and win the game
// n = 3 4 A will win the game by picking 3 or 4 coins
// n = 5, 6 A will choose 3 or 4 coins. Now B will have to choose from 2 coins so A will win.
// We can observe that A wins game for n coins only when B loses for coins n-1 or n-x or n-y.

// C++ program to find winner of game
// if player can pick 1, x, y coins
#include <bits/stdc++.h>
using namespace std;

// To find winner of game
bool findWinner(int x, int y, int n)
{
    // To store results
    int dp[n + 1];

    // Initial values
    dp[0] = false;
    dp[1] = true;

    // Computing other values.
    for (int i = 2; i <= n; i++)
    {

        // If A losses any of i-1 or i-x
        // or i-y game then he will
        // definitely win game i
        if (i - 1 >= 0 and !dp[i - 1])
            dp[i] = true;
        else if (i - x >= 0 and !dp[i - x])
            dp[i] = true;
        else if (i - y >= 0 and !dp[i - y])
            dp[i] = true;

        // Else A loses game.
        else
            dp[i] = false;
    }

    // If dp[n] is true then A will
    // game otherwise  he losses
    return dp[n];
}

// Driver program to test findWinner();
int main()
{
    int x = 3, y = 4, n = 5;
    if (findWinner(x, y, n))
        cout << 'A';
    else
        cout << 'B';

    return 0;
}