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
        ListNode* prev=nullptr;
        ListNode* cur=head;
        while(cur) {
            ListNode* nextTemp = cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextTemp;
        }

        return prev;
        
    }


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //reverse the list 
        head = reverseList(head);
        //remove the nth item from the beginning
        ListNode *cur,*prev;
        cur=head;
        prev=nullptr;
        
        if(n==1) {
            head = head->next;
        }
        else {
            for(int i=0; i<n-1; i++) {
                prev=cur;
                cur=cur->next;
            }
            prev->next=cur->next;
        }
        
        //reverse the list and return head
        head = reverseList(head);
        return head;
    }
};
