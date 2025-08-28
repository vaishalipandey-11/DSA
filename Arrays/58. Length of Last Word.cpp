#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i=n-1;
        while(i>=0 && s[i] == ' '){
            i--;
        }
        int len =0;
        while(i>=0 && s[i] != ' '){
            i--;
            len++;

        }
        return len;
        
    }
};