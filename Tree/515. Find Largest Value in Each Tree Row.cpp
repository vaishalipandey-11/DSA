
#include <vector>
#include <queue>
#include <limits.h> 
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
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        queue<TreeNode*>q;

        if(!root) return {};

        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int maxele = INT_MIN;

            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                maxele= max(maxele, curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
            res.push_back(maxele);
        }
        return res;
    }
};