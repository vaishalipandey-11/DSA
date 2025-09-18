
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 
class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        priority_queue<double>pq;
        for(auto &it : nums){
            pq.push((double)it);
            sum+= it;

        }

        double half = sum/2.0;
        int count =0;
        while(sum > half){
            double x = pq.top(); pq.pop();
            pq.push((x/2.0));
            sum -= ((x/2.0));
            count++;

        }
        return count ;
        
    }
};