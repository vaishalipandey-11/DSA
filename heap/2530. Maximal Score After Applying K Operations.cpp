
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int> max_heap(nums.begin(), nums.end());
        
        long long  sum =0;
        while(k--){
            long long curr = max_heap.top();
             max_heap.pop();
            sum+=curr;
           
            max_heap.push(ceil(curr/3.0));
            
        }

        return sum ;
    }
};