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
    bool hasCycle(ListNode* head) {
        ListNode* temp= head;
        unordered_set< ListNode*> s;
        while(temp!=NULL)
        {
            if(s.find(temp)!=s.end()) //found element
              return true;


            s.insert(temp);
            temp=temp->next;
        }
        return false;
    }
};
