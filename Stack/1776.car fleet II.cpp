#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<stack>
#include<vector>
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
       // we need a vector and a stack 
       vector<double>answer(cars.size() , -1);
       stack<int>st; // for indexing only 
       // reversed loop over the cars 
       for(int i = cars.size()-1 ; i>=0 ; i--){
        //check speed and pop if the speed of top ele is more because it cant form a fleet and store -1 
        while(!st.empty() &&  cars[st.top()][1] >= cars[i][1]){
            st.pop();
        }
        // if the speed of top element of the car is less then fleet can we formed 
        // so lets find the time in sec 
        while(!st.empty()){
            double collidetime =(double) (cars[st.top()][0]-cars[i][0])/(cars[i][1] - cars[st.top()][1]);

            // we need to push the collidetime to the answer 
            if(answer[st.top()]== -1 || collidetime <=answer[st.top()]){
                answer[i]= collidetime ;
                break;
            }
            st.pop();
        }
         st.push(i);
       }
       return answer;
       
    }
};