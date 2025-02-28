//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *newNode(int key)
{
    Node *node = new Node(key);
    return node;
}


// real code .....................................O(n2)....
class Solution
{
public:
    Node *flattenBST(Node *root)
    {   //bc
        if(!root) return NULL ;
        
        // believe in recc 
        // flatten left side and return head of it 
        Node* head = flattenBST(root->left);
        root->left= NULL ; // detach root from left 5->3 X 
        root->right = flattenBST(root->right); // call for right side as well
        
        // check if head is available and then traverse in left side to find 
        // the end and attach the right pointer to root node 
        if(head){
            Node* temp = head;
            while(temp->right){
                temp= temp->right;
            }
            // final attach
            temp->right = root;
        }else{ // if single 
            head = root ;
        }
        
        // return the head which is the staring of sorted ll
        return head;
        
    }
};


//{ Driver Code Starts.

