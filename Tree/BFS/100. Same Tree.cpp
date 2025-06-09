
 
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
#include <queue>
// This code checks if two binary trees are the same using BFS (Breadth-First Search).

class Solution {
public:
        // here we are doing bfs okay 
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if(p==NULL && q==NULL) return true; // cases 
      if(p==NULL || q==NULL) return false;
      
      queue<TreeNode*>q1,q2;
      
      q1.push(p);
      q2.push(q);

      while(!q1.empty() && !q2.empty() ){
        TreeNode* Node1 = q1.front() ;q1.pop();
        TreeNode* Node2= q2.front() ; q2.pop();

        if(Node1->val != Node2->val) return false ;

        if(Node1->left && Node2->left){
            q1.push(Node1->left);
            q2.push(Node2->left);
        }else if(Node1->left || Node2->left ){
            return false;
        }

        if(Node1->right && Node2->right){
            q1.push(Node1->right);
            q2.push(Node2->right);
        }else if(Node1->right || Node2->right){
            return false ;
        }

      }
      return true;
        
    }
};