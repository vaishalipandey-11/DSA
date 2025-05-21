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
    int findLength(ListNode* head){
        int l=0;
        while(head){
            l++;
            head =  head->next;
        }
        return l;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int L = findLength(head);
        int K_1 = k;
        ListNode* Node1 = head;
       while(K_1 > 1){
        Node1 = Node1->next;
          K_1--;       
       }
        


       int K_2 = L-k+1;
        ListNode* Node2 = head;
       
       while(K_2 > 1){
         Node2 = Node2->next;
         K_2 --;
       }
       

        swap(Node1->val, Node2->val);
        

        return head;
    }
};