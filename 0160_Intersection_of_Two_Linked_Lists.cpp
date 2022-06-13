/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //Time O(M+N), Space O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        while(curA != curB){
            curA = curA == nullptr? headB : curA->next;
            curB = curB == nullptr? headA : curB->next;
        }
        return curA;
    }
};
