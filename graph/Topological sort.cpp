//topological sort using dfs 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
      public:
        void dfstopo(int u , vector<bool>&vis ,  unordered_map<int ,vector<int>>&adj,  stack<int>&st){
            vis[u]=true;
           for(auto &v : adj[u] ){
               if(!vis[v]){
                   dfstopo(v,vis,adj,st);
               }
           } 
            st.push(u);
        }
        vector<int> topoSort(int V, vector<vector<int>>& edges) {
            unordered_map<int ,vector<int>>adj;
            for(auto &i : edges){
                int u = i[0];
                int v= i[1];
                adj[u].push_back(v);
            }
            
            stack<int>st;
            vector<bool>vis(V,false);
            
            for(int i=0 ; i<V ; i++){
                if(!vis[i] ){
                    dfstopo(i, vis , adj , st);
                } 
            }
            
            vector<int>res;
            while(!st.empty()){
                int u = st.top();
                res.push_back(u);
                st.pop();
            }
            
            return res;
            
        }
};

//topological sort using bfs called khan's algorithm