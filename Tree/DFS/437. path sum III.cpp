

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
        int ans =0;
    // create a function for root element only
    void Path(TreeNode* root , long sum ){
        // edge case
        if(!root) return ;
        if(root->val == sum ){
            ans++;
        }

        Path(root->left , sum-root->val);
        Path(root->right , sum - root->val);
    }
    int pathSum(TreeNode* root, long targetSum) {
        // calculate path for each node now 
        if(root){
        Path(root , targetSum );
        pathSum(root->left , targetSum);
        pathSum(root->right , targetSum);
        }
      return ans ;   
        
    
}
};