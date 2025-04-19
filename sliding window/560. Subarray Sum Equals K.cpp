#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n =nums.size();
        int count =0;
        for(int i=0 ; i<n ; i++){
            int sum =0;
            for(int j =i ; j<n ; j++){
                sum += nums[j];
                if(sum == k ) count ++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        int count =0;
        int currsum =0;
        mp[0] = 1;

        for(auto &num : nums){
            currsum += num;
            if(mp.find(currsum -k) != mp.end()){
                count += mp[currsum -k] ;
            }
            mp[currsum ]++;
        }
        
        return count ;
    }
};