
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        
        unordered_map<char,int>mp;
        for(auto &ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>>mh;

        for(auto it : mp){
            mh.push({it.second , it.first});
        }

         if(( (n+1)/2) < mh.top().first) return "";
       
        string result = "";
        while(mh.size()>1){
            auto [cnt1 , ch1]= mh.top(); mh.pop();
            auto [cnt2 , ch2]= mh.top() ; mh.pop();

            result+=ch1;
            result+=ch2;

            if(--cnt1>0) mh.push({cnt1 , ch1});
            if(--cnt2>0) mh.push({cnt2 , ch2});

        }

         if(!mh.empty()){
            result += mh.top().second;
         }
        return result;
    }
};