
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        

        int n = nums1.size();
        for(int i=0 ; i<n ; i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin() , v.end(), greater<>());
        
        priority_queue<int , vector<int> , greater<int>>min_heap;


        long long ans =INT_MIN;
        long long curr = 0;

        for(int i =0 ; i<k ; i++){
            curr+= v[i].second;
            min_heap.push(v[i].second);
        }

        long long curr_ans = v[k-1].first * curr;
        ans = max(ans , curr_ans);

        for(int i=k ; i<n ; i++){
            curr = curr-min_heap.top()  + v[i].second ;
            min_heap.pop();
            curr_ans = v[i].first * curr;
            min_heap.push(v[i].second);
             ans = max(ans , curr_ans);
        }

        
     return ans ;

        
    }
};