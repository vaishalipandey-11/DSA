#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void dfss(vector<vector<int>>& adj , int u , vector<int>&visited , vector<int>&ans){
       if(visited[u]) return;
       visited[u]=true;
       ans.push_back(u);
       
       for(auto &v : adj[u]){
           if(!visited[v]){
               dfss(adj , v , visited,ans);
           }
       }
       
   }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
      vector<int>ans;
      vector<int>visited(adj.size() , false);
      
      dfss(adj , 0 , visited,ans);
      return ans;
    }
};