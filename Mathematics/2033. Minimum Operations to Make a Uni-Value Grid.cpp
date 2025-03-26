#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size() , n =grid[0].size();
        vector<int>v;
        for(int i =0 ; i<m ; i++){
            for(int j =0 ; j<n ; j++){
                v.push_back(grid[i][j]);
            }
        }
        int L = v.size();
       
        nth_element(v.begin() , v.begin()+L/2 , v.end());
         int target =v[L/2];

        int ans =0;
        for(auto &num  : v){
            if(num%x != target%x)
            {
                 return -1;
            }

            ans +=abs(target-num )/x;
        }
        return ans ;
    }
};