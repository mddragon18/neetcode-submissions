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
        unordered_map<Node*,Node*> links;
        if(!head) return nullptr;
        Node* chead = new Node(head->val);
        Node* temp = chead;
        links[head]=temp;
        Node* cur = head->next;
        
        while(cur) {
            temp->next=(new Node(cur->val));
            temp=temp->next;
            links[cur]=temp;
            cur=cur->next;
        }

        cur = head;
        temp=chead;
        links[nullptr]=nullptr;
        while(cur) {
            temp->random = links[cur->random];
            temp=temp->next;
            cur=cur->next;
        }

        return chead;

    }
};
