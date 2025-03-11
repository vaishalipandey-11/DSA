#include <bits/stdc++.h>
using namespace std;
// by reversing parts 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k= k% n; // check k 
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k ,nums.end());
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int  n = nums.size();
        vector<int>v(n);
        for(int i =0 ; i<n ; i++){
            int idx = (i+k)%n;
            v[idx]= nums[i];
        }
        nums = v;
        
    }
};