
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0) return false ;
        unordered_map<int,int>mp;
        for(int i=0 ; i<n ; i++){
            mp[ nums[i]]++;
        }
        int groups = n/k;
        for(auto & it : mp){
            if(it.second > groups) return false;
            // if((it.second >1)  && (k==n) ) return false;
        }

        return true;
        
    }
};