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

//by bfs traversal
#include <bits/stdc++.h>
using namespace std;
//here we are using bfs traversal to find the bottom left value of the tree by traversing right first then left


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
       queue<TreeNode* >q;
       q.push(root);
       int bottomleft ;

       while(!q.empty()){
       
        int n = q.size();

        while(n--){
             TreeNode* node = q.front();
             q.pop();
             bottomleft = node->val;

             if(node->right) q.push(node->right);
             if(node->left) q.push(node->left);
             
             
        }
       } 
       return bottomleft;
    }
};