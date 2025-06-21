
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
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    unordered_map<TreeNode* , TreeNode*>parent;
    void addparent( TreeNode* root){
        if(!root) return;

        if(root->left ) parent[root->left]=root;
        addparent(root->left);

        if(root->right) parent[root->right] = root;
        addparent(root->right);
    }

    void kdist(TreeNode* target , int k , vector<int>& result ){
         queue<TreeNode*>q;
         q.push(target);

         unordered_set<int>visited;
         visited.insert(target->val);

         while(!q.empty()){
            int n = q.size();
            if(k==0) break;

            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !visited.count(curr->left->val)){
                     q.push(curr->left);
                     visited.insert(curr->left->val);
                }
                if(curr->right && !visited.count(curr->right->val)){
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                if(parent.count(curr ) && !visited.count(parent[curr]->val)){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);

                } 
            }
            k--;
         }

            while(!q.empty()){
                TreeNode* x = q.front();
                q.pop();
                result.push_back(x->val);
            }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>result ;
        addparent(root);
        kdist(target , k , result);
        return result;


    }
};