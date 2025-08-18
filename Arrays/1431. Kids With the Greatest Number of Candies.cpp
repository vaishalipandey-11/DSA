
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxi =0;
       
        vector<bool>result ;
        for(int i=0; i<n ; i++){
             maxi = max(maxi,candies[i]);
            if(candies[i]+ extraCandies >= maxi){
                result.push_back(true);

            }else{
                result.push_back(false);
            }

        }
        return result ;
    }
};