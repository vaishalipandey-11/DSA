#include <vector>
using namespace std;    
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// This code implements Morris Inorder Traversal for a binary tree.
// It uses O(1) space and O(n) time complexity, where n is the number of nodes in the tree.
// The algorithm modifies the tree structure temporarily to create threads for traversal without using a stack or recursion.
// The main idea is to find the inorder predecessor of each node and create a temporary link to it, allowing us to traverse the tree without using additional space.
// After visiting a node, the temporary link is removed, restoring the original tree structure.
// This approach is efficient for large trees where space complexity is a concern.
// The algorithm works as follows:  
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        TreeNode* pre;

        // Traverse the tree
        while (curr != nullptr) {

            // Case 1: If left child is null, visit current node and go to right
            if (curr->left == nullptr) {
                result.push_back(curr->val); // Visit the current node
                curr = curr->right;          // Move to the right child
            } 
            // Case 2: Left child exists, so find the inorder predecessor
            else {
                pre = curr->left;

                // Find the rightmost node in the left subtree (inorder predecessor)
                while (pre->right != nullptr) {
                    pre = pre->right;
                }

                // Make current as the right child of its predecessor (threading)
                pre->right = curr;

                // Store current node, move to left child, and break the left link
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr; // Remove the left child to avoid revisiting
            }
        }

        return result;
    }
};
