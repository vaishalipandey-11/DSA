  #include <vector>
#include <iostream>
#include <unordered_map>
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
    int ans = 0;

    void solve(vector<int>& count, TreeNode* root) {
        if (root) {
            count[root->val]++;
        }

        // Leaf node reached
        if (!root->left && !root->right) {
            int oddfreq = 0;

            // Count digits with odd frequency
            for (int i = 0; i <= 9; i++) {
                if (count[i] % 2 != 0) {
                    oddfreq++;
                }
            }

            // A pseudo-palindrome can have at most one odd count
            ans += (oddfreq <= 1);
        }

        // DFS to children
        if (root->left) solve(count, root->left);
        if (root->right) solve(count, root->right);

        // Backtrack the current node’s effect before returning
        count[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> count(10, 0);  // Digits 1–9
        solve(count, root);
        return ans;
    }
};
