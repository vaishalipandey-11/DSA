
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
         priority_queue<int > pq;
        for(auto &it : piles){
            sum+=it;
            pq.push(it);
        }

        while(k--){
            int top = pq.top();
            pq.pop();
            int remove = top/2;
            sum -= remove;
            pq.push(top-remove);
        }
        return sum ;

    }
};