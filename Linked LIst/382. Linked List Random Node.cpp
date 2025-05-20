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
vector<int>v;
    Solution(ListNode* head) {
        
        ListNode * temp = head ;
        while(temp){
            v.push_back(temp->val);
            temp = temp ->next;
        }
    }
    
    int getRandom() {
        int n = v.size();

        int Random_idx = rand()%n;
         return v[Random_idx];
    }

};
