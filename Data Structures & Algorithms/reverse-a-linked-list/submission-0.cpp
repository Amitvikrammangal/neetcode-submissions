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
    ListNode* reverseList(ListNode* head) {
        vector<int> values;
        ListNode* temp;
        temp=head;
        while(temp!=NULL)
        {
            values.push_back(temp->val);
            temp=temp->next;
        }
         temp=head;
         int i=values.size()-1;
         while(i>=0)
         {
             temp->val=values[i];
             i--;
             temp=temp->next;
         }
         return head;
    }
};
