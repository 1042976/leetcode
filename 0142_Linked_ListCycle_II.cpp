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
    // Time O(2a+F), Space O(1). a is the number of nodes before the intersection while F is the number of nodes in the cycle.
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode *fast = head, *slow = head;
        while(fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == nullptr || slow == nullptr){
                break;
            }
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};
