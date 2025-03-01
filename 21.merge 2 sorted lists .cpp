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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 ==NULL ) return list1;

        ListNode* result ;
        if(list1->val > list2->val) {
            result = list2;
            result->next = mergeTwoLists(list1  ,list2->next);
        }
        else {
            result = list1;
            result->next = mergeTwoLists(list1->next,  list2);
        }
        return result ;
    }
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* L, ListNode* R) {
        //edge case .. koi bhi agr end ho jata h toh next wale ko pura returnkr do
        if(L == NULL) return R;
        if(R==NULL) return L;
        ListNode* ans = new ListNode(-1); //init ans 
        ListNode* mptr = ans; // ptr on ans 
        while(L && R ){ // koi bhi null n ho jb tk
            if(L->val <= R->val){
                mptr->next = L; // ptr change 
                mptr= L;  // update mpt 
                L= L->next; //update l
            }else{
                mptr->next = R;
                mptr =R;
                R = R->next;
            }
        }
        if(L){  // ek null hua toh 2nd pe ptr laga do ab 
            mptr->next=L;
        }
        if(R){
            mptr->next=R;
        }
        return ans->next; // ans ka next dedo ans pe 
    }
};