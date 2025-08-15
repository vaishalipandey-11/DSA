
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n =grid.size();
        int m =grid[0].size();
        unordered_map<int,vector<int>>mp;

        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }

        for(auto &it : mp){
            if(it.first < 0){
                sort(it.second.begin(),it.second.end());
                reverse(it.second.begin(),it.second.end());
            }else{
                sort(it.second.begin(),it.second.end());
            }
        }

       
        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                int val = mp[i-j].back();
               grid[i][j]=val;
               mp[i-j].pop_back();
            }
        }
        return grid;
        
    }
};