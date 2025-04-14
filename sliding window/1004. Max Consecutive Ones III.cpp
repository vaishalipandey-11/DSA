#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int flip =0;
        int res =0;
        
        int i =0 ;
        int j =0;
        while(j < n ){
            flip +=(nums[j]==0);
            while(flip >k){
                flip-=(nums[i]==0);
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
        
    }
};