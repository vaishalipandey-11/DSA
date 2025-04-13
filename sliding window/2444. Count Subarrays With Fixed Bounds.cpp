#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // we just need 3 things , minpos , maxpos , culpret index 
        long long ans =0;
        int minP = -1 ;
        int maxP = -1 ;
        int Ci =-1;
        for(int i =0 ; i<nums.size() ; i++){
            if(nums[i]< minK || nums[i]>maxK){
                Ci = i;
            }
            if(nums[i]==maxK){
                maxP = i;
            }
            if(nums[i]== minK){
                minP = i;
            }
             
             // if the count is neg means culpret index is in between 
             // min and max position okay
             
            int count = min(minP , maxP ) - Ci ;
            ans += (count<=0 ) ? 0: count ;   // at that moment the subarray is n valid 
        }
        return ans ;
    }
};