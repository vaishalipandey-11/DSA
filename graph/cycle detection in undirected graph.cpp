#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// we have parent agr samne wala parent h toh  nhi jana h waha continue kro 
// agr vo parent nhi h toh please check kro ki kahi vo visited toh nhi h agr h toh cycle h else nhi h 
class Solution {
      public:
      bool iscycledfs(int u , vector<bool>&vis , unordered_map<int , vector<int>>&adj , int parent  ){
       
         vis[u] = true ;
         for(auto &v : adj[u]){
             if(v==parent ) continue;
             if(vis[v]) return true;
             if(iscycledfs(v , vis , adj , u)){
                 return true ;
             }
         }
         return false;
          
      }
        bool isCycle(int V, vector<vector<int>>& edges) {
            vector<bool>vis(V,false);
            
            unordered_map<int , vector<int>>adj;
            
            for(auto &i : edges){
                int u = i[0];
                int v= i[1];
                
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            
            for(int i=0; i<V ; i++){
                if(!vis[i] && iscycledfs(i , vis , adj ,-1)){
                    return true;
                }
            }
            return false;
            
            
             
        }
};