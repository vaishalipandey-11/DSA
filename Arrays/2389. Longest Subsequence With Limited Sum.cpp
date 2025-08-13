
#include<iostream>
#include<bits/stdc++.h>
using namespace std;    
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    vector<int>ans;

    for(int i=0; i<queries.size() ; i++){
        int currsum =0;
        int count =0;
        for(int j=0; j<nums.size() ; j++){
            currsum += nums[j];
            if(currsum >queries[i]){
                break; 
            }
            count++;
            
        }
        ans.push_back(count);
    }
    return ans;
        
    }
};


//using cumm and binary search 
class Solution {
public:
    int binarysearch(vector<int>& nums, int target){
        int l=0; int e=nums.size()-1;
        while(l<=e){
            int mid= l +(e-l)/2;
            if(nums[mid]>target){
                e=mid-1;

            }else{
                l=mid+1;

            }
        }
        return l;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>ans;

        for(int i=1 ; i<n ; i++){ //cumm sum 
            nums[i] +=nums[i-1];
        }

        for(int i=0 ; i<queries.size(); i++){
            int idx = binarysearch(nums, queries[i]);
            ans.push_back(idx);

        }
        return ans;
        
    }
};