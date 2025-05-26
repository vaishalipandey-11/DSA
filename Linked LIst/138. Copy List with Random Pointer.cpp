

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head ) return 0;


        // insert a node in between the 2  nodes 
       
         Node * curr = head ;          //A
         while(curr ){
         Node* currnext = curr->next; //A->B

            curr->next= new Node( curr->val);
            curr->next->next = currnext;

            curr = currnext;

         }

         // deep copy of random pointer 
         curr = head ;
         while(curr && curr->next ){
            if(curr->random == NULL){
                curr->next ->random = NULL;
            }else{
                curr ->next->random = curr->random->next;
            }
            curr = curr->next->next;

         }

         //detach both linked lists now 
          Node * newhead = head ->next; // to return new linked list
          

          curr = head ;   // need both to iterate
          Node* newcurr = newhead;

          while(curr && newcurr){
            curr->next = curr->next ? curr->next->next : nullptr;
            newcurr ->next = newcurr->next?  newcurr->next->next : nullptr;

            curr = curr->next ;
            newcurr = newcurr->next;
          }
          return newhead;





        

        
        
    }
};
