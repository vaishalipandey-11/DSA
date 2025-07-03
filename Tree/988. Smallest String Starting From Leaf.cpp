 struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string result ="";
    void solve(TreeNode * root , string curr){
     if(!root) return ;
     curr = char(root->val +'a')+curr;

     if(!root->left && !root->right){// leaf tk aagaye ab dekhlo kon chota h 
        if(result =="" || result >curr){
            result = curr;
        }
        return ;
     }
     
      solve(root->left , curr);
      solve(root->right, curr);

    }
    string smallestFromLeaf(TreeNode* root) {
      string curr = "";

      solve(root , curr);
      return result ;
    }
};