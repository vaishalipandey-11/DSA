#include <iostream>
#include <cmath> // For abs function
#include <algorithm> // For min and max functions
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
  public :
  int maxdiff(TreeNode* root , int minv , int maxv){
    if(!root) return abs(maxv-minv); // if the end of the path just return the diff of the max and min value found 
    
    minv = min(root->val , minv); // update both the values as we move to different root 
    maxv = max(root->val , maxv);

    int l = maxdiff(root->left, minv ,maxv);  // one for left side other for right 
    int r = maxdiff(root->right, minv , maxv);

    return max(l,r); //fetch the maximum 
  }
    int maxAncestorDiff(TreeNode* root) {
        int minv= root->val; // in the beginning  both are root values 
        int maxv = root->val;

        return maxdiff(root , minv , maxv);
    
    }
};