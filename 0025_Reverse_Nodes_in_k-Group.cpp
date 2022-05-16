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
    //T-O(n), S-O(n/k)
    // ListNode* dfs(ListNode* head, int k){
    //     ListNode* cur = head;
    //     for(int i = 0; i < k; ++i){
    //         if(cur == nullptr){
    //             return head;
    //         }
    //         cur = cur->next;
    //     }
    //     cur = head;
    //     ListNode* last = nullptr;
    //     for(int i = 0; i < k; ++i){
    //         ListNode* next = cur->next;
    //         cur->next = last;
    //         last = cur;
    //         cur = next;
    //     }       
    //     head->next = dfs(cur, k);
    //     return last;
    // }
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     return dfs(head, k);
    // }
    
    //T-O(n), S-O(1)
     ListNode* reverseKNodes(ListNode* &head, ListNode* &lastTail, int k){
         ListNode* cur = head;
         ListNode* last = nullptr;
         for(int i = 0; i < k; ++i){
             ListNode* next = cur->next;
             cur->next = last;
             last = cur;
             cur = next;     
         }
         if(lastTail != nullptr){
            lastTail->next = last;
         }
         lastTail = head;
         head = last;
         return cur;
      }
     ListNode* reverseKGroup(ListNode* head, int k){
        ListNode* lastTail = nullptr;
        ListNode* nextHead = reverseKNodes(head, lastTail, k);
        while(nextHead != nullptr){
            ListNode* cur = nextHead;
            for(int i = 0; i < k; ++i){
                if(cur == nullptr){
                 lastTail->next = nextHead;
                 return head;
                }
                cur = cur->next;
            }
            nextHead = reverseKNodes(nextHead, lastTail, k);
        }
        return head;
     }
};
