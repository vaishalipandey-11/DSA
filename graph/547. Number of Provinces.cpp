#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, vector<int>& vis, int u) {
        vis[u] = true;
        for (auto& v : adj[u]) {
            if (!vis[v]) {
                dfs(adj, vis, v);
            }
        }
    }
    int n;

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        // lets create adj list from matrix
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, false);
        // dsf call for each node
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adj, vis, i);
                count++;
            }
        }
        return count;
    }
};