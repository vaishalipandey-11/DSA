#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool topodfs(int u, vector<bool>& vis, unordered_map<int, vector<int>>& adj,
                 stack<int>& st, vector<bool>& inrec) {
        vis[u] = true;
        inrec[u] = true;
        for (auto& v : adj[u]) {
            if (!vis[v]) {
                if (!topodfs(v, vis, adj, st, inrec))
                    return false;
            } else if (inrec[v]) {

                return false;
            }
        }
        inrec[u] = false;
        st.push(u);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (auto& i : prerequisites) {
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);
        }

        stack<int> st;
        vector<bool> vis(numCourses, false);
        vector<bool> inrec(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
              if(!topodfs(i, vis, adj, st, inrec)) return {};
            }
        }
        vector<int> res;

        while (!st.empty()) {
            int i = st.top();

            st.pop();
            res.push_back(i);
        }

        return res;
    }
};