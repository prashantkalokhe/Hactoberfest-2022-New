// Smallest sum contiguous subarray

// Difficulty Level : Easy
// Last Updated : 15 Jul, 2022
// Given an array containing n integers. The problem is to find the sum of the elements of the contiguous subarray having the smallest(minimum) sum.

// Examples:

// Input : arr[] = {3, -4, 2, -3, -1, 7, -5}
// Output : -6
// Subarray is {-4, 2, -3, -1} = -6

// Input : arr = {2, 6, 8, 1, 4}
// Output : 1
// Recommended PracticeSmallest sum contiguous subarrayTry It!
// Naive Approach: Consider all the contiguous subarrays of different sizes and find their sum. The subarray having the smallest(minimum) sum is the required answer.

// Efficient Approach: It is a variation to the problem of finding the largest sum contiguous subarray based on the idea of Kadane’s algorithm.

// Algorithm:

// smallestSumSubarr(arr, n)
//     Initialize min_ending_here = INT_MAX
//     Initialize min_so_far = INT_MAX

//     for i = 0 to n-1
//         if min_ending_here > 0
//             min_ending_here = arr[i]
//         else
//             min_ending_here += arr[i]
//         min_so_far = min(min_so_far, min_ending_here)

//     return min_so_far
// C++ implementation to find the smallest sum
// contiguous subarray
#include <bits/stdc++.h>

using namespace std;

// function to find the smallest sum contiguous subarray
int smallestSumSubarr(int arr[], int n)
{
    // to store the minimum value that is ending
    // up to the current index
    int min_ending_here = INT_MAX;

    // to store the minimum value encountered so far
    int min_so_far = INT_MAX;

    // traverse the array elements
    for (int i = 0; i < n; i++)
    {
        // if min_ending_here > 0, then it could not possibly
        // contribute to the minimum sum further
        if (min_ending_here > 0)
            min_ending_here = arr[i];

        // else add the value arr[i] to min_ending_here
        else
            min_ending_here += arr[i];

        // update min_so_far
        min_so_far = min(min_so_far, min_ending_here);
    }

    // required smallest sum contiguous subarray value
    return min_so_far;
}

// Driver program to test above
int main()
{
    int arr[] = {3, -4, 2, -3, -1, 7, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Smallest sum: "
         << smallestSumSubarr(arr, n);
    return 0;
}
// Time Complexity: O(n)