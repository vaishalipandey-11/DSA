struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
   #include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:

int maxsteps;
    void solve(TreeNode* root , int stepcount , bool goleft ){
        if(!root) return ;

          maxsteps = max(stepcount , maxsteps );

        if(goleft == true ){//agr left jana tha
            solve(root->left , stepcount +1 , false);// aap left gaye to +1 and next time right jaoge so false ;
            solve(root->right , 1 , true);
        }else{// left nhi right jana h 
            solve(root->right , stepcount+1 , true );
            solve(root->left , 1 , false );
        }
    }
    int longestZigZag(TreeNode* root) {
       
        solve(root , 0 , true );
        solve(root , 0 , false);
        return maxsteps;
    }
};
//Approach-2 (Keeping track of left and right count)
class Solution {
public:
    int maxPath = 0;
    
    void solve(TreeNode* root, int left, int right) {
        if(!root)
            return;
        
                
        maxPath = max({maxPath, left, right});
        
        
        solve(root->left, right+1, 0);
        solve(root->right, 0, left+1);
        
    }
    
    int longestZigZag(TreeNode* root) {
        
        solve(root, 0, 0);
        
        return maxPath;
        
    }
};


//Approach-3 (Returning pair of left and right length)
class Solution {
public:
    
    int maxPath = 0;
    
    vector<int> solve(TreeNode* root) {
        if(root == NULL)
            return {0, 0};
        
        vector<int> reL = solve(root->left);
        vector<int> reR = solve(root->right);
        
        int L = reL[0];
        int R = reR[1];
        
        maxPath = max({maxPath, L, R});
        
        return {R+1, L+1};
    
    }
    
    int longestZigZag(TreeNode* root) {
        solve(root);
        return maxPath;
    }
};