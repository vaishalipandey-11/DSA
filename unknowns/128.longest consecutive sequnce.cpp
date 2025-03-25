#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    // helper linear search function 
    bool linearsearch(vector<int>&nums, int x){
        int n = nums.size();
        if(n==0 ) return 0;
        for(int i =0 ; i<n ; i++){
            if(nums[i]==x) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
         int largest =0;
        // here we will take 2 var lag and count too track
        for(int i =0 ; i<n ; i++){
            //we need to while cons so
            int x = nums[i];
            int count =1;
           
            while(linearsearch(nums,x+1)==true){
                 x++;
                 count++;
               }
            largest = max(largest,count);
        }
        return largest;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        //edge case of empty array
        if(n==0) return 0;
        // var needed
        int end = INT_MIN;
        int count =0;
        int longestcoseq = 1;
        //sort array 
        sort(nums.begin(), nums.end());
        //iterate 
        for(int i=0 ; i<n ;i++){
            //check last elem is the end or not
            if(nums[i]-1 == end){
                count++;
                end=nums[i];
            }else if(nums[i] != end){
                count=1;
                end = nums[i];
            }
             longestcoseq = max(count , longestcoseq);
        }
        return longestcoseq;
        
    }
};
  int longestConsecutive(vector<int>& nums) {
            int n = nums.size();
            if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //iterate and insert
    for (int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
        
    }