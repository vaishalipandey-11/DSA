#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string &s) {
        int n = s.length();
        vector<int>mp(3,0);
        int i=0, j=0;
        int result =0;
        // khandani tamplet
        
        while(j<n){
           
            mp[s[j]-'a']++; // to get o based indexing...................

            while(mp[0] > 0 && mp[1]> 0 && mp[2] > 0){
                result += (n-j);
                mp[s[i]-'a']--;
                i++;

            }

             j++;
        }
        return result;
    }
};