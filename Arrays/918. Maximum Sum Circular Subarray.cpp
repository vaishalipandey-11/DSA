#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int n ;

    int Sum( vector<int>&nums){
       int sum =nums[0];
       for(int i=1 ;i<n ; i++){
        sum+= nums[i];
       }
       return sum ;
    }

    int kadanes_min(vector<int>&nums){
        int c_s =nums[0];
        int m_s= nums[0];
        for(int i=1 ; i<n ; i++ ){
            c_s = min(nums[i], c_s+nums[i]);
            m_s = min(m_s,c_s);
        }
        return m_s;
        
    }

    int kadanes_max(vector<int>&nums){
        int c_s = nums[0];
        int m_s = nums[0];
        for(int i=1 ; i<n ; i++){
            c_s = max(nums[i], c_s+nums[i]);
            m_s = max(m_s, c_s);
        }
        return m_s;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        n = nums.size();
        if(kadanes_max(nums) > 0){
            return max(kadanes_max(nums) ,(Sum(nums)-kadanes_min(nums)) );
        }
            return kadanes_max(nums);
        
        
    }
};


class Solution {
public:
    int n;
    int kadanes(vector<int>& nums) {

        int m_s = nums[0];
        int c_s = nums[0];
        for (int i = 1; i < n; i++) {
            c_s = max(nums[i], c_s + nums[i]);
            m_s = max(m_s, c_s);
        }
        return m_s;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        n = nums.size();
        int ans = INT_MIN;

        for (int r = 0; r < n; r++) {

            ans = max(ans, kadanes(nums));
            rotate(nums.begin(), nums.begin() + 1, nums.end());
        }
        return ans;
    }
};

class Solution {
public:
    int n;
    int kadanes(vector<int>& nums) {

        int m_s = nums[0];
        int c_s = nums[0];
        for (int i = 1; i < n; i++) {
            c_s = max(nums[i], c_s + nums[i]);
            m_s = max(m_s, c_s);
        }
        return m_s;
    }
    void rotate(vector<int>&nums){
        int first = nums[0];
        for(int i=0 ; i<n-1 ; i++){
            nums[i] = nums[i+1];
        }
        nums[n-1]= first;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        n = nums.size();
        int ans = INT_MIN;

        for (int r = 0; r < n; r++) {

            ans = max(ans, kadanes(nums));
             rotate(nums);
        }
        return ans;
    }
};