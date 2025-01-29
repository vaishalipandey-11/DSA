#include <iostream>
using namespace std;
#include<vector>
 
  struct ListNode {
     int val;
       ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // init ans 
        vector<int>ans ={-1, -1};
        // pointer creation
        // ListNode* prev = head;
        // if(!prev) return ans;
        // ListNode* curr = prev->next;
        // if(!curr) return ans;
        // ListNode* nxt = prev->next->next;
        // if(!nxt) return ans;
        
         ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* nxt = prev->next->next;
        if(!prev || !curr || ! nxt){ return ans;}
       
    

        int firstcp = -1;
        int lastcp = -1;
        int minDist = INT_MAX;

        // indexing 
        int i =1;

        while(nxt){
            // check for the condition 
        bool iscp = ((curr->val > prev->val && nxt->val < curr->val ) ||
                        (curr->val <prev->val && curr->val < nxt->val))
                        ? true : false;
       

 
  // exists but it 1st occ 
               if(iscp && lastcp == -1){
                firstcp =i ;
                lastcp =i;
               }

               // case2 more than 1 occ
              else if(iscp){
               
                minDist = min(minDist , i-lastcp);
                 lastcp =i;
              }
                 i++;

                 // pointer 
                 prev = prev->next;
                 curr =curr->next;
                 nxt = nxt->next;
        }
        
        if(lastcp == firstcp){
            return ans;
        }else{
            ans[0] = minDist;
            ans[1] = lastcp - firstcp ;
        }

            return ans ;
    }
};