/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    //Time O(n), Space O(1)
    Node* insert(Node* head, int insertVal) {
        Node* insertNode = new Node(insertVal);
        if(head == nullptr){
            insertNode->next = insertNode;
            return insertNode;
        }
        Node* cur = head;
        while(cur->next != head){
            bool condition1 = cur->val <= insertVal && cur->next->val >= insertVal;
            bool condition2 = cur->val > cur->next->val && (cur->val < insertVal || insertVal <= cur->next->val);
            if(condition1 || condition2){
                Node* tmp = cur->next;
                cur->next = insertNode;
                insertNode->next = tmp;
                return head;
            }
            cur = cur->next;
        }
        cur->next = insertNode;
        insertNode->next = head;
        return head;
    }
};
