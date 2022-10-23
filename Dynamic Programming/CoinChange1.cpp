// Coin Change
// Medium Accuracy: 47.19% Submissions: 85171 Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.
// Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.

// Example 1:

// Input:
// n = 4 , m = 3
// S[] = {1,2,3}
// Output: 4
// Explanation: Four Possible ways are:
// {1,1,1,1},{1,1,2},{2,2},{1,3}.
// Example 2:

// Input:
// n = 10 , m = 4
// S[] ={2,5,3,6}
// Output: 5
// Explanation: Five Possible ways are:
// {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5}
// and {5,5}.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function count() which accepts an array S[] its size m and n as input parameter and returns the number of ways to make change for N cents.

// Expected Time Complexity: O(m*n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 <= n,m <= 103

#include <bits/stdc++.h>
using namespace std;
#define RUN 100
#define MAX 25
#define MAXLEN 100

int main()
{
    srand(time(NULL));
    int LEN;
    int x;
    x = 1 + rand() % RUN;
    printf("%d"
           "\n",
           x / 2);
    for (int i = 1; i <= x; i++)
    {
        LEN = 1 + rand() % MAXLEN;
        printf("%d"
               "\n",
               LEN);
        for (int j = 0; j < LEN; j++)
        {
            int x = 1 + rand() % 2;
            if (x == 1)
            {
                printf("%c", 'a' + rand() % MAX);
            }
            else if (x == 2)
            {
                printf("%d", 1 + rand() % 9);
            }
        }
        printf("\n");
    }
    return (0);
}