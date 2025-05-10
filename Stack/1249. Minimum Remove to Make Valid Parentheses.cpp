
#include<bits/stdc++.h>
#include<istream>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        unordered_set<int> toremoveindex;
        stack<int>st;

        for(int i =0 ; i< n ; i++){
            if(s[i]=='('){          // open ko push kiya
                st.push(i);
            }else if(s[i]==')'){   // close ko dekha 
                if(!st.empty()){    // check kro stack empty nhi h toh pop kr do 
                    st.pop();       // balancing with open '('
                }else{              // vrna empty h toh vo extra or invalide h toh usko remove krne 
                                     //k liye     set    pe daal do 
                    toremoveindex.insert(i);
                }
            }
        }
            // what is input pe '((' aisa kuch hoga toh toh remove pe jayenge n sb 
            // toh eisliye hm remove pe add nhi karenge unko 
            // so adding here 
            while(!st.empty()){
                toremoveindex.insert(st.top());
                st.pop();
            }

            string result = "";
            for(int i=0 ; i<n ; i++){
                if(toremoveindex.find(i) == toremoveindex.end()){
                    result.push_back(s[i]);
                }
                
            }
        return result ;
    }
};