///Approach-1 (Using unordered_map + sorting)
//T.C : O(m+n + NlogN), N = m+n, m = nums1.size(), n = nums2.size()
//S.C : O(m+n)
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>sol ;
        int n = nums1.size();
        int m = nums2.size();

        // using unordered_map() here 
        unordered_map<int, int> mp;

        // creating a map for the values and adding values acc to id 
        for(int i =0 ; i<n ;i++){
            int id = nums1[i][0];
            int val = nums1[i][1];
              mp[id] += val;
        }
        for(int i =0 ; i<m ;i++){
            int id = nums2[i][0];
            int val = nums2[i][1];
              mp[id] += val;
        }
        //lets traverse on map and create our sol 
        for(auto &it : mp){
            int key = it.first;
            int value = it.second;
            // add key value pairs in  solution 
            sol.push_back({key,value});
        }
        // unordered map is not sorted we need to sort it 
        sort(sol.begin(), sol.end()); // by default acc to key
        return sol;

    }
};

//Approach-2 (Using ordered+map)
//T.C : O(m+n + NlogN), insertion in ordered_map is logarithmic time complexity
//S.C : O(m+n)

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>sol ;
        int n = nums1.size();
        int m = nums2.size();

        // using ordered_map() here 
      map<int, int> mp;

        // creating a map for the values and adding values acc to id 
        for(int i =0 ; i<n ;i++){
            int id = nums1[i][0];
            int val = nums1[i][1];
              mp[id] += val;
        }
        for(int i =0 ; i<m ;i++){
            int id = nums2[i][0];
            int val = nums2[i][1];
              mp[id] += val;
        }
        //lets traverse on map and create our sol 
        for(auto &it : mp){
            int key = it.first;
            int value = it.second;
            // add key value pairs in  solution 
            sol.push_back({key,value});
        }
        // unordered map is not sorted we need to sort it 
      
        return sol;

    }
};

//Approach-3 (Using 2 Pointers)
//T.C : O(m+n)
//S.C : O(1)

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
      int n = nums1.size(); int m = nums2.size();
      int i =0 ; int j =0 ;
      vector<vector<int>>sol;
      while(i<n && j<m){
          if(nums1[i][0]<nums2[j][0]){
                sol.push_back(nums1[i]);
                i++;
          }
           else if(nums1[i][0]>nums2[j][0]){
                sol.push_back(nums2[j]);
                j++;
          }
         else{
                sol.push_back({nums1[i][0], nums1[i][1] +nums2[j][1]});
                i++;
               j++;
                    } 
                    
             }  

             // extra elements 
             while(i<n){
                sol.push_back(nums1[i]);
                i++;
             }
              while(j<m){
                sol.push_back(nums2[j]);
                j++;
             }
             return sol;
    }
};