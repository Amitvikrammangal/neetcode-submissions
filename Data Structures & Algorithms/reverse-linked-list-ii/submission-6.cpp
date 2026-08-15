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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* agla=NULL;
         ListNode* tcurr=head;
          ListNode* tprev=NULL;
        for(int i=1;i<left;i++)
        {
             tprev=curr;
             tcurr=tcurr->next;
             curr=curr->next;
        }
        while(left<=right)
        {
                agla = curr->next;
                curr->next = prev;
                prev = curr;
                curr = agla;
                left++;
        }
        tcurr->next=curr;

        if(tprev != NULL)
            tprev->next = prev;
        else
            head = prev;
       
        return head;
    }
};