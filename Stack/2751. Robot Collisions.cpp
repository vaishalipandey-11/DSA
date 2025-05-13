#include<bits/stdc++.h>
using namespace std;
#include<iostream>
class Solution {// similar to astroid one 
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
         int n = positions.size();
         vector<int>actual_index(n); 
         iota(actual_index.begin(), actual_index.end(), 0);// 0 , 1, 2,3 .. n-1
          
         auto lambda = [&] (int i , int j){
            return positions[i]<positions[j];
         };

         sort(actual_index.begin() , actual_index.end(), lambda);// sorting by using lambda function nlogn

         stack<int>st;
         vector<int>result ;

         for(int curr_index : actual_index){ // o(n)
            if(directions[curr_index] == 'R'){
                st.push(curr_index);
            }else{
                while(!st.empty() && healths[curr_index] >0){
                   int top_index = st.top();
                    st.pop();

                    if(healths[curr_index]>healths[top_index]){
                        healths[top_index] =0;
                        healths[curr_index] -= 1;

                    }else if(healths[curr_index] <healths[top_index]){
                        healths[top_index] -=1;
                        healths[curr_index] =0;
                         st.push(top_index);
                       
                    }else{
                        healths[top_index] =0;
                        healths[curr_index] =0;
                        
                    }
                }
            }
         }
         for(int i=0 ; i<n ; i++){ // o(n)
            if(healths[i]>0){
                result.push_back(healths[i]);
            }
         }
         return result ;
         
    }
};