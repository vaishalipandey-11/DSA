
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    bool allzero(vector<int>&counter){
    for(auto i : counter){
        if(i !=0  )return false;
    }
    return true;
}
    vector<int> findAnagrams(string s, string p) {
        int k = p.length();
        int n = s.length();
       vector<int>counter(26,0);
        vector<int>result ;

        for(int i =0 ; i<k ; i++){
            char ch = p[i];
            counter[ch-'a']++;
        }

        int  i=0 , j =0;
        while(j<n){
            counter[s[j]-'a']--;
            if(j-i+1 == k){
                if(allzero(counter)){
                    result.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;

            }
            j++;
        }
        return result ;
        
    }
};