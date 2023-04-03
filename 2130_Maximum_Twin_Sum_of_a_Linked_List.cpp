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
    ListNode* reverse(ListNode* head){
        ListNode *pre = nullptr, *cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    //Time O(N), Space O(1)
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != nullptr){
            fast = fast->next->next;
            if(fast == nullptr){
                break;
            }
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = 0;
        head2 = reverse(head2);
        int maxTwinSum = 2;
        slow = head;
        fast = head2;
        while(slow != nullptr){
            maxTwinSum = max(maxTwinSum, slow->val+fast->val);
            slow = slow->next;
            fast = fast->next;
        }
        return maxTwinSum;
    }
};
