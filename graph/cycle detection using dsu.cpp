    #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;
class Solution {
  public:
  int find(int i , vector<int>&parent){
      if(i == parent[i]) return i ;
      return parent[i] = find(parent[i] , parent);
  }
  
   void Union(int i , int j , vector<int>&rank , vector<int>&parent){
       int ip = find(i , parent);
       int jp = find(j, parent);
       
       if(ip == jp) return ;
      
        if(rank[ip] == rank[jp] ) {
            parent[ip]= jp;  
            rank[jp]++;
            
        }
        else if(rank[ip]>rank[jp]){ 
            parent[jp]= ip;
            
        }
        else {
            parent[ip] = jp;
            
        }
   }
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
       vector<int>parent(V);
       vector<int>rank(V,0);
       
       for(int i=0 ; i<V ; i++) parent[i]= i;
       
       for(int u=0 ; u<V ; u++){
           
            for(auto &v : adj[u]){
                
              if(u<v){
                  int up = find(u , parent);
                   int vp = find(v,parent);
                   if(up == vp ) return 1;
                 }
             Union(u , v , rank , parent);
       }
       
       }
       return 0;
    }
    
};