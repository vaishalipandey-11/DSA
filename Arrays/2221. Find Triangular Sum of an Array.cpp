#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];
        vector<vector<int>>solve(n , vector<int>(n, 0));
        for(int i=0 ; i<n ; i++){
            solve[0][i]= nums[i];
        }
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<n-1 ; j++){
                solve[i][j]= (solve[i-1][j] + solve[i-1][j+1])%10 ;
            }
        }
        return solve[n-1][0];
        
    }
};


class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];
        int m =n;
        for(int i=0 ; i<n-1 ; i++){
           m--;
            for(int j=0 ; j<m ; j++){
               nums[j]= (nums[j]+nums[j+1])%10;
            }
        }
        return nums[0];
        
    }
};