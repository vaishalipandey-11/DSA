#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       int n = nums.size();
     long long  result =0;
       for(int i =0 ; i<n ; i++){
        for(int j = i+1 ; j<n ; j++){
            for(int k =j+1 ; k<n ; k++){
                    result = max(result, (long long)((nums[i] - nums[j]) *(long long) nums[k]));
            }
        }
       } 
       return result;
    }
};


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>lm(n);
        vector<int>rm(n);
        long long result =0;
   
   // just store the left max by traversing fromleft to right
        for(int  i=1 ; i<n ; i++){
            lm[i] = max(lm[i-1], nums[i-1]);
        }
        //store right max by traversing from right to left 
        for(int i=n-2 ; i>0 ; i--){
            rm[i] = max(rm[i+1] , nums[i+1]);
        } 

        //now more j and calculate max ..
        for(int j =1 ; j<n ; j++){
            result = max(result , (long long)(lm[j] - nums[j]) *rm[j]);
    }
    return result ;
    }
};

