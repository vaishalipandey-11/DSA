
 struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
#include <queue>
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int currlvl =1;

        if(!root->left && !root->right ) return 1 ;

        queue<TreeNode* >q ;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
           
            while(n--){

                 TreeNode* node = q.front();
                 q.pop();

                if(!node->left && !node->right){
                    return currlvl;
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            currlvl++;
        }
        return -1;
    }
};