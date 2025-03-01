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

//Approach-2
//T.C : O(n)
//S.C : Auxiliary Space is O(1) and Stack Space due to recursion is O(n)
class Solution {
public:
    Node* prev = NULL;
    
    Node* flattenBST(Node* root) {
        if (!root) return NULL;
        
        Node* head = flattenBST(root->left); // Flatten left subtree

        if (prev) {
            prev->right = root;
        } else {
            head = root; // Set head only once (first node in in-order traversal)
        }
        
        prev = root;
        root->left = NULL;  // Remove left link
        
        flattenBST(root->right); // Flatten right subtree
        
        return head;
    }
};




