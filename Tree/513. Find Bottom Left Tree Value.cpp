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
  int maxdepth;
  int result ;

void dfs(TreeNode* root , int currdepth ){
    if(!root) return ;

    if(currdepth >maxdepth  ){
        maxdepth = currdepth;
        result = root->val;
    }

    dfs(root->left, currdepth+1 ) ;
    dfs(root->right , currdepth+1);


}
    
    int findBottomLeftValue(TreeNode* root) {
         maxdepth =-1;
        dfs(root , 0);
        return result ;
        
    }
};