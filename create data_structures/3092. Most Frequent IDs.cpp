
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
typedef long long ll;

    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<ll , ll> mp;
        priority_queue<pair<ll,ll>> pq;
        vector<ll > result(n,0) ;

        for (int i = 0; i < n; i++) {
            mp[nums[i]] += freq[i];
            pq.push({mp[nums[i]], nums[i]});

            // Clean stale entries
            while (!pq.empty() && pq.top().first != mp[pq.top().second]) {
                pq.pop();
            }

            result[i] = pq.empty() ? 0 : pq.top().first;
        }
        return result;
    }
};