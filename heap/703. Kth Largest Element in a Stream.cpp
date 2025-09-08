
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class KthLargest {
public:
    int K;
    priority_queue<int ,vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
         K = k;
         for(auto &it: nums){
            pq.push(it);
         }
         int s =pq.size();
         while(s>k){
            pq.pop();
            s--;      
         }
     }

    int add(int val) {
        pq.push(val);
        if(pq.size()>K) pq.pop();
        return pq.top();

    }
};

