
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

class Solution {
public:
    void inordertraversal(TreeNode* root , string &s){
        if(root==NULL)  return ;
         if(root->left==NULL && root->right==NULL){
            s+=to_string(root->val)+"_";
         }   
         inordertraversal(root->left,s);
         inordertraversal(root->right,s);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 ="";
        string s2 = "";
        inordertraversal(root1, s1);
        inordertraversal(root2,s2);

        return s1 == s2;
    }
};