#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<stack>
#include<vector>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       next_permutation(nums.begin(), nums.end());
     
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        // find the pivot element 
        for(int i =n-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
               pivot = i;
                break;
            }  
        }

        // what if pivot element do not exists
          if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
         }

        //find the next larger at the right(check from right )
        for(int i =n-1; i>pivot ; i--){
            if(nums[i]>nums[pivot]){
                swap(nums[pivot], nums[i]);
                break;
            }
        }

        // reverse the right part 
        reverse(nums.begin()+pivot+1, nums.end());
        
        }
    
};

   