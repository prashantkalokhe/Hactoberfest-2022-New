/*

Given two strings s1 and s2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters 
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example :

	Input : s1 = "ABCDGH", s2 = "AEDFHR"
	Output: 3
	Explanation : "ADH" is the LCS between s1 and s2

	Input : s1 = "AGGTAB", s2 = "GXTXAYB"
	Output: 4
	Explanation : “GTAB” is the LCS between s1 and s2

	Input : s1 = "ABCHG", s2 = "ABGCF"
	Output: 3
	Explanation : "ABC" & "ABG" is the LCS between s1 and s2

*/

#include<iostream>
#include<vector>

using namespace std;

int LCS(string& s1, string& s2, int i, int j) {
	if(i == s1.size() || j == s2.size()) {
		// either of the sequences become empty
		return 0;
	}

	if(s1[i] == s2[j]) {
		int l3 = LCS(s1, s2, i+1, j+1);
		return 1 + l3;
	}

	int l1 = LCS(s1, s2, i+1, j);
	int l2 = LCS(s1, s2, i, j+1);

	return max(l1, l2);

}

int LCSTopDown(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
	if(i == s1.size() || j == s2.size()) {
		// either of the sequences become empty
		return dp[i][j] = 0;
	}

	// lookup
	if(dp[i][j] != -1) return dp[i][j];

	if(s1[i] == s2[j]) {
		int l3 = LCSTopDown(s1, s2, i+1, j+1, dp);
		return dp[i][j] = 1 + l3;
	}

	int l1 = LCSTopDown(s1, s2, i+1, j, dp);
	int l2 = LCSTopDown(s1, s2, i, j+1, dp);

	return dp[i][j] = max(l1, l2);

}

int LCSBottomUp(string s1, string s2, int m, int n) {
	// automatically handle the base case during initialisation
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

	for(int i=m-1; i>=0; i--) {
		for(int j=n-1; j>=0; j--) {
			if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i+1][j+1];
			else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
		}
	}

	return dp[0][0];

}

int main() {

	string s1("ABCDGH");
	string s2("AEDFHR");

	int m = s1.size();
	int n = s2.size();

	cout << LCS(s1, s2, 0, 0) << endl;

	vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
	cout << LCSTopDown(s1, s2, 0, 0, dp) << endl;
	cout << LCSBottomUp(s1, s2, m, n) << endl;

	return 0;
}

