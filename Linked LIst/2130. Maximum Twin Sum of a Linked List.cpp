#include<bits/stdc++.h>
using namespace std;
 #include<iostream>
struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
// this is our first approach using vector 
    int pairSum(ListNode* head) {
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head= head->next;
        }

        int i=0;
        int j =v.size()-1;
        int maximum = INT_MIN;
        while(i<j){
             maximum = max(maximum , v[i]+v[j]); 
          i++;
          j--;
        }
        return maximum;

        
    }
};