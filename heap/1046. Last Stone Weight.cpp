
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() >=2) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (x != y)
                pq.push(y - x);
        }
        if (pq.empty())
            return 0;
        return pq.top();
    }
};