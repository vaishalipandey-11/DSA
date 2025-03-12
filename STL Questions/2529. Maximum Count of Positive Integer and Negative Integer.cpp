#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int  n = nums.size();
        int p = lower_bound(nums.begin(), nums.end(), 1)-nums.begin(); // index of 1st positive
        int N = lower_bound(nums.begin(), nums.end(),0 )-nums.begin(); // index of last neg which is a count 
     
        // get the count of p by sub 
        return max(n-p , N);
            }
};
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto p = [] (int nums){
            return nums >0;
        };
        auto N = [] (int nums){
            return nums < 0;
        };
        int pos = count_if(nums.begin(), nums.end(), p);
        int neg = count_if(nums.begin(), nums.end(),N);

        return max(pos,neg);
    }
};