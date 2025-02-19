#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    bool match(string &num , string &pattern){
        int n = pattern.length();
        for(int i=0; i<n ; i++){
            if((pattern[i]=='I' && num[i]>num[i+1])||(pattern[i]=='D' && num[i]<num[i+1])){
                return false;
            }
        }
        return true;
    }
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string num = "";
        for(int  i =1 ; i<=n+1 ; i++){
            num.push_back(i+'0');
        }

        while(!match(num, pattern)){
            next_permutation(num.begin(),num.end());
        }
        return num;
        
    }
};