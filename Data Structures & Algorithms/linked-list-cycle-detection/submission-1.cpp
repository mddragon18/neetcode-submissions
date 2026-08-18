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
        if(head == nullptr || head->next==nullptr) 
            return false;
        ListNode* i=head;
        ListNode* j=head;
        while(i!=nullptr && j!=nullptr && j->next!=nullptr) {
            i=i->next;
            j=j->next->next;

            if(i==j) return true;
        }

        return false;
        
    }
};
