/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        if (head == NULL)
    return NULL;
        Node* newhead= new Node(head->val);
        Node* newt=newhead;
        mp[head]=newhead;
        Node* oldt=head->next;

        while(oldt!=NULL)
        {
             Node* copyt = new Node(oldt->val);
             mp[oldt]=copyt;
             newt->next=copyt;
             newt=newt->next;
             oldt=oldt->next;
        }

        newt=newhead;
        oldt=head;

        while(oldt!=NULL)
        {
             newt->random=mp[oldt->random];
             oldt=oldt->next;
             newt=newt->next;
        }
    
    return newhead;
    }

};
