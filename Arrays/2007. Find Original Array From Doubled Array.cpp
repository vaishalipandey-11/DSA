
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 //tc: O(nlogn) + O(n)
 //sc: O(n)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>result;
        int n = changed.size();
        if(n%2 != 0) return {};

        sort(changed.begin(), changed.end());

        unordered_map<int,int>mp;
        for(int i =0 ; i<n ; i++){
            mp[changed[i]]++;
        }

        for(int i =0 ; i<n ; i++){
            if(mp[changed[i]]==0 ) continue;
            if(mp.find(changed[i]*2)==mp.end()|| mp[changed[i]*2]==0){
                 return {};
            }else{
                result.push_back(changed[i]);
                mp[changed[i]]--;
                mp[changed[i]*2]--;
            }
            
        }
        return result ;
    }
};