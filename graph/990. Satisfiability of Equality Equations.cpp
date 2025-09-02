 #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;
    
class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i], parent);
    }

    void Union(int i, int j, vector<int>& rank, vector<int>& parent) {
        int ip = find(i, parent);
        int jp = find(j, parent);
        if (ip == jp) return;

        if (rank[ip] == rank[jp]) {
            parent[ip] = jp;
            rank[jp]++;   
        }
        else if (rank[ip] > rank[jp]) {
            parent[jp] = ip;
        }
        else {
            parent[ip] = jp;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26, 0);

        for (int i = 0; i < 26; i++) parent[i] = i;

        for (auto &it : equations) {
            if (it[1] == '=') {
                int u = it[0] - 'a';
                int v = it[3] - 'a';
                Union(u, v, rank, parent);
            }
        }

        for (auto &it : equations) {
            if (it[1] == '!') {
                int u = it[0] - 'a';
                int v = it[3] - 'a';

                if (find(u, parent) == find(v, parent)) {
                    return false;  
                }
            }
        }
        return true;
    }
};
