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
    ListNode* oddEvenList(ListNode* head) {
   if(!head || !head->next){ // edge or base case
        return NULL;
   }

        ListNode * ODD = head ;
        ListNode * Even = head-> next ;
        ListNode *Evenstart = head->next;// for pointing odd to even's starting 

        while(Even && Even->next ){
          ODD->next = Even->next;
          Even->next =Even->next->next;
          ODD = ODD->next ;   // update ODD and EVEN
          Even = Even->next ;
        }
        ODD->next = Evenstart ; // point odd end to even starting 
        return head;    // return ll 

    }
};