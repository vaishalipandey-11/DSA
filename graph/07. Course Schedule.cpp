#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    bool dfs(int u , vector<bool>&vis , unordered_map<int, vector<int>>&adj , vector<bool>&inrec){
        vis[u]=true;
        inrec[u]=true;
        for(auto &v: adj[u]){
            if(!vis[v]){
                if(!dfs(v,vis, adj  , inrec)) return false;
            }else if(inrec[v]){
                return false;
            }
        }
        inrec[u]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>>adj ;
        for(auto &i : prerequisites){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }

        vector<bool>vis(numCourses, false);
        vector<bool>inrec(numCourses, false);

        for(int i =0 ; i<numCourses ; i++){
            if(!vis[i] && !dfs(i, vis, adj , inrec)){
                return false;
            }
        }
        return true;

    }
};