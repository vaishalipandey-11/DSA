
 
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

// This code finds the maximum path sum in a binary tree.


class Solution {
public:
    int maxsum;
    int solve(TreeNode* root ){
        if(root== NULL) return  0;

        int l = solve(root->left);
        int r = solve(root->right);

        int neeche_tha_ans = l+r+root->val;        //1
        int ek_side_pe_mila = max(l,r)+root->val;  //2
        int root_pe_mila = root->val;              //3
         
         maxsum = max({maxsum ,neeche_tha_ans,ek_side_pe_mila,root_pe_mila}); // finding the ,ax of three

        return max(ek_side_pe_mila,root_pe_mila); // return the valid (only 2 )

    }
    int maxPathSum(TreeNode* root) {
        maxsum = 0 ;
        solve(root);
         return maxsum ;
    }
};