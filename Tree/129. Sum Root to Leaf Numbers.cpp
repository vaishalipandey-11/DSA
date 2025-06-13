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
    int find(TreeNode* root , int curr){
        if(!root) return 0;
        
        // work
        curr = curr*10 + root->val ; 
        // dekh lo abhi end pe ho ky toh curr ko dedo 
        if(root->left == nullptr && root->right == nullptr){ //bc 
            return curr ;
        }

        int left = find(root->left , curr ); // rec call for left 
        int right = find(root->right , curr); // rec call for right 

        return left + right ;
    }

    int sumNumbers(TreeNode* root) {
     return find(root , 0);        
    }
};
