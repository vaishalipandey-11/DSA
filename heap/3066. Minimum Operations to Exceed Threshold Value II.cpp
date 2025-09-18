
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long long, vector<long long> , greater<long long>> pq;

        for(auto &it:nums){
            pq.push(it);
        }
        int count =0;
        while(pq.top()<k){
            long long x = pq.top(); pq.pop();
            long long y =pq.top() ; pq.pop();
            pq.push(min(x, y) * 2 + max(x, y));
            count++;
        }
        return count;


    }
};