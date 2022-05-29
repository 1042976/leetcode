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
    // bool isPalindrome(ListNode* head) {
    //     vector<int> arr;
    //     ListNode* cur = head;
    //     while(cur != nullptr){
    //         arr.emplace_back(cur->val);
    //         cur = cur->next;
    //     }
    //     int i = 0, j = arr.size()-1;
    //     while(i < j){
    //         if(arr[i] != arr[j]){
    //             return false;
    //         }
    //         ++i;
    //         --j;
    //     }
    //     return true;
    // }
    
    // ListNode* reverseList(ListNode* head){
    //     ListNode *cur = head, *last = nullptr;
    //     while(cur != nullptr){
    //         ListNode* next = cur->next;
    //         cur->next = last;
    //         last = cur;
    //         cur = next;
    //     }
    //     return last;
    // }
    // //Time O(n), Space O(1)
    // bool isPalindrome(ListNode* head) {
    //     int count = 0;
    //     ListNode* cur = head;
    //     while(cur != nullptr){
    //         ++count;
    //         cur = cur->next;
    //     }
    //     if(count <= 1){
    //         return true;
    //     }
    //     cur = head;
    //     int i = 1;
    //     while(i < count/2){
    //         cur = cur->next;
    //         ++i;
    //     }
    //     ListNode* secondHead = cur->next;
    //     cur->next = nullptr;
    //     secondHead = reverseList(secondHead);
    //     cur = head;
    //     ListNode* secondCur = secondHead;
    //     bool status = true;
    //     ListNode* last = nullptr;
    //     while(cur != nullptr){
    //         last = cur;
    //         if(cur->val != secondCur->val){
    //             status = false;
    //             break;
    //         }else{
    //             cur = cur->next;
    //             secondCur = secondCur->next;
    //         }
    //     }
    //     secondHead = reverseList(secondHead);
    //     last->next = secondHead;
    //     return status;
    // }
    ListNode* reverseList(ListNode* head){
        ListNode *cur = head, *last = nullptr;
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        return last;
    }
    bool compareList(ListNode* head, ListNode* secondHead){
        ListNode *cur = head, *secondCur = secondHead;
        while(secondCur != nullptr){
            if(cur->val != secondCur->val){
                return false;
            }
            cur = cur->next;
            secondCur = secondCur->next;
        }
        return true;
    }
    //Time O(N), Space O(1)
    bool isPalindrome(ListNode* head){
        ListNode *slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHead = slow->next;
        slow->next = nullptr;
        secondHead = reverseList(secondHead);
        bool status = compareList(head, secondHead);
        secondHead = reverseList(secondHead);
        slow->next = secondHead;
        return status;
    }
};
