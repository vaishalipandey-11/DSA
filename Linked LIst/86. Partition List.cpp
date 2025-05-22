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
    ListNode* partition(ListNode* head, int x) {
      ListNode* small = new ListNode (0); // creating 2 nodes for small list and large list
      ListNode* large = new ListNode (0);  

      ListNode* smallp = small ;
      ListNode* largep = large ;

      while(head){
        if(head->val < x){ // adding nodes  to lists
            smallp->next = head ;
            smallp = smallp->next ;
        }else{
            largep->next = head ;
            largep= largep->next;
        }
        head = head ->next;
      }

       
      smallp->next = large->next ; // joining the nodes to the list now 
       largep->next = NULL;
    

        return small->next;
    }
};