#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string result = "";
        stack<char> st;
        for(int i =0 ; i<n ; i++){
            if(!st.empty() && s[i] == st.top()){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
       reverse(result.begin() , result.end());
       return  result;

    }
};