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

//here is the complete code for counting nodes at distance K from leaf nodes in a binary tree:
//here we are reducing the sc of  the solution first by just stirng the paths from root to leaf nodes and then checking the distance k from leaf nodes
//Approach-2 (Without storing all root-leaf paths)
//T.C : O(n)
//S.C : O(h)
class Solution {
    public:
    
    void solve(Node* root, int level, unordered_set<Node*>& result, vector<Node*>& path, int& k) {
        if(!root) {
            return;
        }
        
        path.push_back(root);
        if(!root->left && !root->right) {
            if(level - k >= 0) {
                result.insert(path[level-k]);
            }
        }
        
        solve(root->left, level+1, result, path, k);
        solve(root->right, level+1, result, path, k);
        path.pop_back();
    }
    
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k) {
        vector<Node*> path;
        unordered_set<Node*> result;
    	
    	solve(root, 0, result, path, k);

    	return result.size();
    }
};
