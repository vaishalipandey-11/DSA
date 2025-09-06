
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 
class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int>mp;
        for(auto &ch : s){
            mp[ch]++;
        }

        vector<pair<char , int>>v(mp.begin(), mp.end());

        sort(v.begin() , v.end() , [] (auto &a , auto &b){
            return a.second > b.second;
        });

        string result ="";
        
        for(auto &it : v){
            while(it.second--){
                result+=it.first;
                
            }
        }
        return result ;
        
    }
};