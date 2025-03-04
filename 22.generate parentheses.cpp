#include <bits/stdc++.h>
#include <iostream>
using namespace std;


//Approach-1 (Simple Recursion)
//T.C : O(2n* (2^(2n)) -> Removing constant -> O(n * (2^n))
//S.C : O(2*n) -> Removing constant -> O(n) -> recursion stack space - Max depth of recusion tree
class Solution {
public:
  vector<string>result;
   bool isvalid(string str){
    int count =0 ;
    for(char ch : str){
        if(ch =='('){
            count ++;
        }else{
            count--;
        }
        if(count <0) return false;
        }
        return count ==0 ; //if count =0 true else false 
      
   }
    void solve(string &curr , int n ){
         if(curr.length()==2*n){
            if(isvalid(curr)){
                    result.push_back(curr);
                  
            }
              return ;
        
      }
      
        curr.push_back('(');
        solve(curr , n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr , n);
        curr.pop_back();

    }

    vector<string> generateParenthesis(int n) {
      
      string curr = "";
     
      solve(curr , n);
      return result;

    }
};
//Approach-2 (Smart Recursion)
//T.C : O(2^n)
//S.C : O(2*n) -> Removing constant -> O(n) -> recursion stack space - Max depth of recusion tree
// using the concept of open and close open <n  and close< open .. push.....result 
class Solution {
public:
  vector<string>result;
    void solve(string &curr , int n , int open , int close ,vector<string>&result){
         if(curr.length()==2*n){
              result.push_back(curr);
              return ;        
      }
        if(open <n){
           curr.push_back('(');
           solve(curr , n ,open+1 , close, result);
          curr.pop_back();
        }
        
        if(close<open){
            curr.push_back(')');
           solve(curr , n ,open , close+1,result);
           curr.pop_back();
        }
        
    }

    vector<string> generateParenthesis(int n) {
      
      string curr = "";
      int open =0 , close =0;
      solve(curr , n ,open , close, result);
      return result;

    }
};