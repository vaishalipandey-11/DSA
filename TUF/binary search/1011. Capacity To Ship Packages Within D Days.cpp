#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
     bool ispossible(vector<int>& weights,int days, int mid){
        int countday =1;
        int countweight =0;
        for(auto &it : weights){
            countweight+= it;

            if(countweight> mid){
                countday++;
                countweight = it;
            }
        }
        return countday <= days;
     }
    int shipWithinDays(vector<int>& weights, int days) {

       int r = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());
         
         int n = weights.size();
         if(days==1) return r;
         if(n<days) return -1;

        while(l<r){
            int mid = l+(r-l)/2;
            if(ispossible(weights,days, mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return r;
        
    }
};