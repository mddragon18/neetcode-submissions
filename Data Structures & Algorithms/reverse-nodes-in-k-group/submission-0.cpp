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

ListNode* getkth(ListNode* curr, int k) {
    while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
}

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0,head);
        ListNode* groupPrev = &dummy;

        if(!head) return nullptr;
        
        while (true) {
            ListNode* kth = getkth(groupPrev,k);
            if(!kth) break;
            ListNode* groupNext = kth->next;

            ListNode* prev = kth->next;
            ListNode* cur = groupPrev->next;

            while(cur!=groupNext) {
                ListNode* tmp = cur->next;
                cur->next=prev;
                prev=cur;
                cur=tmp;
            }
            ListNode* tmp = groupPrev->next;
            groupPrev->next=kth;
            groupPrev=tmp;
        }

        return dummy.next;
    }
};
