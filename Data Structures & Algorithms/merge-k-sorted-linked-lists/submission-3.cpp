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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(!n) return nullptr;

        while(lists.size()>1) {
        vector<ListNode*> mergedLists;
            for(int i=0; i<lists.size(); i+=2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = i+1 < lists.size() ? lists[i+1] : nullptr;
                mergedLists.push_back(mergeList(l1,l2));
            }
            lists=mergedLists;
        }
        return lists[0];
    }
    ListNode* mergeList(ListNode* l1,ListNode* l2) {
        ListNode dummy;
        ListNode* dum = &dummy;

        while(l1 && l2) {
            if(l1->val <= l2->val) {
                dum->next=l1;
                l1=l1->next;
            }
            else {
                dum->next=l2;
                l2=l2->next;
            }
            dum=dum->next;
        }
        dum->next=l1 ? l1 : l2;
        return dummy.next;
    }
};
