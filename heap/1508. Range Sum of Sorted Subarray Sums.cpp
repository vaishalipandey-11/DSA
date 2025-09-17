
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 
class Solution {

public:
    const int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<int, vector<int> , greater<int> > min_heap;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                min_heap.push(sum);
            }
        }
        
        int i=0;
        int result =0;
        while (!min_heap.empty() && i < right  ) {
            i++;
            int val = min_heap.top();
            min_heap.pop();
            if( i>= left && i<= right){
                result = (result+val )%MOD;
            }
        }
        return result ;
    }
};