// User function Template for C++

// A Tree node
struct Node
{
    int key;
    struct Node *left, *right;
    Node(int x) : key(x), left(nullptr), right(nullptr) {}
};

#include <vector>
using namespace std;    
class Solution {
  public:
   vector<vector<int>>result;
   void solve(vector<int>temp , int sum , int curr_sum , Node* root){
       if(!root) return ;
       
       curr_sum += root->key;
       temp.push_back(root->key);
       
       if(curr_sum == sum){
           result.push_back(temp);
       }
       
       solve(temp , sum , curr_sum , root->left);
       solve(temp , sum , curr_sum , root->right);
       
       temp.pop_back();
   }
    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<int>temp ;
        solve(temp , sum , 0 , root);
        return result ;
    }
};