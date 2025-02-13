#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    vector<int>P,N;
    int n = nums.size();
    for(int i =0 ; i<n ; i++){
        nums[i]>0 ? P.push_back(nums[i]): N.push_back(nums[i]);
    }

    for(int i =0 ; i<n/2 ; i++){
        nums[2*i]=P[i];
        nums[2*i+1]=N[i];
    }
    return nums;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int Pos = 0 ; int Neg = 1;
        for(int i =0 ; i<n ; i++){
            if(nums[i]<0 ){
                     ans[Neg]=nums[i] ;
                     Neg+=2;
            }else{
                ans[Pos]=nums[i];
                Pos+=2;
            }
        }
        return ans;

    }
};