Minimum removals from array to make max – min <= K

Difficulty Level : Medium
Last Updated : 30 Jun, 2022
Given N integers and K, find the minimum number of elements that should be removed, such that Amax-Amin<=K. After the removal of elements, Amax and Amin is considered among the remaining elements.

Examples: 

Input : a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20} 
          k = 4 
Output : 5 
Explanation: Remove 1, 3, 4 from beginning 
and 17, 20 from the end.

Input : a[] = {1, 5, 6, 2, 8}  K=2
Output : 3
Explanation: There are multiple ways to 
remove elements in this case.
One among them is to remove 5, 6, 8.
The other is to remove 1, 2, 5
Recommended Practice
Array Removals
Try It!
Approach: Sort the given elements. Using the greedy approach, the best way is to remove the minimum element or the maximum element and then check if Amax-Amin <= K. There are various combinations of removals that have to be considered. We write a recurrence relation to try every possible combination. There will be two possible ways of removal, either we remove the minimum or we remove the maximum. Let(i…j) be the index of elements left after removal of elements. Initially, we start with i=0 and j=n-1 and the number of elements removed is 0 at the beginning. We only remove an element if a[j]-a[i]>k, the two possible ways of removal are (i+1…j) or (i…j-1). The minimum of the two is considered. 
Let DPi, j be the number of elements that need to be removed so that after removal a[j]-a[i]<=k. 

Recurrence relation for sorted array:  

DPi, j = 1+ (min(countRemovals(i+1, j), countRemovals(i, j-1))
Below is the implementation of the above idea:

// CPP program to find minimum removals
// to make max-min <= K
#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX][MAX];
 
// function to check all possible combinations
// of removal and return the minimum one
int countRemovals(int a[], int i, int j, int k)
{
    // base case when all elements are removed
    if (i >= j)
        return 0;

    // if condition is satisfied, no more
    // removals are required
    else if ((a[j] - a[i]) <= k)
        return 0;

    // if the state has already been visited
    else if (dp[i][j] != -1)
        return dp[i][j];

    // when Amax-Amin>d
    else if ((a[j] - a[i]) > k)
    {

        // minimum is taken of the removal
        // of minimum element or removal
        // of the maximum element
        dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k),
                           countRemovals(a, i, j - 1, k));
    }
    return dp[i][j];
}
 
// To sort the array and return the answer
int removals(int a[], int n, int k)
{
    // sort the array
    sort(a, a + n);

    // fill all stated with -1
    // when only one element
    memset(dp, -1, sizeof(dp));
    if (n == 1)
        return 0;
    else
        return countRemovals(a, 0, n - 1, k);
}
 
// Driver Code
int main()
{
    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}
Output
5
Time Complexity :O(n2) 
Auxiliary Space: O(n2)

The solution could be further optimized. The idea is to sort the array in increasing order and traverse through all the elements (let’s say index i) and find the maximum element on its right (index j) such that arr[j] – arr[i] <= k. Thus, the number of elements to be removed becomes n-(j-i+1). The minimum number of elements can be found by taking the minimum of n-(j-i-1) overall i. The value of index j can be found through a binary search between start = i+1 and end = n-1;

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to find
// rightmost index
// which satisfies the condition
// arr[j] - arr[i] <= k
int findInd(int key, int i,
            int n, int k, int arr[])
{
    int start, end, mid, ind = -1;

    // Initialising start to i + 1
    start = i + 1;

    // Initialising end to n - 1
    end = n - 1;

    // Binary search implementation
    // to find the rightmost element
    // that satisfy the condition
    while (start < end)
    {
        mid = start + (end - start) / 2;

        // Check if the condition satisfies
        if (arr[mid] - key <= k)
        {

            // Store the position
            ind = mid;

            // Make start = mid + 1
            start = mid + 1;
        }
        else
        {
            // Make end = mid
            end = mid;
        }
    }

    // Return the rightmost position
    return ind;
}
 
