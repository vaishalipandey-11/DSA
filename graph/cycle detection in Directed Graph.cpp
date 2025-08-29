#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int u, vector<bool>& vis, vector<bool>& inrecc, unordered_map<int, vector<int>>& adj) {
        vis[u] = true;
        inrecc[u] = true;

        for (auto &v : adj[u]) {
            if (!vis[v] && dfs(v, vis, inrecc, adj)) {
                return true;
            } else if (inrecc[v]) { // back edge found
                return true;
            }
        }

        inrecc[u] = false; // remove from recursion stack after exploring all neighbors
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (auto &i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v); // directed graph
        }

        vector<bool> vis(V, false);
        vector<bool> inrecc(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i] && dfs(i, vis, inrecc, adj)) {
                return true;
            }
        }
        return false;
    }
};


// step-by-step DFS:
// 0 → 1 → 2 ↘
// ↑         ↓
// └─────────┘
// 3

// Start with node 0:
// vis[0] = true, inrecc[0] = true
// Explore neighbor 1
// DFS(1):
// vis[1] = true, inrecc[1] = true
// Explore neighbor 2
// DFS(2):
// vis[2] = true, inrecc[2] = true
// Explore neighbor 0
// 0 is already visited and also in recursion stack (inrecc[0] = true) → Cycle detected! ✅
// At this point, the function returns true up the call stack, so we stop.

// Step-by-step DFS:
// 0 → 1 → 2 → 3

// Start with node 0:
// vis[0] = true, inrecc[0] = true
// Explore neighbor 1
// DFS(1):
// vis[1] = true, inrecc[1] = true
// Explore neighbor 2
// DFS(2):
// vis[2] = true, inrecc[2] = true
// Explore neighbor 3
// DFS(3):
// vis[3] = true, inrecc[3] = true
// No neighbors → backtrack
// inrecc[3] = false
// Backtracking continues:
// inrecc[2] = false
// inrecc[1] = false
// inrecc[0] = false
// No back edge found, so the function eventually returns false ✅.