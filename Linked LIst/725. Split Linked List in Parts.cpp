#include<bits/stdc++.h>
using namespace std;
#include<iostream>
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // find the length of the ll
        ListNode* curr = head;
        int L =0;
        while(curr){
            curr= curr->next ;
            L++;
        }

        vector<ListNode* > result(k, NULL);

        int each = L/k;
        int extra = L%k;

            curr = head ;
        ListNode* prev = NULL;
        for(int i =0 ; curr && i<k ; i++){ // loop over the k parts of result 
            result[i] = curr ;
            
            for(int count =1 ; count <= each +(extra>0 ?1:0); count++){ // 1 part pe kitne elements by this loop
                         
                         prev = curr ; // move pointers 
                         curr= curr->next ;

            }
            prev ->next  = NULL; // detach the ll 
            extra --;              // update the remaining 

        }
        return result ;
        
    }
};