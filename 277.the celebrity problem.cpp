#include <bits/stdc++.h>

#include <iostream>
using namespace std;
#include<vector>
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        
        //  push every elem into the stack first
        
     stack<int>st;
     for(int i =0 ; i<mat.size() ;i++){
         st.push(i);
     }
        // take a b from the stack 
       
       while(st.size()!=1){
           int a = st.top() ; st.pop();
           int b = st.top() ; st.pop();
           
           if(mat[a][b] ){
               // a is not celeb 
               st.push(b);
           }else{
               st.push(a);
           }
            } 
       
       // single elem may be celeb
       // empty stack 
       int celeb = st.top();
       st.pop();
       
       // it should not know  anyone 
       for(int i =0 ; i<mat.size() ;i++){
           if(mat[celeb][i]!=0){
               return -1;
               
           }
       }
       /// everyone should know him
       for(int i =0 ; i<mat.size() ; i++){
           if(mat[i][celeb]==0 && i!=celeb){
               return -1;
           }
       }
    
        
        return celeb;
        
        
    }
};