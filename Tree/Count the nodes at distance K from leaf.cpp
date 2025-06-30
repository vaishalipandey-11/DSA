#include <bits/stdc++.h>
using namespace std;    

// A Tree node
struct Node
{
    int key;
    struct Node *left, *right;
    Node(int x) : key(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
   vector<vector<Node* >>paths;
   void storeRootToLeaf(Node* root , vector<Node*>&temp){
       if(!root) return ;
       
       temp.push_back(root);
       if(!root->left && !root->right){
           paths.push_back(temp);
       }
       if(root->left) storeRootToLeaf(root->left, temp);
       if(root->right ) storeRootToLeaf(root->right, temp);
       
       temp.pop_back();
   }
    
    int printKDistantfromLeaf(Node* root, int k) {
     vector<Node* > temp;
     storeRootToLeaf(root, temp);
     unordered_set<Node*>st;
     for(vector<Node*> &vec : paths){
         int n = vec.size();
         if(n-k>0){
             st.insert(vec[n-k-1]);
         }
     }
     
     return st.size();
     
    }
};