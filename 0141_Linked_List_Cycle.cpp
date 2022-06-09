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
    //Time O(N), Space O(1)
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode *tortoise = head, *hare = head;
        while(hare != nullptr && hare->next != nullptr){
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(tortoise == hare){
                return true;
            }
        }
        return false;
    }
};
