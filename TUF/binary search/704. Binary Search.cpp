#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0 ; int r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]< target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};


class Solution {
public:
    int bs(vector<int>& nums , int low , int high , int target){
        if(low > high ) return -1; // bc
        int mid = (low+high)/2;

        if(nums[mid]==target) return mid;
        else if(nums[mid]< target){
           return  bs(nums , mid+1 , high, target );
        }
        else
          return   bs(nums, low , mid-1 , target);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;  int high = n-1;
       return bs(nums,low , high, target);
    }
};