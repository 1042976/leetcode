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
    //Time O(sz), Space O(1)
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode* cur = head;
    //     int sz = 0;
    //     while(cur != nullptr){
    //         ++sz;
    //         cur = cur->next;
    //     }
    //     int m = sz-n;
    //     if(m == 0){
    //         cur = head->next;
    //         head->next = nullptr;
    //         delete head;
    //         return cur;
    //     }
    //     cur = head;
    //     ListNode* last = nullptr;
    //     while(m--){
    //         last = cur;
    //         cur = cur->next;
    //     }
    //     last->next = cur->next;     
    //     cur->next = nullptr;
    //     delete cur;
    //     return head;
    // }
    
    //Time O(sz), Space O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* cur = head;
        while(n--){
            cur = cur->next;
        }
        if(cur == nullptr){
            cur = head->next;
            delete head;
            return cur;
        }
        ListNode* last = head;
        while(cur->next != nullptr){
            cur = cur->next;
            last = last->next;
        }
        cur = last->next;
        last->next = last->next->next;
        delete cur;
        return head;
    }
};
