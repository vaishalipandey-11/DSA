#include<bits/stdc++.h>
using namespace std;
#include<iostream>
class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(auto &ch : s){
            if(ch == '['){ // push opening bracket 
                st.push(ch);
            }else if(!st.empty()){
                st.pop(); // balance opening bracket 
            }
        }
        return ((st.size()+1)/2); // size of closing brackets 
    }
};




// by using vector instead of stack 
class Solution {
public:
    int minSwaps(string s) {
        vector<char> v;
        for(auto &ch : s){
            if(ch == '['){ // push opening bracket 
                v.push_back(ch);
            }else if(!v.empty()){
                v.pop_back(); // balance opening bracket 
            }
        }
        return ((v.size()+1)/2); // size of closing brackets 
    }
};