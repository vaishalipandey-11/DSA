#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        //for storing sol
        vector<int>sol(n);
        //count the freq 
        int less=0, equal =0;
        for(int i=0 ; i<n ;i++){
           if(nums[i]<pivot){
            less++;
           }
            else if(nums[i]== pivot){
             equal++;
           }
        }
         
         // now add elements acc to freqency
         int i =0 ;
         int j = less;
         int k = less + equal;
         for(int it=0 ; it<n ;it++){
               if(nums[it]<pivot){
                sol[i++]=nums[it];
                
           }
            else if(nums[it]== pivot){
               sol[j++]=nums[it];
           }
           if(nums[it]>pivot){
              sol[k++]=nums[it];
           }
         }
         return sol;
        
    }
};

// a kind of brute force approach...
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       int n = nums.size();
       vector<int >ans;
       for(int i=0 ; i<n ; i++){
        if(nums[i]<pivot) ans.push_back(nums[i]);
       }
       for(int i=0 ; i<n ; i++){
        if(nums[i]==pivot) ans.push_back(nums[i]);
       }
       for(int i=0 ; i<n ; i++){
        if(nums[i]>pivot) ans.push_back(nums[i]);
       }
       return ans;
       
    }
};
//using 2 pointer approach
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       int n = nums.size();

       vector<int>sol(n);

       int i=0 , j =n-1;

       int k =0 , l = n-1;

       while(i< n && j>=0){
        if(nums[i]<pivot){
            sol[k]=nums[i];
            k++;
      
         }
         if(nums[j]>pivot){
           sol[l] = nums[j];
             l--;
         }
         i++;
         j--;
       } 
       while(k <= l){
        sol[k]=pivot;
        k++;
       }
       return sol;
    }
};