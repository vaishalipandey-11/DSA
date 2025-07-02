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


//Approach-2 (DFS)
//T.C : O(n)
//S.C : Auxiliary Space O(n) + Recursion Space O(depth)
class Solution {
public:
    
    vector<int> levelPrev;
    
    bool solve(TreeNode* root, int level) {
        if(!root) {
            return true;
        }
        
        if((level%2 == 0 && root->val%2 == 0) || (level%2 != 0 && root->val%2 != 0)) {
            return false;
        }
        
        if(level >= levelPrev.size()) {
            levelPrev.resize(level+1);
        }

        if(levelPrev[level] != 0) { //already there is a value at this level
            if((level%2 == 0 && root->val <= levelPrev[level]) ||
               (level%2 != 0 && root->val >= levelPrev[level]))
                return false;
        }
        
        levelPrev[level] = root->val;
        
        return solve(root->left, level+1) && solve(root->right, level+1);
    }
    
    bool isEvenOddTree(TreeNode* root) {
        return solve(root, 0);
    }
};