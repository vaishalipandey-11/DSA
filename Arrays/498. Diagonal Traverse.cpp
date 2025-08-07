
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
      int n = mat.size();
      if(n==0) return {};
      int m = mat[0].size();

      vector<int>result;
      map<int,vector<int>>mp;

      for(int i =0 ; i <n ; i++){
        for(int j =0 ; j<m ; j++){
            mp[i+j].push_back(mat[i][j]);
        }
      }

      bool flag = true;
      for(auto &it : mp){
       if(flag){
        reverse(it.second.begin(), it.second.end());
       }

       for(auto &val : it.second){
         result.push_back(val);
       }

        flag = !flag;
      }
      return result ;
    }
};