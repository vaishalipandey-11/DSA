#include<bits/stdc++.h>
using namespace std;
#include<iostream>
class Solution {
public:
// tc : o(n2) and sc = o(n)
    string reverseParentheses(string s) {
        stack<int>st;
        string result ;
        for(auto currentchar : s){
            if(currentchar == '('){
                st.push(result.length());
            }else if(currentchar == ')'){
                int start = st.top();
                st.pop();
                reverse(result.begin()+ start , result.end());
            }else{
                result += currentchar ;
            }
            
        }
        return result ;
    }
};