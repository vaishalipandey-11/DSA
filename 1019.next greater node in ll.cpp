#include <bits/stdc++.h>

#include <iostream>
using namespace std;
#include<vector>
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // convert ll into a vector first 
        vector<int> ll;

        while(head ){
            ll.push_back(head->val);
            head= head->next;
        }
        // create a and and a stack 
        stack<int>st;
        vector<int>ans(ll.size()) ;
       for(int i = 0; i<ll.size() ; i++){
            while(!st.empty() && ll[i] > ll[st.top()] ){
             int kids = st.top();
             st.pop();
             ans[kids] = ll[i];
            }
           
                st.push(i);
            }


           
        return ans;     
    }
};