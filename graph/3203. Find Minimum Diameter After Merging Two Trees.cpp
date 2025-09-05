
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    pair<int, int> farthestnode(int source, unordered_map<int, vector<int>>& adj) {
        unordered_map<int ,bool> visited;
       int farthest = source ;
        queue<int> q;
        q.push(source);
        visited[source] = true;
        int dist = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
               int u = q.front();
                farthest = u;
                q.pop();
                for (auto& v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            if(!q.empty()){
                dist++;
            }
            
        }
        return {dist , farthest};
    }
    unordered_map<int, vector<int>> makeadj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {

                                    
        auto adj1 = makeadj(edges1);
        auto adj2 = makeadj(edges2);
        
        auto [dist1, node1] = farthestnode(0, adj1);
        auto [diam1, node2] = farthestnode(node1, adj1);

        auto [dist2, node3] = farthestnode(0, adj2);
        auto [diam2, node4] = farthestnode(node3, adj2);

        return max({((diam1 + 1) / 2) + ((diam2 + 1) / 2) + 1, diam1, diam2});
    }
};