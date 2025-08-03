#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
       
        int closest = nums[0] +nums[1]+ nums[2];
        for(int i =0 ; i<n-2 ; i++){
            int l = i+1 , r = n-1;

            while(l<r){
               
               int sum = nums[i]+nums[l] +nums[r];
               if(abs(target-sum)<abs(target-closest)){
                closest = sum;
               }

                if(sum == target){
                  return target;
                }else if(sum < target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return closest;
    }
};