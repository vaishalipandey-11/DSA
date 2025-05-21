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
// here we are trying recc to solve such minor detailed problems 
    ListNode* swapPairs(ListNode* head) {
        
        if(head ==NULL || head ->next == NULL) return head; // base case 

        ListNode* temp = head->next;     // need to store B .. A->B->C->D->..
          head->next = swapPairs(head->next->next); // use recc and get the swapped list after 2 nodes
        temp->next = head;
      
        return temp; // after swap(temp =b ) is the head each time 
    }
};