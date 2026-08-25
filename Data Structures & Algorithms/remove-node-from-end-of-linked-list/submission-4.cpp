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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode second1 = ListNode(0,head);
        ListNode* second = &second1;

        while(n) {
            first=first->next;
            n--;
        }
        while(first) {
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        return second1.next;
    }
};
