#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node *left, *right;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->left = temp->right = NULL;
    temp->data = key;
    return temp;
}

Node* insert(Node* root, int key)
{
    if (!root)
        return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int floor(Node* root, int key)
{
    if (!root)
        return INT_MAX;

    if (root->data == key)
        return root->data;

    if (root->data > key)
        return floor(root->left, key);
 
    /* Else, the floor may lie in right subtree
      or may be equal to the root*/
    int floorValue = floor(root->right, key);
    return (floorValue <= key) ? floorValue : root->data;
}
 
int main()
{

    Node* root = NULL;
    root = insert(root, 7);
    insert(root, 10);
    insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 8);
    insert(root, 12);
   
    cout << floor(root, 9) << endl;
    return 0;
}
