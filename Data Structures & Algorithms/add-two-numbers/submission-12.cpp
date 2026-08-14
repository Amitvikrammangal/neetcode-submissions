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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* head1=l1;
          ListNode* head2=l2;
         ListNode* head3=NULL;
          ListNode* temp=NULL;
          int carry=0;
     while(head1 != NULL || head2 != NULL)
        {
            int sum=carry;
            if(head1!=NULL)
            {
                 sum=sum+head1->val;
                 head1=head1->next;
            }
            if(head2!=NULL)
            {
                 sum=sum+head2->val;
                 head2=head2->next;

            }
            int digit=sum%10;
            carry=sum/10;
             ListNode* newnode= new ListNode(digit);
             if(head3==NULL)
             {
                head3=newnode;
                temp=newnode;
             }
             else
             {
                temp->next=newnode;
                temp=newnode;
             }
             
        }
        if(carry!=0)
        {
             ListNode* newnode= new ListNode(carry);
             temp->next=newnode;
        }
        return head3;
    }
};
