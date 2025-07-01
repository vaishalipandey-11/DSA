#include <iostream>
using namespace std;
// This code checks if a binary tree is an Even-Odd Tree.
#include <bits/stdc++.h>


  
  struct TreeNode {
      int val;
    TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:

    bool isEvenOddTree(TreeNode* root) {
    
      queue<TreeNode*>q;
      q.push(root);
      bool even = true;

      while(!q.empty()){
        int n = q.size();
        int prev;
        if(even){
            prev = INT_MIN;
        }else{
            prev = INT_MAX;
        }
    
        while(n--){
            TreeNode* node = q.front();
            q.pop();

        if(even && (node->val <=prev || node->val %2 ==0)) return false;
        if(!even && (node->val >=prev || node->val%2 ==1)) return false;

        prev= node->val;

        if(node->left ) q.push(node->left);
        if(node->right) q.push(node->right);

        }
        even = !even;

      }
      return true ;

    }
};