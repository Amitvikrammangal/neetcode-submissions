/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
         ListNode* slow=head;
          ListNode* fast=head;
          while(fast!=NULL && fast->next!=NULL)
          {
             fast=fast->next->next;
             slow=slow->next;
          }

          ListNode* next=NULL;
          ListNode* curr=slow->next;
           slow->next=NULL;
          ListNode* prev=NULL;
          
            while(curr!=NULL)
            {
                 next=curr->next;
                 curr->next=prev;
                 prev=curr;
                 curr=next;
            }
            ListNode*  second=prev;
            ListNode* first=head;
          while(second!=NULL)
            {
               ListNode* firstnext=first->next;
               ListNode* secondnext=second->next;
               first->next=second;
               second->next=firstnext;

               first=firstnext;
               second=secondnext;

            }

            
    }
    
};
