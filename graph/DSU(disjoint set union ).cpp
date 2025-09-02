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

    // PATH COMPRESSION 
    int findd(int i , vector<int>parent){
        if(i==parent[i]) return i;
        return parent[i]= findd(parent[i] , parent);

    }

    //union compression dsu