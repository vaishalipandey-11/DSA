#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
      
    long long countSubarrays(vector<int>& nums, int k) {
        int maxe = *max_element(nums.begin(), nums.end());
        int i =0 ; 
        int j =0 ;
        int n = nums.size();
        long long result = 0;
        int count =0;
        while(j<n){
            
            if(nums[j]==maxe){
                count++;
            }
            while(count>=k){
               result+=(n-j);
               if(nums[i]==maxe){
               
                count--;
               }
                i++;
            }
         
            j++;
        }
        return result;
    }
};