#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        set<vector<int>>st;

        for(int i=0; i<n ; i++){
            
            for(int j=i+1 ; j<n ; j++){
                for(int k=j+1; k<n ; k++){
                    for(int l=k+1 ; l<n ; l++){
                        if((long long)nums[i] + nums[j]+ nums[k] + nums[l]== target) {
                            vector<int>temp = {nums[i] ,nums[j], nums[k] , nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>>st;

        for(int i=0; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                set<long long>hashset;
                for(int k=j+1 ; k<n ; k++){
                    long long sum = (long long)nums[i]+nums[j] +nums[k];
                    
                    long long rem = (long long)target-sum;

                    if(hashset.find(rem) != hashset.end()){
                        vector<int>temp = {nums[i],nums[j],nums[k], (int)rem};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);

                }

            }
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
        
    }
};