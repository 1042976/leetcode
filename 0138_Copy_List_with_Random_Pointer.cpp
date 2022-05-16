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
    //T-O(N), S-O(1)
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        Node* cur = head;
        while(cur != nullptr){
            Node* next = cur->next;
            Node* curCopied = new Node(cur->val);
            cur->next = curCopied;
            curCopied->next = next;
            cur = next;
        }
        cur = head;
        while(cur != nullptr){
            cur->next->random = cur->random? cur->random->next : nullptr;
            cur = cur->next->next;
        }
        Node* headCopied = head->next;
        cur = head;
        while(cur != nullptr){
            Node* tmp = cur->next->next;
            cur->next->next = tmp? tmp->next : nullptr;
            cur->next = tmp;
            cur = cur->next;
        }
        return headCopied;
        
    }
};
