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
    //Time O(nlogn), Space O(logn)
    // ListNode* reverseList(ListNode* head) {
    //     if(head == nullptr || head->next == nullptr){
    //         return head;
    //     }
    //     ListNode *slow = head, *fast = head, *tail = nullptr;
    //     while(fast != nullptr && fast->next != nullptr){
    //         tail = slow;
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     tail->next = nullptr;
    //     head = reverseList(head);
    //     ListNode* head2 = reverseList(slow);
    //     slow->next = head;
    //     return head2;
    // }
    
    //iterative. Time O(N), Space O(1)
    // ListNode* reverseList(ListNode* head){
    //     ListNode *prev = nullptr, *cur = head;
    //     while(cur != nullptr){
    //         ListNode *next = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = next;     
    //     }
    //     return prev;
    // }
    
    //recursive. Time O(N), Space O(N)
    ListNode* reverseList(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
