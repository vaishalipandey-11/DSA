
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int, vector<int> , greater<int>> min_heap;
         int n = nums.size();
         for(auto it : nums){
            min_heap.push(it);
         }

         for(int i=1 ; i<=n-k ; i++){
            min_heap.pop();
         }
         return min_heap.top();
    }
};