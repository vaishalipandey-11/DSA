#include <bits/stdc++.h>

#include <iostream>
using namespace std;
class Solution {
public:
     
    string decodeString(string s) {
        stack<string> st;
        for(auto ch :s){

            if(ch == ']'){
                  string stringrepeat = "";
               // app all chars 
                while(!st.empty() && st.top() !="["){
                   
                string top = st.top();
                stringrepeat += top;
                // pop after adding  
                st.pop();

                }
                // pop "["
                st.pop();
                // time to count digit 
                string repeatcount = "";
                while(!st.empty() && isdigit(st.top()[0]) ){
                    repeatcount += st.top();
                        st.pop();
                }
                // reverse the digits 
                reverse(repeatcount.begin(), repeatcount.end());
                // conversion
                int n = stoi(repeatcount);

                // time for string creating 
                string currstring ="";
                while(n--){

                    currstring += stringrepeat;

                }
                st.push(currstring);
                
            }
            else{
               // push all in stack

                string temp(1,ch);
                st.push(temp);
            }

        }
            // ans inti 
            string ans ;
            while(!s.empty()){
                ans +=st.top();
                st.pop();

            }

            reverse(ans.begin(), ans.end());
            return ans ;
    }
};