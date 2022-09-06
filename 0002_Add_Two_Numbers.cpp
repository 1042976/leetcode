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
    // void update(int &a, int &c){
    //     c = (a >= 10);
    //     a %= 10;
    // }
    // //Time O(M+N), Space O(1), M is the length of l1 while N is the length of l2
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     ListNode *last1 = nullptr;
    //     ListNode *cur1 = l1, *cur2 = l2;
    //     int c = 0;
    //     while(cur1 != nullptr && cur2 != nullptr){
    //         cur1->val += (cur2->val+c);
    //         update(cur1->val, c);
    //         last1 = cur1;
    //         cur1 = cur1->next;
    //         cur2 = cur2->next;
    //     }
    //     if(cur1 == nullptr){
    //         last1->next = cur2;
    //         cur1 = last1->next;
    //     }
    //     while(cur1 != nullptr && c == 1){
    //         cur1->val += c;
    //         update(cur1->val, c);
    //         last1 = cur1;
    //         cur1 = cur1->next;
    //     }
    //     if(c == 1){
    //         ListNode *tail = new ListNode(1);
    //         last1->next = tail;
    //     }
    //     return l1;
    // }
    
    //Time O(max(M,N)), Space O(1), M is the length of l1 while N is the length of l2
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode *head = new ListNode(0), *cur = head;
        int c = 0;
        while(l1 != nullptr || l2 != nullptr || c != 0){
            cur->next = new ListNode(0);
            cur = cur->next;
            int a = l1? l1->val : 0, b = l2? l2->val : 0;
            int sum = a+b+c;
            c = sum/10;
            cur->val = sum%10;
            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;
        }
        ListNode* next = head->next;
        delete(head);
        return next;
    }
};
