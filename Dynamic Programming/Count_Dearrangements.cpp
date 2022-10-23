// Count Derangements (Permutation such that no element appears in its original position)

// A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
// Given a number n, find the total number of Derangements of a set of n elements.

// Examples :

// Input: n = 2
// Output: 1
// For two elements say {0, 1}, there is only one
// possible derangement {1, 0}

// Input: n = 3
// Output: 2
// For three elements say {0, 1, 2}, there are two
// possible derangements {2, 0, 1} and {1, 2, 0}

// Input: n = 4
// Output: 9
// For four elements say {0, 1, 2, 3}, there are 9
// possible derangements {1, 0, 3, 2} {1, 2, 3, 0}
// {1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3,
// 1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1} and {3, 2, 1, 0}
// Recommended: Please try your approach on {IDE} first, before moving on to the solution.
// Let countDer(n) be count of derangements for n elements. Below is the recursive relation to it.

// countDer(n) = (n - 1) * [countDer(n - 1) + countDer(n - 2)]
// How does above recursive relation work?

// There are n – 1 way for element 0 (this explains multiplication with n – 1).
// Let 0 be placed at index i. There are now two possibilities, depending on whether or not element i is placed at 0 in return.

// i is placed at 0: This case is equivalent to solving the problem for n-2 elements as two elements have just swapped their positions.
// i is not placed at 0: This case is equivalent to solving the problem for n-1 elements as now there are n-1 elements, n-1 positions and every element has n-2 choices
// Below is the simple solution based on the above recursive formula:

// // A Naive Recursive C++ program
// // to count derangements
#include <bits/stdc++.h>
using namespace std;

int countDer(int n)
{
    // Base cases
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    // countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
    return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}

// Driver Code
int main()
{
    int n = 4;
    cout << "Count of Derangements is "
         << countDer(n);
    return 0;
}
// Output
// Count of Derangements is 9
// Time Complexity: O(2^n) since T(n) = T(n-1) + T(n-2) which is exponential.

// Auxiliary Space: O(h) where h= log n is the maximum height of the tree.

// We can observe that this implementation does repetitive work. For example, see recursion tree for countDer(5), countDer(3) is being evaluated twice.

// cdr() ==> countDer()

//                     cdr(5)
//                  /         \     
//              cdr(4)          cdr(3)
//            /      \         /     \
//        cdr(3)     cdr(2)  cdr(2)   cdr(1)
// An Efficient Solution is to use Dynamic Programming to store results of subproblems in an array and build the array in bottom-up manner.

// // A Dynamic programming based C++
// // program to count derangements
// #include <bits/stdc++.h>
// using namespace std;

int countDer(int n)
{
    // Create an array to store
    // counts for subproblems
    int der[n + 1] = {0};

    // Base cases
    der[1] = 0;
    der[2] = 1;

    // Fill der[0..n] in bottom up manner
    // using above recursive formula
    for (int i = 3; i <= n; ++i)
        der[i] = (i - 1) * (der[i - 1] +
                            der[i - 2]);

    // Return result for n
    return der[n];
}

// // Driver code
// int main()
// {
//     int n = 4;
//     cout << "Count of Derangements is "
//          << countDer(n);
//     return 0;
// }
// Output
// Count of Derangements is 9
// Time Complexity : O(n)
// Auxiliary Space : O(n)

// A More Efficient Solution Without using Extra Space.

// As we only need to remember only two previous values So, instead of Storing the values in an array two variables can be used to just store the required previous only.

// Below is the implementation of the above approach:

// // C++ implementation of the above
// // approach

// #include <iostream>
// using namespace std;

// int countDer(int n)
// {

//     // base case
//     if (n == 1 or n == 2) {
//         return n - 1;
//     }

//     // Variable for just storing
//     // previous values
//     int a = 0;
//     int b = 1;

//     // using above recursive formula
//     for (int i = 3; i <= n; ++i) {
//         int cur = (i - 1) * (a + b);
//         a = b;
//         b = cur;
//     }

//     // Return result for n
//     return b;
// }

// // Driver Code
// int main()
// {

//     cout << "Count of Derangements is " << countDer(4);
//     return 0;
// }

// Output
// Count of Derangements is 9
// Time Complexity: O(n)
// Auxiliary Space: O(1), since no extra space has been taken.