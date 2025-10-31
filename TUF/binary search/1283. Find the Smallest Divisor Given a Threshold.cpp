#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sum(vector<int>& nums, int mid){
        int s= 0;
        for(auto &it: nums){
            s+= ceil((double)it/mid);
        }
        return s;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int  n = nums.size();
        int r = *max_element(nums.begin(), nums.end());
        int l=1; 
        while(l<=r){
            int mid = l+(r-l)/2;
            if(sum(nums,mid) <=threshold){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
        
    
};