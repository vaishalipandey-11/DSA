
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int count =0;
        unordered_map<int,int>mp;
        mp[0]=1;

        int currsum =0;
        for(int i =0 ; i<n ; i++){
            currsum+=nums[i];
            int rem = currsum%k;
            if(rem <0) rem +=k;

            if(mp.find(rem) != mp.end()){//past me dekha h 
            count += mp[rem];
            mp[rem]++;

            }
            else{
                mp[rem]++;
            }

        }
        return count ;
    }
};

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
       
        for (int i = 0; i < n; i++) {
             int sum = 0;
            for (int j = i; j < n; j++) {
                sum +=nums[j];
                if(sum%k==0) ans++;             
            }
        }
        return ans;
    }
};