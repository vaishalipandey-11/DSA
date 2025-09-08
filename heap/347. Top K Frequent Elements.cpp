
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int n = nums.size();
      unordered_map<int,int>mp;
      for(auto & it : nums){
        mp[it]++;
      }
 
     priority_queue<pair<int,int>>pq;
     for(auto &it :mp){
        pq.push({it.second, it.first});
     }
  
      vector<int>ans;
     while(k!=0){
        auto freq = pq.top().second;
        pq.pop();
        ans.push_back(freq); 
        k--;
     }
     return ans;

    }
};