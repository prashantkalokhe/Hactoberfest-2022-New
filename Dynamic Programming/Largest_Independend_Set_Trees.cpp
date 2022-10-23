// Largest Independent Set Problem | DP-26

// Given a Binary Tree, find size of the Largest Independent Set(LIS) in it. A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset.

// For example, consider the following binary tree. The largest independent set(LIS) is {10, 40, 60, 70, 80} and size of the LIS is 5.

// A Dynamic Programming solution solves a given problem using solutions of subproblems in bottom up manner. Can the given problem be solved using solutions to subproblems? If yes, then what are the subproblems? Can we find largest independent set size (LISS) for a node X if we know LISS for all descendants of X? If a node is considered as part of LIS, then its children cannot be part of LIS, but its grandchildren can be. Following is optimal substructure property.

// 1) Optimal Substructure:
// Let LISS(X) indicates size of largest independent set of a tree with root X.

//      LISS(X) = MAX { (1 + sum of LISS for all grandchildren of X),
//                      (sum of LISS for all children of X) }
// The idea is simple, there are two possibilities for every node X, either X is a member of the set or not a member. If X is a member, then the value of LISS(X) is 1 plus LISS of all grandchildren. If X is not a member, then the value is sum of LISS of all children.

// 2) Overlapping Subproblems
// Following is recursive implementation that simply follows the recursive structure mentioned above.
// A naive recursive implementation of
// Largest Independent Set problem
#include <bits/stdc++.h>
using namespace std;

// A utility function to find
// max of two integers
int max(int x, int y)
{
    return (x > y) ? x : y;
}

/* A binary tree node has data,
pointer to left child and a
pointer to right child */
class node
{
public:
    int data;
    node *left, *right;
};

// The function returns size of the
// largest independent set in a given
// binary tree
int LISS(node *root)
{
    if (root == NULL)
        return 0;

    // Calculate size excluding the current node
    int size_excl = LISS(root->left) +
                    LISS(root->right);

    // Calculate size including the current node
    int size_incl = 1;
    if (root->left)
        size_incl += LISS(root->left->left) +
                     LISS(root->left->right);
    if (root->right)
        size_incl += LISS(root->right->left) +
                     LISS(root->right->right);

    // Return the maximum of two sizes
    return max(size_incl, size_excl);
}

// A utility function to create a node
node *newNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver Code
int main()
{
    // Let us construct the tree
    // given in the above diagram
    node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    cout << "Size of the Largest"
         << " Independent Set is "
         << LISS(root);

    return 0;
}

// This is code is contributed
// by rathbhupendra
