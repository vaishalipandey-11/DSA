
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 
class Solution {
public:
    typedef pair<long long, long long> p;
    long long findScore(vector<int>& nums) {

        long long n = nums.size();

        priority_queue<p, vector<p>, greater<p>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        long long sum = 0;
        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();
            if (nums[idx] != -1) {
                sum += num;
                nums[idx] = -1;
                if (idx-1 >=0) {
                    nums[idx - 1] = -1;
                }
                if (idx+1 < n) {
                    nums[idx + 1] = -1;
                }
            }
        }
        return sum ;
    }
};