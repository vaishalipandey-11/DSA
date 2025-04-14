#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0;
        int cmax =0;
        // iterate over the nums .. count the cons ones if 0 break the count start again and return the max of it !
        for(auto &i : nums){
            if(i==1){
                count++;
                cmax=max(cmax ,  count );
            }else{
                count =0;
            }
        }
        return cmax;
    }
};
