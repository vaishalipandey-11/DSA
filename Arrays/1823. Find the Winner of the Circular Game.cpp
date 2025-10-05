#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>vec;
        for(int i=1 ; i<=n ; i++){
            vec.push_back(i);
        }

        int i=0;
        while(vec.size() >1){
            int idx = (i+k-1)%vec.size();
            vec.erase(vec.begin() + idx);
            i=idx;
        }
        return vec[0];
        
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1 ; i<=n ; i++) q.push(i);

        while(q.size() > 1){
            for(int i =0; i<k-1 ; i++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
        
    }
};