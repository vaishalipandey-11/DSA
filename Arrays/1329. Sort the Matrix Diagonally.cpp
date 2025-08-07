#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
         int n = mat.size();
         int m = mat[0].size();
         unordered_map<int , vector<int>>mp;
         for(int i =0 ; i<n ; i++){
            for(int j =0; j<m ; j++){
                mp[i-j].push_back(mat[i][j]);
            }
         }

         for(auto &it :mp){
            
            sort( it.second.begin(),  it.second.end());
            reverse(it.second.begin(), it.second.end());
         }

         for(int i =0; i<n ; i++){
            for(int j = 0 ;j <m ; j++){
                int val = mp[i-j].back();
                mat[i][j]=val;

                mp[i-j].pop_back();
            }
         }
         return mat;
    }
};

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
         int n = mat.size();
         int m = mat[0].size();
         unordered_map<int , vector<int>>mp;
         for(int i =0 ; i<n ; i++){
            for(int j =0; j<m ; j++){
                mp[i-j].push_back(mat[i][j]);
            }
         }

         for(auto &it :mp){
            
            sort( it.second.begin(),  it.second.end());
         }

         for(int i =n-1 ; i>=0 ; i--){
            for(int j = m-1 ;j>=0 ; j--){
                int val = mp[i-j].back();
                mat[i][j]=val;

                mp[i-j].pop_back();
            }
         }
         return mat;
    }
};