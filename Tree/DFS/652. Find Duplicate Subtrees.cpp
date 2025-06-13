struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  #include <algorithm>
#include <vector>
using namespace std;
#include <unordered_map>
#include <string>
#include <iostream>
class Solution {
public:
    string Dfs(TreeNode* root , unordered_map<string,int>&mp , vector<TreeNode*>&res ){
        if(!root) return "NULL";
        string s = to_string(root->val) + "," + Dfs(root->left,mp , res)+"," + Dfs(root->right , mp , res);
        if(mp[s] == 1)
        res.push_back(root);
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string , int>mp;
        vector<TreeNode* > res;
         Dfs(root, mp , res);
         return res;
    }
};