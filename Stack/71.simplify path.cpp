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



// better approach here 
class Solution {
public:
    string simplifyPath(string path) {
     stack<string > st;
     string token ="";
     // tokenise the stream path 
     stringstream ss(path);
     while(getline(ss, token , '/')){
        if(token == "." || token == "") continue ;
        if(token != "..") {
        st.push(token);
        }else if(!st.empty()){
            st.pop();
        }
     } 
     // if stack is empty then /
     if(st.empty()) return "/";

     string result = "";
     while(!st.empty()){
       result = "/" + st.top() + result ; // dont forget the order please 
       st.pop();
     } 

     return result ; 
    }
};

// we can use vector in place of stack here 
class Solution {
public:
// here we are using vector in place of stack okay
    string simplifyPath(string path) {
    vector<string > st;
     string token ="";
     // tokenise the stream path 
     stringstream ss(path);
     while(getline(ss, token , '/')){
        if(token == "." || token == "") continue ;
        if(token != "..") {
        st.push_back(token);
        }else if(!st.empty()){
            st.pop_back();
        }
     } 
     // if vector  is empty then /
     if(st.empty()) return "/";

     string result = "";
     for(auto &token : st){
        result = result + "/" + token ; // dont look for order here its vector  
     }

     return result ; 
    }
};