// Function to calculate
// minimum number of elements
// to be removed
int removals(int arr[], int n, int k)
{
    int i, j, ans = n - 1;

    // Sort the given array
    sort(arr, arr + n);

    // Iterate from 0 to n-1
    for (i = 0; i < n; i++)
    {

        // Find j such that
        // arr[j] - arr[i] <= k
        j = findInd(arr[i], i, n, k, arr);

        // If there exist such j
        // that satisfies the condition
        if (j != -1)
        {
            // Number of elements
            // to be removed for this
            // particular case is
            // (j - i + 1)
            ans = min(ans, n - (j - i + 1));
        }
    }

    // Return answer
    return ans;
}
 
// Driver Code
int main()
{
    int a[] = {1, 3, 4, 9, 10,
               11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}
Output
5
Time Complexity :O(nlogn) 

Auxiliary Space: O(n)

Approach:

The solution could be further optimized. The idea is to sort the array in increasing order and traverse through all the elements (let’s say index j) and find the minimum element on its left (index i) such that arr[j] – arr[i] <= k and store it in dp[j].
Thus, the number of elements to be removed becomes n-(j-i+1). The minimum number of elements can be found by taking the minimum of n-(j-i-1) overall j. The value of index i can be found through its previous dp array element value.
Below is the implementation of the approach:

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// To sort the array and return the answer
int removals(int arr[], int n, int k)
{
    // sort the array
    sort(arr, arr + n);
    int dp[n];

    // fill all stated with -1
    // when only one element
    for (int i = 0; i < n; i++)
        dp[i] = -1;

    // as dp[0] = 0 (base case) so min
    // no of elements to be removed are
    // n-1 elements
    int ans = n - 1;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = i;
        int j = dp[i - 1];
        while (j != i && arr[i] - arr[j] > k)
        {
            j++;
        }
        dp[i] = min(dp[i], j);
        ans = min(ans, (n - (i - j + 1)));
    }
    return ans;
}
 
// Driver code   
int main()
{
    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}
 
// This code is contributed by Balu Nagar
Output
5
Time Complexity: O(nlog n). As outer loop is going to make n iterations. And the inner loop iterates at max n times for all outer iterations. Because we start value of j from dp[i-1] and loops it until it reaches i and then for the next element we again start from the previous dp[i] value. So the total time complexity is O(n) if we don’t consider the complexity of the sorting as it is not considered in the above solution as well.

Auxiliary Space: O(n)

Space Optimised Approach
The solution could be further optimized. It can be done in Auxiliary Space: O(1). The idea is to first sort the array in ascending order. The keep 2 pointers, say i and j, where j iterates from index 1 to index n-1 and keeps track of ending subarray with the difference in max and min less than k, and i keeps the track of starting index of the subarray. If we find that a[j] – a[i[ <=k (means the i to j subarray is valid) we update the length from i to j in a variable to track of max length so far. Else, we update the starting index i with i+1. 

At first it seems that subarrays from i to j are ignored, but obviously their lengths are less than i to j subarray, so we don’t care about them.

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
int removal(int a[], int n, int k)
{
    // Sort the Array; Time complexity:O(nlogn)
    sort(a, a + n);

    // to store the max length of
    // array with difference <= k
    int maxLen = INT_MIN;
    int i = 0;
    // J goes from 1 to n-1 in n-2 iterations
    // Thus time complexity of below loop is O(n)
    for (int j = i + 1; j < n && i < n; j++)
    {
        // if the subarray from i to j index is valid
        // the store it's length
        if (a[j] - a[i] <= k)
        {
            maxLen = max(maxLen, j - i + 1);
        }
        // if subarray difference exceeds k
        // change starting position, i.e. i
        else
        {
            i++;
        }
    }
    // no. of elements need to be removed is
    // Length of array - max subarray with diff <= k
    int removed = n - maxLen;
    return removed;
}
 
//Driver Code
int main()
{
    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removal(a, n, k);
    return 0;
}
Output
5
Time Complexity: O(nlogn) For sorting the array, we require O(nlogn) time, and no extra space. And for calculating we only traverse the loop once, thus it has O(n) time complexity. So, overall time complexity is O(nlogn).

Auxiliary Space: O(1)