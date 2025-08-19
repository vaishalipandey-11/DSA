
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class SummaryRanges {
public:
     set<int>st; 
    SummaryRanges() {
      st.clear();
    }
    
    void addNum(int value) {
        st.insert(value)  ;
    }
    
    vector<vector<int>> getIntervals() {
       vector<int>arr(st.begin(), st.end());
       int n = arr.size();
       vector<vector<int>>ans;

       for(int i=0 ; i<n ; i++){
        int start = arr[i];
        while(i<n-1 && arr[i]+1 == arr[i+1]){
            i++;
        }
        ans.push_back({start , arr[i]});

       }
       return ans;
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */