// we are following opposite approach for that where we eliminate substr 
// we find left and right 
// we use recc for that .. the tc is very bad
 #include <iostream>
using namespace std;
#include<stack>
class Solution {
public:
    bool isValid(string s) {
      
      if(s.size() == 0) return true ;

      int fnd = s.find("abc");

      if( fnd != string::npos){
        // found 
        string left = s.substr(0, fnd);
        string right = s.substr(fnd+3 , s.size());

        return isValid(left+right);
      }
      return false;

        
    }
};

// better solution as compared to that and beats 100%
class Solution {
public:
    bool isValid(string s) {
        if(s[0] !='a') return false;
        stack<char>st;

        for(auto ch : s){
            if(ch == 'c'){
                if(st.size()<2) return false;
                if(st.top()=='b'){
                    st.pop();
                    if(st.top()=='a'){
                        st.pop();
                    }else{
                        return false;
                    }
                }   
               
            }else{
                st.push(ch);
              
            }
        }
        return st.empty();
    }
};