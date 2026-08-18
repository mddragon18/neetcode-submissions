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
        int n=0;
        if (!head) return;
        vector<ListNode*> stack;
        ListNode* cur=head;
        while(cur!=nullptr) {
            n++;
            stack.push_back(cur);
            cur=cur->next;
        }
        cur=head;
        int pairs=n/2;
        for(int i=0;i<pairs;i++) {
            ListNode* temp = stack.back();
            stack.pop_back();
            ListNode* stemp = cur->next;
            cur->next=temp;
            cur->next->next=stemp;
            cur=cur->next->next;
        }
        cur->next=nullptr;
    }
};
