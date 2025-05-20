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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next ) return NULL; // this is our base case 

        ListNode* slow = head ;
        ListNode* fast = head ;

        while(fast && fast->next){ // basecase
            slow = slow ->next;
            fast = fast ->next->next;

            if(slow == fast ) break; // check if they meet 
        }
        if(slow != fast ) return NULL; // check if the loop terminated or they dont meet so no loop 

        ListNode* p = head ; // if yes then init p and move 
        while(p!=slow){ // where they meet is the point of cycle 
            p= p->next;
            slow = slow ->next;
        }
        return p;
    }
}; 