#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();

        int currCost =0;
        int maxLen =0;

        int i=0 ;
        int j =0;

        while(j<n){
            currCost += abs(s[j]-t[j]);
            while(currCost > maxCost){
                currCost -= abs(s[i]-t[i]);
                i++;
            }
            maxLen = max(maxLen , j-i+1);
            j++;
        }

        return maxLen;
    }
};