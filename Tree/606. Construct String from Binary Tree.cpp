
#include <bits/stdc++.h>
using namespace std;
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
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";

        // root 1st
        string result = to_string(root->val);
        if(root->left == NULL && root->right==NULL) return result ;

        //left right lao apna 
        string LEFT = tree2str(root->left);
        string RIGHT = tree2str(root->right);

        if(root->left== NULL) return result + "()" +"("+ RIGHT +")";
        if(root->right ==NULL) return result + "(" + LEFT+ ")";

        return  result + "(" + LEFT +")"+ "("+ RIGHT + ")";
        
    }
};