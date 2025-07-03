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
    unordered_map<int , int >mp;
          int maxdepth =0;

    TreeNode* lca(TreeNode* root ){

       if(root==NULL || mp[root->val] == maxdepth ){   
        return root ;
       }

       TreeNode* l = lca(root->left);
       TreeNode* r = lca(root->right);

       if(l && r ) return root;

       return l != NULL ?  l : r ; // if left then return it 


    }      
   
    void depth(TreeNode* root , int d){
        
        if(!root ) return ;

        mp[root->val] = d;
        maxdepth = max(maxdepth , d);

        depth(root->left, d+1);
        depth(root->right,d+1);

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root , 0);
        return lca(root );
    }
};