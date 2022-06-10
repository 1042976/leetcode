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
//     ListNode* findMid(ListNode* head){
//         ListNode *slow = head, *fast = head->next;
//         while(fast != nullptr && fast->next != nullptr){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }
    
//     ListNode* mergeSortedList(ListNode* head1, ListNode* head2){
//         ListNode* head = new ListNode(0);
//         ListNode* cur = head;
//         ListNode *cur1 = head1, *cur2 = head2;
//         while(cur1 != nullptr && cur2 != nullptr){
//             if(cur1->val < cur2->val){
//                 cur->next = cur1;
//                 cur1 = cur1->next;
//             }else{
//                 cur->next = cur2;
//                 cur2 = cur2->next;
//             }
//             cur = cur->next;
//         }
//         while(cur1 != nullptr){
//             cur->next = cur1;
//             cur1 = cur1->next;
//             cur = cur->next;
//         }
//         while(cur2 != nullptr){
//             cur->next = cur2;
//             cur2 = cur2->next;
//             cur = cur->next;
//         }
//         ListNode* tmp = head;
//         head = head->next;
//         delete tmp;
//         return head;
//     }
//     ListNode* devideAndConquer(ListNode* head){
//         if(head->next == nullptr){
//             return head;
//         }else if(head->next->next == nullptr){
//             ListNode *next = head->next;
//             if(next->val < head->val){
//                 swap(head->val, next->val);
//             }
//             return head;
//         }
//         ListNode* mid = findMid(head);
//         ListNode* head2 = mid->next;
//         mid->next = nullptr;
//         head = devideAndConquer(head);
//         head2 = devideAndConquer(head2);
//         return mergeSortedList(head, head2);
//     }
//     //Time O(NlogN), Space O(logN)
//     ListNode* sortList(ListNode* head) {
//         if(head == nullptr){
//             return nullptr;
//         }
//         return devideAndConquer(head);
//     }
    int numOfMergedList = 0;
    vector<ListNode*> mergeSortedList(ListNode* head1, ListNode* head2){
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        ListNode *cur1 = head1, *cur2 = head2;
        while(cur1 != nullptr && cur2 != nullptr){
            if(cur1->val < cur2->val){
                cur->next = cur1;
                cur1 = cur1->next;
            }else{
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        if(cur1 != nullptr){
            cur->next = cur1;
        }
        if(cur2 != nullptr){
            cur->next = cur2;
        }
        while(cur->next != nullptr){
            cur = cur->next;
        }
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
        return vector<ListNode*>{head, cur};
    }
    ListNode* helper(ListNode* head, int n){
        ListNode *newHead = new ListNode(0), *newTail = newHead;
        numOfMergedList = 0;
        ListNode *list1 = head, *list2 = head;
        ListNode *last2 = nullptr, *last3 = nullptr;
        while(list1 != nullptr && list2 != nullptr){
            ++numOfMergedList;
            for(int i = 0; i < n; ++i){
                last2 = list2;
                list2 = list2->next;
                if(list2 == nullptr){
                    newTail->next = list1;
                    head = newHead->next;
                    delete newHead;
                    return head;
                }
            }
            last2->next = nullptr;
            ListNode* list3 = list2;
            for(int i = 0; i < n && list3 != nullptr; ++i){
                last3 = list3;
                list3 = list3->next;
            }
            if(last3 != nullptr){
                last3->next = nullptr;
            }
            vector<ListNode*> merged = mergeSortedList(list1, list2);
            newTail->next = merged[0];
            newTail = merged[1];
            list1 = list3;
            list2 = list1;
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
    
    //Time O(NlogN), Space O(1)
    ListNode* sortList(ListNode* head){
        int n = 1;
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        while(numOfMergedList != 1){
            head = helper(head, n);
            n <<= 1;
        }
        return head;
    }
};
