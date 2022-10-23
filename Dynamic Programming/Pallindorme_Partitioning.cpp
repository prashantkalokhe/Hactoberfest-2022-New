// Palindromic Partitioning
// HardAccuracy: 52.73%Submissions: 49690Points: 8
// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.

// Example 1:

// Input: str = "ababbbabbababa"
// Output: 3
// Explaination: After 3 partitioning substrings
// are "a", "babbbab", "b", "ababa".
// Example 2:

// Input: str = "aaabba"
// Output: 1
// Explaination: The substrings after 1
// partitioning are "aa" and "abba".

// Your Task:
// You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as the input parameter and returns the minimum number of partitions required.

// Expected Time Complexity: O(n*n) [n is the length of the string str]
// Expected Auxiliary Space: O(n*n)
//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isPallindrome(string &str, int i, int j)
    {

        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string str, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
        {
            return 0;
        }
        if (isPallindrome(str, i, j) == true)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        int low, high;
        for (int k = i; k <= j - 1; k++)
        {
            // int tempans=1+solve(str,i,k,dp)+solve(str,k+1,j,dp);
            if (dp[i][k] != -1)
            {
                low = dp[i][k];
            }
            else
            {
                low = solve(str, i, k, dp);
                dp[i][k] = low;
            }
            if (dp[k + 1][j] != -1)
            {
                high = dp[k + 1][j];
            }
            else
            {
                high = solve(str, k + 1, j, dp);
                dp[k + 1][j] = high;
            }
            int tempans = 1 + low + high;
            ans = min(ans, tempans);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here

        int n = str.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int i = 0, j = n - 1;
        return solve(str, i, j, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends