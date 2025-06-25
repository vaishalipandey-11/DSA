
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int result ;
    //ftn to find sum of each node from child dfs
    int sum(TreeNode* root , int &count ){
        if(!root ) return 0;
        count ++;
        int l = sum(root->left , count );
        int r = sum(root->right , count );

        return l+r+ root->val;
    }
    void solve(TreeNode* root){ //ftn for checking sum and value of node 
        if(!root) return ;

        int count =0;
        int totalsum = sum(root,count);

        if((totalsum)/count == root->val){
            result++;
        }

         solve(root->left );
         solve(root->right);   
    }
    int averageOfSubtree(TreeNode* root) {// call
        result =0;
      
      solve(root);
      return result;
        
    }
};