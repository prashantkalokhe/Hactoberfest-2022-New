/*Create Linked List from a given Binary Search Tree */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTree
{

public:
    T data;
    BinaryTree<int> *left= NULL;
    BinaryTree<int> *right= NULL;
    BinaryTree(T data)
    {

        this->data = data;
    }

    BinaryTree<int> *TakeinputLevelwise()
    {

        queue<BinaryTree<int> *> pendingNodes;
        int rootData;
        cout << "Enter Root Data : ";
        cin >> rootData;
        if (rootData == -1)
        {
            return NULL;
        }
        BinaryTree<int> *root = new BinaryTree<int>(rootData);
        pendingNodes.push(root);
        while (pendingNodes.size() != 0)
        {
            BinaryTree<int> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << "Enter Left child of " << front->data << " : ";
            int leftchild;
            cin >> leftchild;
            if (leftchild != -1)
            {

                BinaryTree<int> *child = new BinaryTree<int>(leftchild);
                front->left = child;
                pendingNodes.push(child);
            }

            cout << "Enter right child of " << front->data << " : ";
            int rightchild;
            cin >> rightchild;
            if (rightchild != -1)
            {

                BinaryTree<int> *child = new BinaryTree<int>(rightchild);
                front->right = child;
                pendingNodes.push(child);
            }
        }
        return root;
    }

    void printTree(BinaryTree<int> *root)
    {

        queue<BinaryTree<int> *> pendingNodes;
        pendingNodes.push(root);
        while (pendingNodes.size() != 0)
        {
            BinaryTree<int> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << endl;
            cout << front->data << " : ";
            if (front->left != NULL)
            {

                cout << " L" << front->left->data;
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {

                cout << " R" << front->right->data;
                pendingNodes.push(front->right);
            }
           
        }
    }

    ~BinaryTree(){

        delete left;
        delete right;
    }
};
class node{
  public:  int data;
           node* next;

        node(int data){
            this->data=data;
            next=NULL;
        }      
};
class Pair{
  public: node* head;
          node* tail;
};

Pair LLfromBST(BinaryTree<int>* root){
    if(root==NULL){
        Pair zero;
        zero.head=NULL;
        zero.tail=NULL;
        return zero;
    }
    if(root->left==NULL){
        if(root->right==NULL){
            Pair ans;
            node* newnode=new node(root->data);
            ans.head=newnode;
            ans.tail=newnode;             
            return ans;
        }
        else{
            node* newnode=new node(root->data);
            Pair ans;
            ans=LLfromBST(root->right);
            newnode->next=ans.head;
            ans.head=newnode;
            return ans;
        }
    }
    else{
         if(root->right==NULL){
            Pair ans;
            ans=LLfromBST(root->left);
            node* newnode= new node(root->data);
            ans.tail->next=newnode;
            ans.tail=newnode;
            return ans;
         }
         else{
         Pair ans;
        ans=LLfromBST(root->left);
        node* newnode= new node(root->data);
        ans.tail->next=newnode;
        ans.tail=newnode;
        Pair ans2;
        ans2=LLfromBST(root->right);
        ans.tail->next=ans2.head;
        ans.tail=ans2.tail;
        return ans;
         }
    }
}
void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() 
{
    BinaryTree<int> *root=root->TakeinputLevelwise();
    node* head=LLfromBST(root).head;
    print(head);
    return 0;

}