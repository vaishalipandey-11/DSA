#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int numXor = 0;
        for(auto &num : nums){
            numXor ^= num;
        }
        return __builtin_popcount( numXor ^ k);
        
    }
};