//using 2 pass method 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // changes on the array acc to need 
        for(int i =0 ; i<n-1 ; i++){
            if(nums[i] == nums[i+1] && nums[i] !=0 ){ // extra condition to not do anything for 0
                nums[i] = nums[i]*2;
                nums[i+1]=0;
            }
        }
        // here we have 2 pointer i , j where i search for non neg add alot it to j 
         int j=0 ;
        for(int i =0 ; i< n ; i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }
        // change the rest as 0 
        while(j< n ){
            nums[j]=0;
            j++;
        }
        return nums;
    }
};
// now by using extra space ..
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;

        // changes on the array acc to need 
        for(int i =0 ; i<n-1 ; i++){
            if(nums[i] == nums[i+1] && nums[i] !=0 ){ // extra condition to not do anything for 0
                nums[i] = nums[i]*2;
                nums[i+1]=0;
            }
        }
        
        for(int i =0 ;i<n ; i++){
            if(nums[i]!=0){
               result.push_back(nums[i]);
            }
        };
        while(result.size()<n){
            result.push_back(0);
        }
        
        
        return result;
    }
};

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // changes on the array acc to need 
        int j =0;
        for(int i =0 ; i<n ; i++){
            if(i+1 < n && nums[i] == nums[i+1] && nums[i] !=0 ){ // extra condition to not do anything for 0
                nums[i] = nums[i]*2;
                nums[i+1]=0;
            }
            if(nums[i] != 0){
                if(i!=j){
                    swap(nums[i],nums[j]);
                    
                }
                j++;
            }
        }
        return nums;
        
        
    }
};