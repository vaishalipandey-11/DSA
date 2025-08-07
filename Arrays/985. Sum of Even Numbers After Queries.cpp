#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sum =0;

        for(int i =0 ; i<n ; i++){
            if(nums[i]%2==0) sum+=nums[i];
        };

        vector<int>result ;

        for(auto &it : queries){

            if(nums[it[1]]%2==0){//even number 
            sum = sum-nums[it[1]];
            nums[it[1]]=nums[it[1]]+it[0];

            if(nums[it[1]]%2==0) {
                sum =sum+nums[it[1]];
            }
            result.push_back(sum);

            }else{
                 nums[it[1]]=nums[it[1]]+it[0];
                 
                if(nums[it[1]]%2==0) {
                sum =sum+nums[it[1]];
            }
                 result.push_back(sum);

            }
        }
        return result;
    }
};