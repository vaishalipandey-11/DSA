
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> v;
        for(int i=0 ; i<n ; i++){
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());

        priority_queue<int> max_heap ;
        int idx =0;
        while(k-- >0){
            while(idx<n && w >= v[idx].first){
                max_heap.push(v[idx].second);
                idx++;
            }

            if(max_heap.empty()) break;

            w += max_heap.top();
            max_heap.pop();
        }
        return w;
    }
};