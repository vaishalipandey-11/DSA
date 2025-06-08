
 
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
class Solution {
public:
   long M = 1e9+7;
   long totalTreesum = 0; // total sum 
   long maxp = 0;

   // total sum of the tree
   int totalSum(TreeNode* root){

    if(root ==nullptr) return 0;

    int leftsubtreesum = totalSum(root->left );
    int rightsubtreesum = totalSum(root->right);
    int sum = root->val + leftsubtreesum + rightsubtreesum ;

    maxp = max(maxp, (totalTreesum - sum)*sum);
    return sum;

   }
    int maxProduct(TreeNode* root) {
       if(root==nullptr) return 0;
         
         maxp =0 ;
         totalTreesum = totalSum(root);
         totalSum(root);
         return maxp%M;

    }
};