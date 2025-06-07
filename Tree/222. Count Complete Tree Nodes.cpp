struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
#include <iostream>
#include <queue>
using namespace std;
#include <cmath> // For pow function
class Solution {
public:
    int lefth(TreeNode* root){
        if(root == NULL)  return 0;
        int lh =0;
        while(root){
            lh++;
            root = root->left;
        }
        return lh;
    }

    int righth(TreeNode* root){
        if(root==NULL) return 0;
        int rh =0;
        while(root){
            rh++;
            root= root->right;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = lefth(root );
        int rh = righth(root);
        if(lh ==rh){
            return pow(2,lh)-1;
        }

        return countNodes(root->left) +countNodes(root->right) +1;
    }
};