#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
//T.C : O(nlogn)
//S.C : O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int n = intervals.size();
       vector<vector<int>>ans;
       sort(intervals.begin(), intervals.end());
       ans.push_back(intervals[0]);

       for(int i =1 ; i<n ; i++){
        int s= intervals[i][0];
        int e = intervals[i][1];

            // non overlaping 
        if(s > ans.back()[1]){
            ans.push_back(intervals[i]);
        }else{// overlapping 
            ans.back()[1] = max(ans.back()[1], e);
        }
       }
       return ans;
    }
};