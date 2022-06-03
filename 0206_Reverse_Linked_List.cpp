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
    //Time O(N), Space O(N)
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    
    //Time O(N), Space O(1)
    // ListNode* reverseList(ListNode* head) {
    //     if(head == nullptr){
    //         return nullptr;
    //     }
    //     ListNode *last = nullptr, *cur = head;
    //     while(cur != nullptr){
    //         ListNode* tmp = cur->next;
    //         cur->next = last;
    //         last = cur;
    //         cur = tmp;
    //     }
    //     return last;
    // }
};
