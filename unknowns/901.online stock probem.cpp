#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>
class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int , int>> st;
   
    int next(int price) {
         int span =1;
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();

        }
        // top is larger
        // for empty
        st.push({price , span});
        return span;

        
    }
};