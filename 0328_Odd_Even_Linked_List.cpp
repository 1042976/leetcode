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
    //Time O(N), Space O(1)
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }else if(head->next == nullptr){
            return head;
        }
        ListNode* head2 = head->next;
        head->next = head2->next;
        ListNode *cur1 = head, *cur2 = head2;
        while(cur1->next != nullptr){
            cur1 = cur1->next;
            cur2->next = cur1->next;
            cur2 = cur2->next;
            if(cur2 == nullptr){
                break;
            }else{
                cur1->next = cur2->next;
            }
        }
        cur1->next = head2;
        return head;
    }
};
