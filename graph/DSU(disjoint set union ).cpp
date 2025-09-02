    #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;

    int find(int par[], int i) {
        if(i == par[i]) return i;
        return find(par, par[i]);
    }
    
    void unionSet(int par[], int i, int z) {
        int i_parent = find(par , i);
        int y_parent = find(par, z);
        if(i_parent != y_parent){
            par[i_parent ] = y_parent;
        }
       
    }
    // PATH COMPRESSION AND RANK COMPRESSION

   int findd(int i, vector<int> &parent) {
    if (i == parent[i]) return i;
    return parent[i] = findd(parent[i], parent); // path compression
}

void unionn(vector<int> &parent, int i, int j, vector<int> &rank) {
    int i_parent = findd(i, parent);
    int j_parent = findd(j, parent);
    if (i_parent == j_parent) return;

    if (rank[i_parent] == rank[j_parent]) {
        parent[i_parent] = j_parent;
        rank[j_parent]++;
    } else if (rank[i_parent] < rank[j_parent]) {
        parent[i_parent] = j_parent;
    } else {
        parent[j_parent] = i_parent;
    }
}
