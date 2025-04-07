#include <bits/stdc++.h>

#include <iostream>
using namespace std;
class Solution {

void ansbuilder(stack<string>&s, string &ans){
        if(s.empty()) return ;

        string minpath = s.top() ; s.pop();
        ansbuilder(s,ans);
        ans+=minpath;
    }
    

public:
    string simplifyPath(string path) {
        // stack is req
        stack<string>s;

        int i=0;
        while(i<path.size()){
            int start = i; 
            int end  = i+1;
            while(end < path.size() && path[end]!='/'){
                end++;
                 
            }
            string minstr = path.substr(start,end-start);
            i = end;

            if(minstr == "/" || minstr=="/."){
                continue;
            }
            if(minstr != "/.."){
                s.push(minstr);
            }
            else if(!s.empty()){
                s.pop();
            }


        }

        string ans = s.empty()?"/":"";
    
       ansbuilder(s,ans);
       return ans ;
    }
};