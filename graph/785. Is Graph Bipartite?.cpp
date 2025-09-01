#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkdfs(unordered_map<int,vector<int>>&adj, vector<int>&clr , int u , int currclr){
        clr[u]=currclr;
        for(auto &v : adj[u]){
            if(clr[v]==currclr) return false ;
            if(clr[v]==-1){
                clr[v]=1-currclr;
            
                if(checkdfs(adj , clr , v, 1-currclr)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int  V = graph.size();
        unordered_map<int,vector<int>>adj;
        // for(int i=0 ; i<V ; i++){
        //     for(auto &v : graph[i]){
        //         adj[i].push_back(v);
        //     }
        // }
        for(int i =0 ;i<V ; i++){
            adj[i]=graph[i];
        }

        vector<int>clr(V,-1);
        int currclr =0;

        for(int i=0 ; i<V ; i++){
            if(clr[i] ==-1){
                if(checkdfs(adj , clr , i , currclr)==false) return false;
            }
        }
        return true;

        
    }
};

// using bfs as well
class Solution {
public:
    bool checkbfs(unordered_map<int, vector<int>>& adj, vector<int>& clr,
                  int currnode, int currclr, queue<int>& q) {
        clr[currnode] = currclr;
        q.push(currnode);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {
                if (clr[v] == currclr)
                    return false;
                if (clr[v] == -1) {
                    clr[v] = 1 - currclr;

                    if (checkbfs(adj, clr, v, 1 - currclr,q) == false)
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        unordered_map<int, vector<int>> adj;
       
        for (int i = 0; i < V; i++) {
            adj[i] = graph[i];
        }

        vector<int> clr(V, -1);
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (clr[i] == -1) {
                if (checkbfs(adj, clr, i, 0,q) == false)
                    return false;
            }
        }
        return true;
    }
};