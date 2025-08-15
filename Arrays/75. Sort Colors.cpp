#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l =0; int m =0 ;int h =nums.size()-1;
        while(m<=h){
            if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }else if(nums[m]==1){
                m++;
            }else{
                swap(nums[m],nums[h]);
                m++;
                h--;
            }
        }
        
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int idx =0;
        for(int i=0; i<mp[0]; i++){
            nums[idx++]=0;
        }
         for(int i=0; i<mp[1]; i++){
            nums[idx++]=1;
        }
         for(int i=0; i<mp[2]; i++){
            nums[idx++]=2;
        }
    }
};