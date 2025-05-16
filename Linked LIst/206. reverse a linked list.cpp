#include <bits/stdc++.h>
#include <iostream>
using namespace std;

  struct ListNode {
      int val;
    ListNode *next;
ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // if single element or no element
        if(head == NULL || head->next == NULL) return head;
        
        // recc call for next but dont forget to return last 
        ListNode* last = reverseList( head->next);

        // main work
        head->next->next = head ;
        head-> next =  NULL;
       
       // return the last which is the end of the linked list
        return last;
        
        
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* prev = NULL;
       ListNode* curr = head;
       while(curr!=NULL){
        ListNode* nextNode = curr->next;
        curr->next=prev;
        prev = curr;
        curr=nextNode;
    
       }

      return prev;
    }
};


