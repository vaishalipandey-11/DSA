#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int>arr;
        arr.push_back(pref[0]);
        for(int i =1 ; i<n ; i++){
            arr.push_back(pref[i]^pref[i-1]);
        }
        return arr;

    }
};

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
       
        for(int i =n-1 ; i>0 ; i--){
            pref[i]= (pref[i]^pref[i-1]);
        }
      return pref;
    }
};