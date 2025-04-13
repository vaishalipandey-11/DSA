#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int>st;
        int  i=0 , j=0 ;
        while(j<n){
            // check ki st pe h y nhi 
            if(st.find(nums[j])!= st.end()){
                return true;
            }
            // nhi h toh insert kr do
            st.insert(nums[j]);
            // chechk window size , shrink and remove i from st 
            if(j-i >= k){
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};