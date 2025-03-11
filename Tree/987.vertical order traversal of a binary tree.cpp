#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>
#include<queue>

#include<map>

 
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //vector for answer
        vector<vector<int>>ans;
        // queue of lvl order traversal
        queue<pair<TreeNode* , pair<int , int >>>q;
        // pushing root ele to q
        q.push({root, {0,0}});
        //creating a data structure for storing values 
        map<int ,map<int , multiset<int>>>mp;
        // here multiset is used for storing ordered duplicate values 
        //queue traversal
        while(!q.empty()){
            auto front = q.front(); q.pop(); //using stl
            TreeNode* node = front.first;
            auto coordinate = front.second;
            // kind of destructing
            int&row = coordinate.first;
            int&col = coordinate.second;
            mp[col][row].insert(node->val);
            // pushing childs further into q if available
            if(node->left)
                    q.push({node->left, {row+1 ,col-1}});
            if(node->right)
                    q.push({node->right , {row+1, col+1}});         
        }
  
        // iterate over the map for further answer 
        // Iterates over each key-value pair
        for(auto it :mp){
            // colMap is a reference to it.second, which is another map.
            auto&colMap = it.second;
            // Declares a temporary vector<int> named vline to store all values.
            vector<int>vline;
            // Iterates over each key-value pair in colMap.
            for(auto colMapIt : colMap){
                // mset is a reference to colMapIt.second, which is a multiset<int>.
                auto&mset = colMapIt.second;
                // Inserts all elements from mset at the end of vline.
                vline.insert(vline.end(), mset.begin(), mset.end());
            }
            // Adds vline (which now contains elements from all msets) to ans.
            ans.push_back(vline);

        }
        return ans;

    }
};




class Solution {
public:

    void traverse(TreeNode* root, map<int, vector<pair<int,int>>>& m, int level, int col){
        if(root == nullptr){
            return ;
        }

        if(m.find(col) == m.end()){
            vector<pair<int,int>> temp;
            temp.push_back({ root->val, level });
            m[col] = temp;
        }else{
            m[col].push_back({ root->val, level });
        }

        traverse(root->left, m,  level + 1, col - 1);
        traverse(root->right, m, level + 1, col + 1);
    }

    bool static compare(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second ;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result ; 
        if(root == nullptr){
            return result ;
        }

        map<int, vector<pair<int,int>>> m ; 
        traverse(root, m, 0, 0);

        for(auto item : m){
            int col = item.first ; 
            vector<pair<int,int>> ans = item.second; 
            sort(ans.begin(), ans.end(), compare);
            vector<int> temp;
            for(auto val : ans){
                temp.push_back(val.first);
            }
            result.push_back(temp);
        }

        return result ; 
    }
};
