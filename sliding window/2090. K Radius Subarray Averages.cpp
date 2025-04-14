#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n =  nums.size();
         vector<int > ans(n , -1);
         if(k==0 ) return nums ;
         if(n < 2*k+1) return ans ;
         long long  sum =0 ;
         int wsize  = 2*k+1;
         for(int i =0 ; i<wsize ; i++){
            sum += nums[i];
         }

         ans[k] = sum / wsize;

         for(int i = k+1 ; i< n-k ; i++){
            sum -= nums[i-k-1];
            sum +=nums[i+k];
            ans[i ] = sum/wsize;
         }
         return ans ;
    }
};