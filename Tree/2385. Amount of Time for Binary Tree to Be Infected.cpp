
#include <unordered_map>
#include <unordered_set>        
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// This code implements a solution to the problem of finding the amount of time it takes for a binary tree to be infected starting from a given node.
// It uses a breadth-first search (BFS) approach to traverse the tree and count the
// number of minutes it takes for the infection to spread to all nodes.
// The algorithm constructs an adjacency list representation of the tree, where each node is connected to its parent and its children.
// It then uses a queue to perform BFS, starting from the infected node,
// marking nodes as visited to avoid revisiting them.
// The time complexity of this solution is O(n), where n is the number of nodes in the tree.
// The space complexity is also O(n) due to the adjacency list and the queue used
// for BFS traversal.
class Solution {
public:
     void convert(TreeNode* current , int parent , unordered_map<int,      vector<int>>&adj){
        if(!current) return ;

        if(parent != -1){
            adj[current->val].push_back(parent);
        }
        if(current->left){
            adj[current->val].push_back(current->left->val);
        }
        if(current->right){
            adj[current->val].push_back(current->right->val);
        }
        convert(current->left , current->val , adj);
        convert(current->right, current->val , adj);

     }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>>adj ;
        convert(root, -1 , adj);

        queue<int>que;
        que.push(start);
        unordered_set<int>visited;
        visited.insert(start);
        int minutes =0;

        while(!que.empty()){
            int n = que.size();

            while(n--){
                int curr= que.front();
                que.pop();

                for(int &x : adj[curr]){
                    if(visited.find(x) == visited.end()){
                        que.push(x);
                        visited.insert(x);
                    }
                }
            }
            minutes ++;
        }
        return minutes-1;
    }

};