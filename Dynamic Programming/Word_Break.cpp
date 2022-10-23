// Word Break
// MediumAccuracy: 50.24%Submissions: 39292Points: 4
// Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

// Note: From the dictionary B each word can be taken any number of times and in any order.
// Example 1:

// Input:
// n = 12
// B = { "i", "like", "sam",
// "sung", "samsung", "mobile",
// "ice","cream", "icecream",
// "man", "go", "mango" }
// A = "ilike"
// Output:
// 1
// Explanation:
// The string can be segmented as "i like".

// Example 2:

// Input:
// n = 12
// B = { "i", "like", "sam",
// "sung", "samsung", "mobile",
// "ice","cream", "icecream",
// "man", "go", "mango" }
// A = "ilikesamsung"
// Output:
// 1
// Explanation:
// The string can be segmented as
// "i like samsung" or "i like sam sung".

// Your Task:
// Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.

// Expected time complexity: O(s2)

// Expected auxiliary space: O(s) , where s = length of string A

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// A : given string to search
// B : vector of available strings

// B={a , ab, c, d , e, de, bc}
// A=abcd

// a (if a is found in B recursion on bcd) bcd or
// ab (if ab is found in B recursion on cd) cd or
// abc (if abc is found in B recursion on d) d.

class Solution
{
public:
    unordered_map<string, int> dp;
    int solve(string A, vector<string> &B)
    {
        int n = A.length();
        if (n == 0)
        {
            return 1;
        }
        if (dp[A] != 0)
        {
            return dp[A];
        }
        for (int i = 0; i <= n; i++)
        {
            int f = 0;
            string ss = A.substr(0, i);
            for (int j = 0; j < B.size(); j++)
            {
                if (ss.compare(B[j]) == 0)
                {
                    f = 1;
                    break;
                }
            }
            if (f == 1 && solve(A.substr(i, n - i), B) == 1)
            {
                return dp[A] = 1;
            }
        }
        return dp[A] = -1;
    }
    int wordBreak(string A, vector<string> &B)
    {
        // code here
        int x = solve(A, B);
        if (x == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
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
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}

// } Driver Code Ends