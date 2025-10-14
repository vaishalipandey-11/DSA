#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        int pre =1 ; int suff =1;
        int ans = INT_MIN;
        for(int i=0; i<n ; i++){
            if(pre == 0) pre =1;
            if(suff ==0) suff =1;
            pre *= nums[i];
            suff*=nums[n-i-1];
            ans = max(ans, max(pre,suff));

        }
        return ans;
        
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int p = INT_MIN;
        for (int i = 0; i < n; i++) {
            int s = 1;
            for (int j = i ; j < n; j++) {

                s *= nums[j];
                p = max(p, s);
            }
        }
        return p;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size();
       int p = INT_MIN;
       for(int i=0; i<n ; i++){
        for(int j=i ; j<n ; j++){
            int cp =1;
            for(int k=i ; k<=j ; k++){
                cp *= nums[k];
                p = max(p,cp);
            }

        }
       } 
       return p;
    }
};